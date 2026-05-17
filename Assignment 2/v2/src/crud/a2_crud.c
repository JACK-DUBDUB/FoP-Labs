#include "a2_crud.h"
#include "../currency/a2_currency.h"
#include "../program/a2_program.h"


// -------- READ FROM FILE ----------------------------------------------------------------------------------------------------

int file_readFirstLine(const char *infile, int *first_value)
{
    printf("\nAttempting to read first line value of: %s\n\n", infile);

    FILE *f_stream = fopen(infile, "r");
    char buffer[READ_FILE_BUFFER_LIMIT];

    if (f_stream == NULL) 
    {
        printf("-> PROGRAM ERROR - The file '%s' could not be opened\n\n", infile);
        return 1;
    }

    if (fgets(buffer, sizeof(buffer), f_stream) != NULL)
    {
        sscanf(buffer, "%i", first_value);
    }
    else 
    {
        printf("-> PROGRAM ERROR - The file '%s' is empty\n\n", infile);
        return 1;
    }

    fclose(f_stream);
    
    if (*first_value < 0)
    {
        printf("-> PROGRAM ERROR - Value parsed was a negative number\n\n");
        return 1;
    }

    printf("-> Successfully read first line value '%i' of file '%s' \n\n",* first_value, infile);

    return 0;
}

// -------- READ CUSTOMER VALUES FROM FILE ------------------------------------------------------------------------------------

int file_readCustomerData(CustomerArray *customers, const CurrencyArray *currencies, const char *infile)
{
    printf("\n\nAttempting to read customer values from file: %s\n\n", infile);

    FILE *f_stream = fopen(infile, "r");
    if (f_stream == NULL) 
    {
        printf("-> PROGRAM ERROR - The file '%s' could not be opened\n\n", infile);
        return 1;
    }
    
    char buffer[READ_FILE_BUFFER_LIMIT];
    int line_count = 0;

    while (fgets(buffer, sizeof(buffer), f_stream) && customers->max > 0) 
    {
        // Skip these lines if they exist
        if(!line_count || *buffer == '/' || *buffer == '\n') 
        {   line_count++;
            continue;
        }

        line_count++;

        if (process_customerLine(customers, currencies, buffer, line_count))
        {
            printf("Reached maximum number of %i customers!\n", customers->count);
            printf("Closing file... \n\n");
            break;
        }
    }

    fclose(f_stream);

    printf("-> Successfully read '%i' unique customer values from file '%s' \n\n", customers->count, infile);
    
    return 0;
}

int process_customerLine(CustomerArray *customers, const CurrencyArray *currencies, char *buffer, const int line_count)
{
    char *t_name = NULL;
    char *t_change = NULL;
    char *t_code = NULL;
    
    // Find the correct token values
    extract_customerTokens(currencies, buffer, &t_name, &t_change, &t_code);

    // Find existing customer position
    int t_pos = compare_existingNames(*customers, t_name);
    int code = compare_currencyCode(currencies, t_code);

    // Extremely dangerous without memory reallocation -> i'm not paid enough to deal with that!
    if(t_pos >= customers->max)
    {
        return 1;
    }

    // Filter token values
    if(filter_customerTokens(t_name, t_change, t_code)) 
    {
        printf("Line: %i -> Rejected entry\n\n", line_count);
        return 0; 
    }

    // Insert successfully parsed customer data, useful function -> atoi(); = ASCII to int
    insert_customerValues(&customers->data[t_pos], t_name, atoi(t_change), code);

    // Increment the known customer count if its unique
    if(customers->count == t_pos)
    {
        customers->count++;
    }
        
    return 0;
}



void extract_customerTokens(const CurrencyArray *currencies, char *buffer, char **t_name, char **t_change, char **t_code)
{
    // string token variables
    const char *delimiter = " ,.\t\n";
    char *token = NULL;

    token = strtok(buffer, delimiter);

    while(token)
    {
        if(isalpha(*token) && !*t_name) // ALWAYS use first string as name if
        {
            *token = toupper(*token);
            *t_name = token;
        }
        else if((isdigit(*token) || *token == '-') && !*t_change) // Find a number [+/-] - useful for filtering later
        {
            *t_change = token;
        }
        else if(compare_currencyCode(currencies, token) >= 0 && !*t_code) // Compare token with currency
        {
            *t_code = token;
        }
        token = strtok(NULL, delimiter);
    }
}


int filter_customerTokens(const char *t_name,  const char *t_change, const char *t_code)
{
    int change = 0;

    if (t_name == NULL) 
    {
        printf("ERROR - Line missing single word string for customer's name \n"); 
        return 1;
    }
    if (t_change == NULL)
    {
        printf("ERROR - Line missing numerical value for change amount\n");
        return 1;
    }
    if (t_code == NULL)
    {
        printf("ERROR - Line missing known currency type\n");
        return 1;
    }
    if (!sscanf_s(t_change, "%i", &change))
    {
        printf("ERROR - Could not parse string '%s' as integer\n", t_change);
        return 1;
    }
    if (change < MIN_CHANGE_LIMIT)
    {
        printf("ERROR - Change value '%i' less than %i.\n", change, MIN_CHANGE_LIMIT);
        return 1;
    }    
    if (change > MAX_CHANGE_LIMIT)
    {
        printf("ERROR - Change value '%i' exceeds %i.\n", change, MAX_CHANGE_LIMIT); 
        return 1;
    }
    return 0;
}

void insert_customerValues(Customer *customer, const char *name, const int change, const int code)
{
    int size = strlen(name) + 1; // null term
    customer->name = calloc(size, sizeof(char));        
    strcpy(customer->name, name);
    customer->values[code] += change;                                      
    return;
}


// -------- WRITE TO FILE -----------------------------------------------------------------------------------------------------

int file_write(const CustomerArray customers, const CurrencyArray currencies, const char *outfile)
{
    printf("\n\nAttempting to write to file: %s\n\n", outfile);

    FILE *f_stream = fopen(outfile, "w");
    if (f_stream == NULL) 
    {
        printf("\nPROGRAM ERROR - Failed to create file '%s' in 'w' mode. \nFile may still be open and/or missing permissions.\n\n", outfile);
        return 1;
    }

    file_writeCustomerData(f_stream, customers, currencies);

    fclose(f_stream);

    printf("-> Successfully customer values to file: '%s' \n\n", outfile);
    return 0;
}


void file_writeCustomerData(FILE *f_stream, const CustomerArray customers, const CurrencyArray currencies)
{
    for (int i = 0; i < customers.max; i++)
    {
        if (customers.data[i].name == NULL)
        {
            continue;
        }

        for (int j = 0; j < currencies.max; j++)
        {
            if (!customers.data[i].values[j])
            {
                continue;
            }

            fprintf(f_stream, "%s, the change for %i cents in %s is ", customers.data[i].name, customers.data[i].values[j], currencies.data[j].code);

            for (int k = 0; k < currencies.data[j].count; k++)
            {
                if(k + 1 != currencies.data[j].count )
                {
                    fprintf(f_stream, "%i,", customers.data[i].coins[j][k]);
                }
                else
                {
                    fprintf(f_stream, "%i\n", customers.data[i].coins[j][k]);
                }
            }
        }
    }
    return;
}