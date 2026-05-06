#include <stdio.h>
#include <string.h>
#include "a2_func.h"
#include "a2_crud.h"


int handle_fileCustomerData(const char *file_name, Customer *customer_data, const char *mode, enum OPTIONS option)
{
    FILE *source_file;
    int error_code = fopen_s(&source_file, file_name, mode);

    if (!!error_code) {
        printf("Error code: %i \n", error_code);
        return -1;
    }

    switch (option) {
        case READ_ROWS: return read_customerRowsNumber(source_file), fclose(source_file);;
        case READ_DATA: read_customerData(source_file, customer_data); break;
        default: break;
    }

    fclose(source_file);

    return 1;
}

int read_customerRowsNumber(FILE *source_file)
{
    char line_buffer[512];
    int table_rows = 0;

    if(fgets(line_buffer, 512, source_file)){
        sscanf_s(line_buffer, "%i", &table_rows);
        return table_rows;
    }

    return 0;
}

void read_customerData(FILE *source_file, Customer *customer_data)
{
    char line_buffer[512];
    int data_row = 0;

    while (fgets(line_buffer, 512, source_file) != NULL)
    {
        // Aggregate/concatenate the strings maybe???
        // https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l?view=msvc-170
        // 
        int spaces_count = read_spacesCount(line_buffer);
        if (!spaces_count)
            continue;

        char rregex[] = " \n";
        char *token = NULL;
        char *next_token = NULL;

        // Shift to first string 
        token = strtok_s(line_buffer, rregex, &next_token);

        int temp_position = compare_existingNames(data_row, customer_data, token);

        if(temp_position == data_row) {
            int name_size = strlen(token) + 1;

            customer_data[temp_position].name = (char*) calloc(name_size, sizeof(char));

            strcpy_s(customer_data[temp_position].name, name_size, token);
        }

        // Shift to next string
        token = strtok_s(NULL, rregex, &next_token);

        // Get change
        int temp_change = 0;
        sscanf_s(token, "%i", &temp_change);

        while (token != NULL)
        {
            switch(compare_currencyTypes(token))
            {
                case CURRENCY_USD: customer_data[temp_position].change_usd += temp_change; break;
                case CURRENCY_AUD: customer_data[temp_position].change_aud += temp_change; break;
                case CURRENCY_EUR: customer_data[temp_position].change_eur += temp_change; break;
                default: break;
            }

            token = strtok_s(NULL, rregex, &next_token);
        }

        data_row++;
    }

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


int compare_existingNames(int line_count, Customer *customer_data, const char *_name)
{
    for (int i = 0; i < line_count; i++)
    {
        if (!strcmp(customer_data[i].name, _name)) {
            return i;
        }
    }
    return line_count;
}

int compare_currencyTypes(const char *_token)
{
    if (strcmp(_token, "$USD") == 0)
        return CURRENCY_USD;

    if (strcmp(_token, "$AUD") == 0)
        return CURRENCY_AUD;

    if (strcmp(_token, "$EUR") == 0)
        return CURRENCY_EUR;

    return 0;
}