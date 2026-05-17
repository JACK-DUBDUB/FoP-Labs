#include "a2_read.h"
#include <ctype.h>

// ============ READ ============

/*
    My VSCode indicates the fopen func has security vulnerabilities and recommends to use fopen_s instead
        Expected to use: File *stream = fopen(infile, "r");
*/
int read_handleDataIn(const char *infile, Customer *customers, const enum READ_OPTIONS option, int *out_value)
{
    FILE *source_file;
    
    int error_code = fopen_s(&source_file, infile, "r"); //"r", r+" (file must exist)
    if(error_code) 
    {
        printf("Error code: %i \n", error_code);
        printf("PROGRAM ERROR - The file '%s' could not be opened\n", infile);
        return 0;
    }

    switch (option)
    {
        case R_FIRST_LINE: 
            *out_value = read_firstLine(source_file);
            break;
        case R_LINE_COUNT:
            *out_value = read_lineCount(source_file);
            break;
        case R_CUST_DATA:
            *out_value = read_customerData(source_file, customers);
            break;
        default: break;
    }

    fclose(source_file);

    return 1;
}

//  Return the first row value if it's an integer
int read_firstLine(FILE *source_file)
{
    char line_buffer[MAX_BUFFER_LENGTH];
    int lines = -1;
    if(fgets(line_buffer, sizeof(line_buffer), source_file)) 
    {
        if(sscanf_s(line_buffer, "%i", &lines) && lines >= 0) 
        {
            return lines;
        }   
    }
    

    return lines;
}

int read_lineCount(FILE *source_file) 
{
    char line_buffer[MAX_BUFFER_LENGTH];
    int lines = 0; // "There can be 0 and up to 'N' input lines"
    while ((fgets(line_buffer, sizeof(line_buffer), source_file) != NULL)) 
    {
        lines++;
    }
    return lines;
}

// Inserts valid values into the customer array, returns the number of unique customers
int read_customerData(FILE *source_file, Customer *customers)
{
    char line_buffer[MAX_BUFFER_LENGTH];
    int current_row = 0;
    int unique_customers = 0;

    printf("---- Reading Customer Data File ----\n\n");

    while ((fgets(line_buffer, sizeof(line_buffer), source_file) != NULL))
    {
        // Skip first line and other char vals
        if(!current_row || *line_buffer == '/' || *line_buffer == '\n') 
        { 
            current_row++;
            continue;
        }
        current_row++;

        // Temp customer tokens
        char *t_name = NULL;
        char *t_code = NULL;
        char *t_change = NULL;
        
        // We get ze customer tokens
        extract_customerTokens(line_buffer, &t_name, &t_code, &t_change);

        // Find existing customer position
        int t_pos = compare_existingNames(unique_customers, customers, t_name);

        // Filter parsed values
        if(!filter_customerValues(customers[t_pos], t_name, t_change, t_code)) 
        {
            printf("Line: %i -> Rejected entry\n\n", current_row);
            continue;
        }
        
        // Insert successfully parsed customer data, useful function -> atoi(); = ASCII to int
        insert_customerValues(&customers[t_pos], t_name, atoi(t_change), compare_currencyCode(t_code)); 

        if(t_pos == unique_customers) 
        {
            unique_customers++;
        }
    }
    return unique_customers;
}


// Extracts each customer token required for filtering and parsing for each customer field
// Parameter values: buffer = {file line}, t_name = {NULL}, t_code = {NULL}, t_change = {NULL}
void extract_customerTokens(char *buffer, char **t_name, char **t_code, char **t_change)
{
    // string token variables
    const char *delimiter = " ,.\t\n";
    char *token1 = NULL, *token2 = NULL;

    token1 = strtok_s(buffer, delimiter, &token2);

    while(token1)
    {
        if(isalpha(*token1) && !*t_name) // ALWAYS use first string as name IF first leter is alphabetical
        {
            *token1 = toupper(*token1);
            *t_name = token1;
        }
        else if((isdigit(*token1) || *token1 == '-') && !*t_change) // Find a number [+/-] (Required for better feedback) 
        {
            *t_change = token1;
        }
        else if(*token1 == '$' && !*t_code) // Find a dollar sign
        {
            *t_code = token1;
        }
        token1 = strtok_s(NULL, delimiter, &token2);
    }
}

// Find and return name position if it exists, else return the row_count
int compare_existingNames(const int unique_customers, const Customer *customers, const char *token)
{
    int index = unique_customers;
    for (int i = 0; i < unique_customers; i++)
    {
        if (compare_caseInsensitive(customers[i].name, token)) 
        {
            index = i; // Found!
            break;
        }
    }
    return index;
}

// Return the currency code ID
int compare_currencyCode(const char *t_code)
{
    // Where: -1 = INVALID, 0 = $USD, 1 = $AUD, 2 = $EUR
    if (compare_caseInsensitive(t_code, USD_S)) 
    {
        return USD_ID;
    }
    if (compare_caseInsensitive(t_code, AUD_S)) 
    {
        return AUD_ID;
    }
    if (compare_caseInsensitive(t_code, EUR_S)) 
    {
        return EUR_ID;
    }
    return -1;
}

// Customer tokens must go through further filtering
int filter_customerValues(const Customer customer, const char *t_name,  const char *t_change, const char *t_code)
{
    int change = 0;
    int code = compare_currencyCode(t_code);

    if (t_name == NULL) 
    {
        printf("ERROR - Line missing single word string for customer's name \n"); 
        return 0;
    }
    if (t_change == NULL)
    {
        printf("ERROR - Line missing numerical value for change amount\n");
        return 0;
    }
    if (t_code == NULL)
    {
        printf("ERROR - Line missing '$' value for currency code detection\n");
        return 0;
    }
    if (!sscanf_s(t_change, "%i", &change))
    {
        printf("ERROR - Could not parse string '%s' as integer\n", t_change);
        return 0;
    }
    if (change < MIN_CHANGE_LIMIT) 
    {
        printf("ERROR - Change value '%i' less than %i.\n", change, MIN_CHANGE_LIMIT);
        return 0;
    }
    if (change > MAX_CHANGE_LIMIT)
    {
        printf("ERROR - Change value '%i' exceeds %i.\n", change, MAX_CHANGE_LIMIT); 
        return 0;
    }
    if (code < 0)
    {
        printf("ERROR - Unrecognised currency code: %s\n", t_code);
        return 0;
    }
    if ((customer.change_values[code] + change) > MAX_CHANGE_LIMIT) 
    {
        printf("ERROR - %s change value '%i' + '%i' exceeds %i.\n", t_code, customer.change_values[code], change, MAX_CHANGE_LIMIT); 
        return 0;
    }
    return 1;
}

// Pointer passing for a single struct
// Need to use -> to access the specific pointer, OTHERWISE i'll be editing a copy which is not what i want!!!
void insert_customerValues(Customer *customer, const char *name, const int change, const int code)
{
    int _size = strlen(name) + 1;                                        // Make calculation once
    customer->name = (char*) calloc(_size, sizeof(char));        // Allocate memory
    strcpy_s(customer->name, _size, name);  // Copy the string 
    customer->change_values[code] += change;                                // Add the change (from 0 or existing)
    return;
}


