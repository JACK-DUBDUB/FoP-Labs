#include "../currency/a2_currency.h"
#include "../program/a2_program.h"

// -------- INITIALIZE CUSTOMER POINTERS --------------------------------------------------------------------------------------

void customer_initPointers(CustomerArray *customers)
{
    // IF a new currency were to be added, we simply have to assign the pointer to it here (it just how it be...)
    for (int i = 0; i < customers->max; i++)
    {
        customers->data[i].c_ptr[USD_ID] = customers->data[i].c_usd;
        customers->data[i].c_ptr[AUD_ID] = customers->data[i].c_aud;
        customers->data[i].c_ptr[EUR_ID] = customers->data[i].c_eur;
        // customers->data[i].c_ptr[XYZ_ID] = customers->data[i].c_xyz;
    }
    return;
}


// -------- FILTER CUSTOMER VALUES POST READ ----------------------------------------------------------------------------------

void customer_filterValues(CustomerArray *customers, const CurrencyArray currencies)
{
    printf("\n---- Filtering Customer Data ----\n");

    int old_count = customers->count;

    for (int i = 0; i < customers->max; i++)
    {
        // Skippo!
        if (!customers->data[i].name)
        {
            continue;
        }
            
        int valid_customer = 0;
        for (int j = 0; j < currencies.max; j++)
        {
            // Logic:
            // -> USD & EURO last coin = 1
            // -> This will remove invalid AUD values by dividing its last coin (5 cents)
            // -> Last coin index for all coins = .count - 1
            if ((customers->data[i].values[j] % currencies.data[j].coins[currencies.data[j].count - 1]) != 0)
            {
                customers->data[i].values[j] = 0;
            }

            if (customers->data[i].values[j])
            {
                valid_customer++;
                break;
            }
        }

        // Set name to null
        if (!valid_customer)
        {
            printf("\nRemoved: %s\nReason: missing valid change values\n", customers->data[i].name);
            customers->data[i].name = NULL;
            customers->count--;
        }
    }

    // Feedback
    if(customers->count != old_count)
        printf("\nTotal customers removed: %i\n\n", old_count - customers->count);
    else if(!customers->count)
        printf("\nNo customers to filter!\n\n");
    else
        printf("\nAll customers valid!\n\n");
    
    return;
}

// -------- INSERT CUSTOMER COINS ---------------------------------------------------------------------------------------------

void customer_insertCoins(CustomerArray *customers, const CurrencyArray currencies)
{
    for (int i = 0; i < customers->max; i++)
    {
        for (int j = 0; j < currencies.max; j++)
        {
            // Skippo!
            if (!customers->data[i].values[j]) 
            {
                continue;
            }

            int temp_change = customers->data[i].values[j];

            for (int k = 0; k < currencies.data[j].count; k++)
            {
                customers->data[i].c_ptr[j][k] = temp_change / currencies.data[j].coins[k]; // Int division: Customer change / Coin Value 
                temp_change = temp_change % currencies.data[j].coins[k];    // Int modulus: Customer change % Coin value
            }
        }
        
    }
    return;
}


// -------- HANDLE CUSTOMER SEARCH --------------------------------------------------------------------------------------------

void customer_nameSearch(const CustomerArray customers, const CurrencyArray currencies)
{
    int found = 0;
    char search[MAX_CUSTOMER_SEARCH_BUFFER];
    read_string(search, sizeof(search));

    
    for (int i = 0; i < customers.max; i++)
    {
        if (compare_caseInsensitive(customers.data[i].name, search) == 0) 
        {
            customer_displayData(customers.data[i], currencies);
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

// -------- DISPLAY CUSTOMER DATA VALUES --------------------------------------------------------------------------------------


void customer_displayData(const Customer customer, const CurrencyArray currencies)
{
    printf("\nCustomer: %s\n", customer.name);

    for (int i = 0; i < currencies.max; i++)
    {   
        if(!customer.values[i])
        {
            continue;
        }

        printf("Change in cents %s: %i\n", currencies.data[i].code, customer.values[i]);

        for (int j = 0; j < currencies.data[i].count; j++)
        {
            if(customer.c_ptr[i][j])
            {
                printf("Cents %i: \t%i\n", currencies.data[i].coins[j], customer.c_ptr[i][j]);
            }
        }
        printf("\n");
    }
    return;
}

void customer_displayNames(const CustomerArray customers)
{
    printf("\n---- Customer Names ----\n\n");
    for (int i = 0; i < customers.max; i++)
    {
        if (customers.data[i].name) 
        {
            printf("-   %s\n", customers.data[i].name);
        }
    }
    if (!customers.max || !customers.count)
    {
        printf("-   No customers\n");
    }

    return;
}

// -------- FREE CUSTOMER MEMORY ----------------------------------------------------------------------------------------------

void customer_freeMemory(CustomerArray *customers)
{
    if (!customers->max || !customers->data) // Empty? -> Return
    {
        return;
    }
    for (int i = 0; i < customers->max; i++)
    {
        free(customers->data[i].name);
    }
    free(customers->data);
    customers->data = NULL;
    customers->count = 0; 
    customers->max = 0;
    return;
}