#include "a2_customer.h"
#include "../general/a2_general.h"
#include "../program/a2_program.h"
#include <stdio.h>

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
    printf("---- Filtering Customer values ----\n\n");
    int customers_removed = 0;
    for (int i = 0; i < rows; i++)
    {
        // Invalidate AUD change value indivisible by 5
        if (customers[i].change_values[AUD_ID] % MIN_AUD_LIMIT) {
            printf("Customer: %s\n", customers[i].name);
            printf("Invalid AUD value: %i is not divisible by %i\n\n",customers[i].change_values[AUD_ID], MIN_AUD_LIMIT);
            customers[i].change_values[AUD_ID] = 0;
        }
        // If customer has any change, then check next customer 
        if (customers[i].change_values[USD_ID] || customers[i].change_values[AUD_ID] || customers[i].change_values[EUR_ID]) {
            continue;
        }
        // Customer has no change values -> set name to NULL, thus invalidating the customer
        if(customers[i].name != NULL) {
            printf("Removing: %s\n", customers[i].name);
            printf("Reason: No change values\n\n");
            customers[i].name = NULL;
            customers_removed++;
        }
    }

    if (customers_removed) {
        printf("Total customers removed: %i\n\n", customers_removed);
    }
    else {
        printf("All customers valid: %i\n\n", customers_removed);
    }

    program_pauseStatus(CONTINUE);
}

void customer_sortNull(Customer *customers, const int rows)
{
    // Swap invalid customers (left), with valid customers (right)
    for (int i = 0; i < rows; i++) 
    {  
        if(customers[i].name != NULL){
            continue;
        }

        // Swap NULL customer [i] with the next VALID customer[j] if they exist
        for (int j = i + 1; j < rows; j++)
        {
            // A customer with no name is NULL/empty
            if (customers[j].name == NULL) {
                continue;
            }

            // Swapping with a valid customer
            Customer _temp   =  customers[i];
            customers[i] =  customers[j];
            customers[j] =  _temp;
            break;
        }
    }
    return;
}

void customer_handleInsertCoins(Customer *customers, const Currency *currencies, const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < MAX_CURRENCY_TYPES; j++)
        {
            if (!customers[i].change_values[j])
                continue;

            customer_insertCoins(customers[i].change_values[j], customers[i].coins_ptr[j], currencies[j]);
        }
    }
    return;
}

void customer_insertCoins(const int customer_change, int customer_coins[], const Currency currencies)
{
    // Insert number of coins based on customer change
    int change = customer_change;
    for (int i = 0; i < MAX_COIN_VARIANTS; i++)
    {
        customer_coins[i] =  calculate_intDiv(change, currencies.coins[i]);
        change = calculate_intMod(change, currencies.coins[i]);
    }

    return;
}

int customer_count(Customer *customers, const int rows)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        if(customers[i].name != NULL){
            count++;
        }
    }
    //printf("Total customers after filter: %i\n\n", count);
    return count;
}

void customer_handleMenu(const Customer *customers, const Currency *currencies, const int rows)
{
    int selection;
    do {

        customer_displayMenu();

        selection = read_intInRange(C_SEARCH, C_QUIT);
        
        //program_clearInputBuffer();

        switch (selection) 
        {
            case C_SEARCH:
                customer_nameSearch(customers, currencies, rows, selection);
                break;
            case C_DISP_NAMES:
                printf("\n---- Customer Names ----\n");
                printf("ID   \tName\n");
                customer_handleDisplayOptions(customers, currencies, rows, NULL, selection);
                break;
            case C_DISP_ALL:
                printf("\n---- Customer Data ----\n");
                customer_handleDisplayOptions(customers, currencies, rows, NULL, selection);
                break;
            case C_QUIT:
                return;
            default:
                break;
        }
        program_pauseStatus(CONTINUE);

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

int customer_nameSearch(const Customer *customers, const Currency *currencies, const int rows, const int selection)
{
    char search[MAX_SEARCH_BUFFER];

    printf("\nPlease enter a name: ");
    read_string(search, sizeof(search));

    int index = customer_handleDisplayOptions(customers, currencies, rows, search, selection);

    if (index >= 0){
        customer_displayData(customers[index], currencies);
        return 1;
    }
    else {
        printf("Name: %s\nNot found\n", search);
        return 0;
    }
}

int customer_handleDisplayOptions(const Customer *customers, const Currency *currencies, const int rows, const char *search, const int option)
{
    int processed = -1;
    for (int i = 0; i < rows; i++)
    {
        switch (option) 
        {
            case C_SEARCH:
                if (!compare_caseInsensitive(customers[i].name, search)) {
                    break;
                }
                return i;

            case C_DISP_NAMES: 
                printf("[%i]\t%s\n", i, customers[i].name); 
                processed = 1;
                break;

            case C_DISP_ALL:
                customer_displayData(customers[i], currencies);
                processed = 1;
            default: break;
        }
    }
    return processed;
}

void customer_displayData(const Customer customer, const Currency *currencies)
{
    printf("\nCustomer: %s\n", customer.name);

    for (int i = 0; i < MAX_CURRENCY_TYPES; i++)
    {   
        if(!customer.change_values[i]){
            continue;
        }

        printf("Change in cents %s: %i\n", currencies[i].code, customer.change_values[i]);

        for (int j = 0; j < MAX_COIN_VARIANTS; j++)
        {
            if(customer.coins_ptr[i][j]) {
                printf("Cents %i: \t%i\n", currencies[i].coins[j], customer.coins_ptr[i][j]);
            }
        }
        printf("\n");
    }
    return;
}


void customer_freeMemory(Customer *customer_data, const int table_rows)
{
    if (!customer_data) return;

    for (int i = 0; i < table_rows; i++)
        free(customer_data[i].name);

    free(customer_data); 

    return;
}