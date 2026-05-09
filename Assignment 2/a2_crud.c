#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "a2_crud.h"


int handle_fileCustomerData(const char *file_name, Customer *customer_data, const char *mode, const enum OPTIONS option, int *table_rows)
{
    FILE *source_file;
    int error_code = fopen_s(&source_file, file_name, mode);

    if (!!error_code) {
        printf("Error code: %i \n", error_code);
        return -1;
    }

    switch (option) {
        case READ_ROWS: *table_rows = read_customerRowsNumber(source_file); break; // Returns expected number of entries only
        case READ_DATA: read_customerData(source_file, customer_data); break; // Inserts valid customer values into the customer_data array
        case CREATE_CSV: create_customerDataCSV(source_file, customer_data, table_rows); break; // Creates the .csv file containing valid customer data
        default: break;
    }

    fclose(source_file);
    return 1;
}

// ---- READ ----

int read_customerRowsNumber(FILE *source_file)
{
    char line_buffer[512];
    int rows = 0;

    if(fgets(line_buffer, 512, source_file)) 
    {
        if(sscanf_s(line_buffer, "%i", &rows)) 
        {
            return rows;
        }
    }
    return 0;
}

void read_customerData(FILE *source_file, Customer *customer_data)
{
    char line_buffer[512];
    int data_row_count = 0;

    while (fgets(line_buffer, 512, source_file) != NULL)
    {
        // Skip the garbage information in the text file
        // https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l?view=msvc-170
        // Frankensteined -> will refactor/simplify later

        int spaces_count = read_spacesCount(line_buffer);
        if (!spaces_count)
            continue;

        // Customer variables
        char *_name = NULL;
        int _pos = 0, _change = 0, _code = 0; 

        // strtok variables
        const char *delimiter = " ,\t\n";
        char *token = NULL, *next_token = NULL;



        // Shift to first string 
        shift_NextToken(&token, line_buffer, delimiter, &next_token);


        // ==== NAME ====
        // Find the name position if it already exists
        _pos = compare_existingNames(data_row_count, customer_data, token);
        _name = token;

        // Shift to next string
        shift_NextToken(&token, NULL, delimiter, &next_token);
        

        // ==== CHANGE ====
        // Get valid change value
        if (!sscanf_s(token, "%i", &_change)) {
            printf("ERROR - Could not read change value.\n");
            printf("Going to next line...\n");
            continue;
        }

        // ==== CURRENCY CODE ==== 
        // Where: -1 = INVALID, 0 = $USD, 1 = $AUD, 2 = $EUR
        while(*token)
        {
            if (*token == '$') { 
                _code = compare_currencyTypes(token); 
                break;
            }

            shift_NextToken(&token, NULL, delimiter, &next_token);
        }

        // Filter
        if (_code < 0) {
            printf("ERROR - Could not read currency code | may be undefined currency: %s \n", token);
            printf("Going to next line...\n");
            continue;
        }


        // Finally enter values

        // If the name does not currently exist
        if(_pos == data_row_count) {

            int _size = strlen(_name) + 1; // Need Null term

            customer_data[_pos].name = (char*) calloc(_size, sizeof(char));

            strcpy_s(customer_data[_pos].name, _size, _name);

            data_row_count++;
        }

        customer_data[_pos].change_values[_code] += _change;

        // printf("position: %i, name %s, change %i, code %i \n", _pos, customer_data[_pos].name, /*customer_data[_pos].change_values[_code]*/ _change, _code);
    }

    return;
}

void shift_NextToken(char **token, char *_string, const char *delimiter, char **_next_token)
{
    *token = strtok_s(_string, delimiter, _next_token);
    return;
}

int read_spacesCount(const char *line_buffer)
{
    int count = 0;
    const char *string_ptr1 = line_buffer;

    while(*string_ptr1)
    {
        if(*string_ptr1 == ' ')
            count++;
        string_ptr1++;
    }

    return count;
}


// Find and return name position if it exists, else return the row_count
int compare_existingNames(const int data_row_count, const Customer *customer_data, const char *_name)
{
    for (int i = 0; i < data_row_count; i++)
    {
        if (compare_nameCaseInsensitive(customer_data[i].name, _name))
            return i;
    }
    return data_row_count;
}


// Assumption -> what if names are same but not same case
bool compare_nameCaseInsensitive(const char *ptr_exist, const char *ptr_compr)
{
    // Sigh...
    if (ptr_exist == NULL || ptr_compr == NULL)
        return false;

    // Compare length first before checking
    if (strlen(ptr_exist) != strlen(ptr_compr))
        return false;

    // If the same length then check 
    while (*ptr_exist && *ptr_compr)
    {
        if (tolower(*ptr_exist) != tolower(*ptr_compr))
            return false;
            
        ptr_exist++, ptr_compr++;
    }

    return true;
}

int compare_currencyTypes(const char *_token)
{
    if (strcmp(_token, "$USD") == 0)
        return CURRENCY_USD;

    if (strcmp(_token, "$AUD") == 0)
        return CURRENCY_AUD;

    if (strcmp(_token, "$EUR") == 0)
        return CURRENCY_EUR;

    return -1;
}



// ---- CREATE ----

void create_customerDataCSV(FILE *output_file, const Customer *customer_data, const int *table_rows)
{
    for (int i = 0; i < *table_rows; i++)
    {
        if(customer_data[i].change_values[CURRENCY_USD])
            write_customerData(output_file, customer_data[i].name, customer_data[i].change_values[CURRENCY_USD], "$USD", customer_data[i].coins_usd);

        if(customer_data[i].change_values[CURRENCY_AUD])
            write_customerData(output_file, customer_data[i].name, customer_data[i].change_values[CURRENCY_AUD], "$AUD", customer_data[i].coins_aud);

        if(customer_data[i].change_values[CURRENCY_EUR])
            write_customerData(output_file, customer_data[i].name, customer_data[i].change_values[CURRENCY_EUR], "$EUR", customer_data[i].coins_eur);
    }

    return;
}

void write_customerData(FILE *output_file, const char *customer_name, const int change, const char *currency, const int coin_variants[])
{   
    fprintf(output_file, "%s, the change for %i cents in %s is ", customer_name, change, currency);
    fprintf(output_file, "%i,%i,%i,%i\n",coin_variants[0], coin_variants[1], coin_variants[2], coin_variants[3]);
    return;
}