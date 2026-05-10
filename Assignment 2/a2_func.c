#include <stdio.h>
#include <stdbool.h>
#include "a2_func.h"
#include "a2_crud.h"

// ---- get user input functions ----
int read_intInRange(const int min, const int max) 
{
    int input = -1;
    do 
    {
        printf("\nEnter a valid value: ");

        scanf_s("%i", &input);
        input = filter_intInRange(input, min, max);

    } while (input != READ_INT_ERROR );
    return input;
}

int filter_intInRange(const int input, const int min, const int max)
{
    if (input == READ_INT_ERROR ) {
        printf("\nUser did not enter an integer value.\n");
        clearInputBuffer();
        return READ_INT_ERROR ;
    }

    if (input == READ_INT_ERROR  && getchar() != '\n') {
        printf("\nUser entered an integer value with a non-integer value.\n");
        clearInputBuffer();
        return READ_INT_ERROR;
    }

    if (input == -1 && (input < min || input > max)) {
        printf("\nUser entered a value outside of range.\n" );
        return READ_INT_ERROR;
    }

    return input;
}

void init_customerPointers(Customer *customer_data, const int table_rows)
{
    for (int i = 0; i < table_rows; i++)
    {
        customer_data[i].coins_ptr[USD_ID] = customer_data[i].coins_usd;
        customer_data[i].coins_ptr[AUD_ID] = customer_data[i].coins_usd;
        customer_data[i].coins_ptr[EUR_ID] = customer_data[i].coins_usd;
    }
    return;
}

void shift_nullCustomerData(Customer *customer_data, const int table_rows)
{
    for (int i = 0; i < table_rows; i++) 
    {
        if (customer_data[i].change_values[AUD_ID] % MIN_AUD_LIMIT)
            customer_data[i].change_values[AUD_ID] = 0;

        if (customer_data[i].change_values[USD_ID] || customer_data[i].change_values[AUD_ID] || customer_data[i].change_values[EUR_ID])
            continue;
        
        // Thus implies that [i] has no values 
        customer_data[i].name = NULL;

        for (int j = i; j < table_rows; j++)
        {
            Customer _temp  =   customer_data[i];
            customer_data[i] =  customer_data[j];
            customer_data[j] =  _temp; 
        }

        bool rest_null = true;
        for (int j = i; j < table_rows; j++)
        {
            if(customer_data[j].name != NULL) {
                rest_null = false;
                break;
            }
        }

        if (rest_null)
            break;

    }
    return;
}


void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    return;
}

void clearInputBuffer()
{
    while (getchar() != '\n');
    return;
}

