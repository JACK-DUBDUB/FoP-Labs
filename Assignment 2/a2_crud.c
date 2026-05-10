#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "a2_crud.h"
#include "a2_general.h"

// ============ CREATE ============

int handle_createCustomerDataCSV(const Customer *customer_data, const Currency *currencies, const char *file_name, const int table_rows)
{
    FILE *output_file;
    int out_value = 0, error_code = 0;

    error_code = fopen_s(&output_file, file_name, "w");

    if (!!error_code) {
        printf("Error code: %i \n", error_code);
        return -1;
    }

    out_value = create_customerDataCSV(output_file, customer_data, currencies, table_rows);

    fclose(output_file);

    return out_value;
}


int create_customerDataCSV(FILE *output_file, const Customer *customer_data, const Currency *currencies, const int table_rows)
{
    int rows_printed = 0;
    for (int i = 0; i < table_rows; i++)
    {
        if (customer_data[i].name == NULL)
            break;

        for (int j = 0; j < MAX_CURRENCY_TYPES; j++)
        {
            if (customer_data[i].change_values[j]) {
                fprintf(output_file, "%s, the change for %i cents in %s is ", customer_data[i].name, customer_data[i].change_values[j], currencies[j].code);
                fprintf(output_file, "%i,%i,%i,%i\n", customer_data[i].coins_ptr[j][0], customer_data[i].coins_ptr[j][1], customer_data[i].coins_ptr[j][2], customer_data[i].coins_ptr[j][3]);
                rows_printed++;
            }
        }
    }
    return rows_printed;
}


// ============ READ ============


int handle_readFileCustomerData(const char *file_name, Customer *customer_data, const enum READ_OPTIONS option)
{
    FILE *source_file;
    int out_value = 0, error_code = 0;

    error_code = fopen_s(&source_file, file_name, "r");
    if (!!error_code) {
        printf("Error code: %i \n", error_code);
        return -1;
    }

    if (option == FILE_READ_ROW)
        out_value = read_firstRowEntry(source_file);

    if (option == FILE_READ_DATA)
        out_value = read_customerData(source_file, customer_data);

    fclose(source_file);
    return out_value;
}



//  Return the first row value if it's an integer
int read_firstRowEntry(FILE *source_file)
{
    char line_buffer[MAX_BUFFER_LENGTH];
    int rows = 0;

    if(fgets(line_buffer, MAX_BUFFER_LENGTH, source_file))
        if(sscanf_s(line_buffer, "%i", &rows))
            return rows;
    
    return 0;
}

// Inserts valid values into the customer array, returns the number of unique customers
int read_customerData(FILE *source_file, Customer *customer_data)
{
    char line_buffer[MAX_BUFFER_LENGTH];
    int file_line_c = 0;
    int unique_customer_c = 0;

    while (fgets(line_buffer, MAX_BUFFER_LENGTH, source_file) != NULL)
    {
        if (!file_line_c) { // Skip first line
            file_line_c++;
            continue;
        }
        
        file_line_c++;

        // Customer variables
        char *_name = NULL;
        int _pos = 0, _change = -1, _code = -1; 

        // strtok variables
        const char *delimiter = " ,\t\n";
        char *token = NULL, *next_token = NULL;

        // Shift to first string 
        shift_toNextToken(&token, line_buffer, delimiter, &next_token);

        // ---- NAME ----
        // Find the name position if it already exists
        _pos = compare_existingNames(unique_customer_c, customer_data, token);
        _name = token;

        // Shift to next string
        shift_toNextToken(&token, NULL, delimiter, &next_token);
        
        // ---- CHANGE ----
        // Get valid change value
        if (!sscanf_s(token, "%i", &_change)) {
            printf("ERROR - Could not read change value.\n");
            printf("Line: %i\n", file_line_c);
            continue;
        }

        // ---- CURRENCY CODE ---- 
        // Where: -1 = INVALID, 0 = $USD, 1 = $AUD, 2 = $EUR
        while(*token)
        {
            if (*token == '$') { 
                _code = compare_currencyCode(token); 
                break;
            }

            shift_toNextToken(&token, NULL, delimiter, &next_token);
        }

        // Filter all values
        if(!filter_customerErrorLine(file_line_c, _change, _code, customer_data[_pos].change_values[_code])) {
            printf("Line: %i\n\n", file_line_c);
            continue;
        }
            
        // Finally enter values
        // If the name does not currently exist
        if(_pos == unique_customer_c) {

            int _size = strlen(_name) + 1; // Need Null term

            customer_data[_pos].name = (char*) calloc(_size, sizeof(char));

            customer_data[_pos].name = _name;
            printf("Name: %s\n", customer_data[_pos].name);

            //strcpy_s(customer_data[_pos].name, _size, _name);

            unique_customer_c++;
        }

        customer_data[_pos].change_values[_code] += _change;
    }

    if (!unique_customer_c)
        return 0;


    return unique_customer_c - 1;
}

// 
void shift_toNextToken(char **token, char *_string, const char *delimiter, char **_next_token)
{
    *token = strtok_s(_string, delimiter, _next_token);
    return;
}


// Filter known read file errors...
bool filter_customerErrorLine(const int line_count, const int _change, const int _code, const int customer_change)
{
    if (_change <= MIN_CHANGE_LIMIT) {
        printf("ERROR - Change value is less than or equal to: %i.\n", MIN_CHANGE_LIMIT); 
        return false;
    }

    if (_change > 95) {
        printf("ERROR - Change value is more than %i.\n", MAX_CHANGE_LIMIT); 
        return false;
    }

    if (_code < 0) { // -1 = error
        printf("ERROR - Unrecognised currency code\n"); 
        return false;
    }

    if (customer_change + _change > MAX_CHANGE_LIMIT) {
        printf("ERROR - Change value '%i' + '%i' exceeds %i.\n", customer_change, _change, MAX_CHANGE_LIMIT); 
        return false;
    }

    if (_code == AUD_ID && (customer_change + _change) < AUD_ID) {
        printf("ERROR - Change value '%i' + '%i' below %i.\n", customer_change, _change, MIN_AUD_LIMIT); 
        return false;
    }

    return true;
}




int compare_currencyCode(const char *_code)
{
    if (compare_caseInsensitive(_code, USD_S))
        return USD_ID;
    if (compare_caseInsensitive(_code, AUD_S))
        return AUD_ID;
    if (compare_caseInsensitive(_code, EUR_S))
        return EUR_ID;
    return -1;
}

// Find and return name position if it exists, else return the row_count
int compare_existingNames(const int unique_customer_c, const Customer *customer_data, const char *_name)
{
    for (int i = 0; i < unique_customer_c; i++)
    {
        if (compare_caseInsensitive(customer_data[i].name, _name))
            return i;
    }
    return unique_customer_c;
}

