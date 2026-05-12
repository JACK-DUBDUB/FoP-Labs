#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "a2_read.h"
#include "../general/a2_general.h"



// ============ READ ============

int read_handleCustomerDataIn(const char *file_name, Customer *customer_data, const enum READ_OPTIONS option)
{
    FILE *source_file;
    int error_code = fopen_s(&source_file, file_name, "r");

    if (!!error_code) {
        printf("Error code: %i \n", error_code);
        return -1;
    }

    int out_value = 0;
    switch (option)
    {
        case R_FIRST_ROW: 
            out_value = read_expectedLines(source_file);
            break;
        case R_LINE_COUNT:
            out_value = read_lineCount(source_file);
            break;
        case R_CUST_DATA:
            out_value = read_customerData(source_file, customer_data);
            break;
        default: break;
    }

    fclose(source_file);
    return out_value;
}

//  Return the first row value if it's an integer
int read_expectedLines(FILE *source_file)
{
    char line_buffer[MAX_BUFFER_LENGTH];
    int lines = 0;

    if(fgets(line_buffer, MAX_BUFFER_LENGTH, source_file)) {
        if(sscanf_s(line_buffer, "%i", &lines) && lines > 0) {
            return lines;
        }   
    }
    return 0;
}

int read_lineCount(FILE *source_file) 
{
    char line_buffer[MAX_BUFFER_LENGTH];
    int lines = -1; // "There can be 0 and up to 'N' input lines"
    while ((fgets(line_buffer, MAX_BUFFER_LENGTH, source_file) != NULL)) {
        lines++;
    }
    return lines;
}

// Inserts valid values into the customer array, returns the number of unique customers
int read_customerData(FILE *source_file, Customer *customer_data)
{
    char line_buffer[MAX_BUFFER_LENGTH];
    int current_row = 0;
    int unique_customers = 0;

    while ((fgets(line_buffer, MAX_BUFFER_LENGTH, source_file) != NULL))
    {
        if(!current_row) {
            current_row++;
            continue;
        }

        // Increment for each line read
        current_row++;

        char *_name = NULL;
        int _pos = 0, _change = -1, _code = -1;
        
        // Parse values, returns last token used
        char *current_token = parse_customerLine(line_buffer, customer_data, unique_customers, &_name, &_pos, &_change, &_code);

        // Filter parsed values
        if(!filter_customerValues(current_token, _name,customer_data[_pos].change_values[_code] ,_change, _code)) {
            printf("Line: %i\n", current_row);
            printf("Rejected entry\n\n");
            continue;
        }
        
        // Insert successfully parsed customer data
        insert_customerValues(&customer_data[_pos], _name, _change, _code);
        if(_pos == unique_customers) {
            unique_customers++;
        }
    }
    return unique_customers;
}


// Default values: name = null, pos = 0, change = -1, code = -1
char* parse_customerLine(char *buffer, const Customer *customers, const int uniq_cust, char **name, int *pos, int *change, int *code)
{
    enum steps {READ_NAME, READ_CHANGE, READ_CODE};
    int current_step = READ_NAME;

    // strtok variables
    const char *delimiter = " ,\t\n";
    char *token = NULL, *next_token = NULL;
    
    // Get first token (string) 
    token = strtok_s(buffer, delimiter, &next_token);

    // Parse values while token not null
    while(token)
    {
        switch (current_step) 
        {
            case READ_NAME:
                *pos = compare_existingNames(uniq_cust, customers, token);
                *name = token;
                current_step++;
                break;

            case READ_CHANGE:
                if(!sscanf_s(token, "%i", change)) {// Parse string as int once
                    return token;
                }
                if (*change < MIN_CHANGE_LIMIT) {
                    *change = 0;
                    return token;
                }
                current_step++;
                break;

            case READ_CODE:
                if(*token == '$') {
                    *code = compare_currencyCode(token); // Returns: -1 (error), 0, 1, 2 (currency IDs) 
                    return token;
                }
        }
        token = strtok_s(NULL, delimiter, &next_token);
    }
    return token;
}

// Find and return name position if it exists, else return the row_count
int compare_existingNames(const int uniq_cust, const Customer *customers, const char *token)
{
    for (int i = 0; i < uniq_cust; i++)
    {
        if (compare_caseInsensitive(customers[i].name, token)) {
            return i; // Found!
        }
    }
    return uniq_cust;
}

// 
int compare_currencyCode(const char *code)
{
    // Where: -1 = INVALID, 0 = $USD, 1 = $AUD, 2 = $EUR
    if (compare_caseInsensitive(code, USD_S)) {
        return USD_ID;
    }
    if (compare_caseInsensitive(code, AUD_S)) {
        return AUD_ID;
    }
    if (compare_caseInsensitive(code, EUR_S)) {
        return EUR_ID;
    }   
    return -1;
}

// Parsed data must go through further filtering
bool filter_customerValues(const char *token, const char *name, const int cust_change, const int change, const int code)
{
    if (name == NULL) {
        printf("ERROR - Line missing single word string for name \n"); 
        return false;
    }
    if (change == -1) { // -1 = error
        printf("ERROR - Could not parse string '%s' as integer\n",token);
        return false;
    }
    if (change < MIN_CHANGE_LIMIT) {
        printf("ERROR - Change value is less than %i.\n", MIN_CHANGE_LIMIT);
        return false;
    }
    if (code < 0) { // -1 = error
        printf("ERROR - Unrecognised currency code: %s\n", token);
        return false;
    }
    if (change > MAX_CHANGE_LIMIT) {
        printf("ERROR - Change value '%i' exceeds %i.\n",  change, MAX_CHANGE_LIMIT); 
        return false;
    }
    if (cust_change + change > MAX_CHANGE_LIMIT) {
        printf("ERROR - Change value '%i' + '%i' exceeds %i.\n", cust_change, change, MAX_CHANGE_LIMIT); 
        return false;
    }
    return true;
}

// *** Tricky!!! ***
// Pointer passing for a single struct
// Need to use -> to access the specific pointer otherwise i'll be editing a copy which is not what i want
void insert_customerValues(Customer *customer, const char *name, const int change, const int code)
{
    int _size = strlen(name) + 1;                                        // Make calculation once
    customer->name = (char*) calloc(_size, sizeof(char));        // Allocate memory
    strcpy_s(customer->name, _size, name);  // Copy the string 
    customer->change_values[code] += change;                                // Add the change (from 0 or existing)
    return;
}


