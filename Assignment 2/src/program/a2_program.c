#include "../../include/a2_includes.h"


// -------- CHECK ARGUMENTS ---------------------------------------------------------------------------------------------------

int program_checkArgs(int argument_count, char *argument_values[])
{
    if (argument_count == 3 && strcmp(argument_values[1], argument_values[2]) == 0)
    {
        printf("\nInput file should not be the same as the output file!\n");
        return 1;
    }

    if (argument_count == 1)
    {
        printf("\nMissing {Input File} AND {Output File} -> Using defaults\n");
        argument_values[1] = DEFAULT_IN_FILE;
        argument_values[2] = DEFAULT_OUT_FILE;
        return 0;
    }
    if (argument_count == 2)
    {
        printf("\nMissing {Output File} -> Using default\n");
        argument_values[2] = DEFAULT_OUT_FILE;;
        return 0;
    }

    if (argument_count > 3)
    {
        printf("\nIncluded too many args -> Using first two provided\n");
    }

    return 0;
}

// -------- COMPARE TO --------------------------------------------------------------------------------------------------------

int compare_currencyCode(const CurrencyArray *currencies, const char *t_code)
{
    // Where: -1 = INVALID, 0 = $USD, 1 = $AUD, 2 = $EUR
    int found = -1;
    for (int i = 0; i < currencies->max; i++)
    {
        if (compare_caseInsensitive(currencies->data[i].code, t_code) == 0)
        {
            found = i;
            break;
        }
    }
    return found;
}

// Find and return name position if it exists
int compare_existingNames(const CustomerArray customers, const char *t_name)
{
    for (int i = 0; i < customers.count ; i++)
    {
        if (compare_caseInsensitive(customers.data[i].name, t_name) == 0) 
        {
            return i;
        }
    }
    return customers.count;
}

int compare_caseInsensitive(const char *string1, const char *string2)
{
    if ((string1 == NULL || string2 == NULL)) 
    {
         return 1;
    }

    if(strlen(string1) != strlen(string2))
    {
        return 1;
    }

    while (*string1 && *string2)
    {
        if (toupper(*string1) != toupper(*string2)) 
        {
             return 1;
        }
        string1++, string2++;
    }
    return 0;
}

// -------- SEARCH MENU HANDLER -----------------------------------------------------------------------------------------------

void program_handleSearchMenu(const CustomerArray customers, const CurrencyArray currencies)
{
    enum MENU_OPTIONS   {PROGRAM_SEARCH = 1, PROGRAM_QUIT = 2};
    int selection;
    do 
    {
        program_pause(MSG_CONTINUE); // Pause to show filtered 

        customer_displayNames(customers);

        printf("\n-------- MENU --------\n");
        printf("[1] - Enter name\n");
        printf("[2] - Quit program\n\n");

        selection = read_intInRange(PROGRAM_SEARCH, PROGRAM_QUIT);

        switch (selection) 
        {
            case PROGRAM_SEARCH:
                printf("\n---- Customer Name Search ----\n");
                printf("\nPlease enter a name: ");
                customer_nameSearch(customers, currencies);
                break;
            case PROGRAM_QUIT:
                break;
        }
    } while(selection != PROGRAM_QUIT);
    return;
}

// -------- READ VALUE FROM STDIN ---------------------------------------------------------------------------------------------

int read_intInRange(const int min, const int max)
{
    int int_value;
    do 
    {
        printf("Please enter an integer value: ");
        if (scanf("%i", &int_value) && getchar() == '\n')
        {   
            if (int_value >= min && int_value <= max)
            {
                 return int_value;
            }
            printf("User entered an integer out of range (%i - %i)!\n",min, max);
        }
        program_clearInputBuffer();
        printf("Please enter a valid value!!!\n\n");
    }while (1);
    return int_value;
}

void read_string(char *buffer, const int size)
{
    if (size <= 0)
    {
        return;
    }

    // Empty string check
    if (fgets(buffer, size, stdin) == NULL) 
    { 
        buffer[0] = '\0'; // Cut it short
    }

    int length = strlen(buffer);

    // If the chars inserted don't reach buffer limit
    if(length < size && buffer[length - 1] == '\n') 
    {
        buffer[length - 1] = '\0'; // Replace '\n'
    } 
    else 
    {  // Exceeded buffer limit (probably)
        program_clearInputBuffer();
    }
    return;
}

// -------- PROGRAM HELPERS ---------------------------------------------------------------------------------------------------

void program_clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return;
}

void program_pause(const enum PROGRAM_PAUSE msg)
{
    switch (msg) 
    {
        case MSG_CONTINUE:
            printf("\nPress enter to continue program...");
            break; 
        case MSG_QUIT: 
            printf("\nPress enter to quit program..."); 
            break;
    }
    getchar();
    printf("\n");
    return;
}






