
#include "../program/a2_program.h"

void customer_initPointers(Customer *customers, const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        customers[i].coins_ptr[USD_ID] = customers[i].coins_usd;
        customers[i].coins_ptr[AUD_ID] = customers[i].coins_aud;
        customers[i].coins_ptr[EUR_ID] = customers[i].coins_eur;
    }
    return;
}

void customer_filterData(Customer *customers, const int rows)
{
    printf("---- Filtering Customer Values ----\n\n");
    int customers_removed = 0;
    for (int i = 0; i < rows; i++)
    {
        // Invalidate AUD change value indivisible by 5
        if (customers[i].change_values[AUD_ID] % MIN_AUD_LIMIT) 
        {
            printf("Customer: %s\n", customers[i].name);
            printf("Invalid AUD value: %i is not divisible by %i\n\n",customers[i].change_values[AUD_ID], MIN_AUD_LIMIT);
            customers[i].change_values[AUD_ID] = 0;
        }

        // If customer has any change -> go to next customer 
        if (customers[i].change_values[USD_ID] || customers[i].change_values[AUD_ID] || customers[i].change_values[EUR_ID]) 
        {
            continue;
        }

        // Customer has no change values -> set name to NULL, thus invalidating the customer
        if(customers[i].name != NULL) 
        {
            printf("REMOVED CUSTOMER: %s\n", customers[i].name);
            printf("Reason: No valid change values\n\n");
            customers[i].name = NULL;
            customers_removed++;
        }
    }

    // Feedback 
    if (customers_removed) 
    {
        printf("Total customers removed: %i\n\n", customers_removed);
    }
    else 
    {
        printf("All customers valid \n\n");
    }
}

int customer_sortNull(Customer *customers, const int rows)
{
    int customer_count = 0;

    // Swap invalid customers (left), with valid customers (right)
    for (int i = 0; i < rows; i++) 
    {  
        if(customers[i].name != NULL)
        {
            continue;
        }

        // Swap NULL customer [i] with the next VALID customer[j] if they exist
        for (int j = i + 1; j < rows; j++)
        {
            // A customer with no name is NULL/empty
            if (customers[j].name == NULL) 
            {
                continue;
            }

            // Swapping with a valid customer
            Customer _temp   =  customers[i];
            customers[i] =  customers[j];
            customers[j] =  _temp;
            break;
        }

        // Didn't swap with a valid customer?
        if (customers[i].name == NULL)
        {
            customer_count = i;
            break;
        }
    }
    return customer_count;
}

void customer_insertCoins(Customer *customers, const Currency *currencies, const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < MAX_CURRENCY_TYPES; j++)
        {
            if (!customers[i].change_values[j]) 
            {
                continue;
            }

            int temp_change = customers[i].change_values[j];
            for (int k = 0; k < MAX_COIN_VARIANTS; k++)
            {
                customers[i].coins_ptr[j][k] = temp_change / currencies[j].coins[k];
                temp_change = temp_change % currencies[j].coins[k];
            }
        }
    }
    return;
}

// ---- MENU ----

void customer_handleMenu(const Customer *customers, const Currency *currencies, const int rows)
{
    int selection;
    do 
    {
        program_pause(MSG_CONTINUE);
        customer_displayMenu();

        selection = read_intInRange(C_SEARCH, C_QUIT);

        switch (selection) 
        {
            case C_SEARCH:
                printf("\n---- Customer Name Search ----\n");
                printf("\nPlease enter a name: ");
                customer_nameSearch(customers, currencies, rows);
                break;
            case C_DISP_NAMES:
                printf("\n---- Customer Names ----\n");
                printf("ID   \tNAME\n");
                customer_handleDisplayData(customers, currencies, rows, selection);
                break;
            case C_DISP_ALL:
                printf("\n---- Customer Data ----\n");
                customer_handleDisplayData(customers, currencies, rows, selection);
                break;
            case C_QUIT:
                return;
            default:
                continue;
        }
    } while(selection != C_QUIT);
    return;
}

void customer_displayMenu()
{
    printf("\n-------- Customer Menu --------\n");
    printf("[%i] - Search customer\n", C_SEARCH);
    printf("[%i] - Display customer names\n", C_DISP_NAMES);
    printf("[%i] - Display customer data\n", C_DISP_ALL );
    printf("[%i] - Exit program\n", C_QUIT);
    return;
}

void customer_nameSearch(const Customer *customers, const Currency *currencies, const int rows)
{
    char search[MAX_SEARCH_BUFFER];
    read_string(search, sizeof(search));

    int found = 0;
    for (int i = 0; i < rows; i++)
    {
        if (compare_caseInsensitive(customers[i].name, search)) 
        {
            customer_displayData(customers[i], currencies);
            found = 1;
            break;
        }
    }
    if(!found)
    {
        printf("Name: %s\nNot found\n", search);
    }
    return;
}

void customer_handleDisplayData(const Customer *customers, const Currency *currencies, const int rows, const int selection)
{
    for (int i = 0; i < rows; i++)
    {
        switch (selection) 
        {
            case C_DISP_NAMES:
                printf("[%i]\t%s\n", i, customers[i].name); 
                break;

            case C_DISP_ALL:
                customer_displayData(customers[i], currencies);
                break;
            default: break;
        }
    }
    return;
}

void customer_displayData(const Customer customer, const Currency *currencies)
{
    printf("\nCustomer: %s\n", customer.name);

    for (int i = 0; i < MAX_CURRENCY_TYPES; i++)
    {   
        if(!customer.change_values[i])
        {
            continue;
        }

        printf("Change in cents %s: %i\n", currencies[i].code, customer.change_values[i]);

        for (int j = 0; j < MAX_COIN_VARIANTS; j++)
        {
            if(customer.coins_ptr[i][j])
            {
                printf("Cents %i: \t%i\n", currencies[i].coins[j], customer.coins_ptr[i][j]);
            }
        }
        printf("\n");
    }
    return;
}

// ---- MEMORY ----

void customer_freeMemory(Customer *customer_data, const int table_rows)
{
    if (!customer_data) // Empty? -> Return
    {
        return;
    }

    for (int i = 0; i < table_rows; i++)
    {
        free(customer_data[i].name);
    } 

    free(customer_data); 
    return;
}