
/** Assignment 1 -  Coin sorting program
 * ---- Author ----
 * Name:    Jack du Boulay
 * ID:      32712899
 * Date:    12/04/2026
 * 
 * ---- About Program ----
 * CLI program that prompts the user to pick from 3 types of currencies.
 * Then prompts the user to insert their change amount that they want to sort into correct coin amounts/values.
 * Then displays the optimal/appropriate number of coin values.
 * Then prompts the user to try again or quit program.  
 *  
 * ---- Program Flow ----
 *  [START]
 *  [Step 1] Get 1 input for choosing the currency type (US/AU/EU)
 *      -> [Step 2] Get the 4 values of coin values according to the currency type selected
 *  [Step 3] Get 1 input for the change value (1-95) 
 *      -> [Step 4] Program displays the user's values they've entered
 *      -> [Step 5] Program calculates the appropriate number of coins
 *      -> [Step 6] Program displays the number of coins per coin value
 *  [Step 7] Get 1 input to continue/quit program (1-2)
 *       -> If user continues: Repeat 3 input process again -> Back to [Step 1]
 *       -> Else quit program 
 *  [END]
 * 
 * Takes in 3 user inputs using the CLI
 * If user inserts an invalid value for any inputs, CLI will display error message type then re-prompted to try again.
 * 
 * ---- Compile and Run ----
 * Compiled: gcc .\a2_main.c .\a2_func.c .\a2_crud.c -o a2.exe
 * gcc -Wall -Wextra -Wpedantic -std=c17 ".\a1_coins_main.c" ".\a1_coins_func.c" -o a1_coins.exe && .\a1_coins.exe
 * 
 * Run: .\a2.exe
 */

#include "a2_func.h"
#include "a2_crud.h"
#include <stdbool.h>
#include <stdio.h>

void sort_coinVariants(int customer_change, int customer_currency[], const Currency currency_type);
void handle_sortCoinVariants(Customer *customer_data, const Currency *currencies, const int table_rows);



void search_customerData(Customer *customer_data, const int table_rows, const char *name_search, const Currency *currencies, enum DISPLAY_MODE search);
void display_customerData(const Customer customer, const Currency *currencies);
void display_customerDataValues(Customer customer, const int index, const int customer_coins[], const Currency currency_type);
void free_customerData(Customer *customer_data, const int table_rows);


int main(const int argument_count, const char *argument_values[])
{
    // Heap
    Customer *customer_data; //   , Freed by free_customerData() 

    // Stack
    Currency currencies[MAX_CURRENCY_TYPES] = {USD, AUD,EUR };

    switch(argument_count)
    {
        case 1:     printf("ERROR - One additional argument was expected \n"); return 1;
        case 2:     printf("The argument value provided is '%s'\n", argument_values[1]); break;
        default:    printf("ERROR = Too many arguments provided \n"); return 2;
    }

    int table_rows = 0;
    handle_fileCustomerData(argument_values[1], customer_data, "r", READ_ROWS, &table_rows);

    switch(table_rows)
    {
        case -1:    printf("ERROR - Failed to open file in 'r' mode. Make sure its a .txt file \n"); return 3;
        case 0:     printf("ERROR - Could not read lines of file '%s' in 'r' mode \n", argument_values[1]); return 4;
        default:    break;
    }

    const int rows = table_rows;
    // Based on the number provided in the text file create table_rows number of customers
    // Calloc intializes all bytes to zero (- which is a good thing!) 
    customer_data = (Customer*) calloc(table_rows, sizeof(Customer)); // (Cast operator*)

    printf("Size of customer array: %i\n", (int) sizeof(*customer_data));

    

    // Point to arrays
    for (int i = 0; i < rows; i++)
    {
        customer_data[i].coins_ptr[CURRENCY_USD] = customer_data[i].coins_usd;
        customer_data[i].coins_ptr[CURRENCY_AUD] = customer_data[i].coins_aud;
        customer_data[i].coins_ptr[CURRENCY_EUR] = customer_data[i].coins_eur;
    }


    // Display initial line count
    printf("Line count: %i\n\n", table_rows );

    // Read values from customers
    handle_fileCustomerData(argument_values[1], customer_data, "r", READ_DATA, &table_rows);

    for (int i = 0; i < table_rows; i++) 
    {
        if (customer_data[i].change_values[CURRENCY_AUD] % MIN_AUD_LIMIT)
            customer_data[i].change_values[CURRENCY_AUD] = 0;

        for (int j = i; j < table_rows - 1; j++)
        {
            // Null the customer string as they have no values
            if (!customer_data[i].change_values[CURRENCY_USD] && !customer_data[i].change_values[CURRENCY_AUD]  && !customer_data[i].change_values[CURRENCY_EUR])
            {
                customer_data[i].name = NULL;
                Customer _temp = customer_data[i];
                customer_data[i] = customer_data[j];
                customer_data[j] = _temp; 
            }
        }
    }

    // Sort customer coins
    handle_sortCoinVariants(customer_data, currencies, table_rows);

    for (int i = 0; i < table_rows; i++)
    {
        printf("\n\nIndex: %i \nName: %s", i, customer_data[i].name);
        for (int j = 0; j < MAX_CURRENCY_TYPES; j++)
        {
            printf("\nChange in %s: %i |", currencies[j].currency_code, customer_data[i].change_values[j]);

            for (int k = 0; k < MAX_COIN_VARIANTS; k++)
            {
                printf("%i|", customer_data[i].coins_ptr[j][k]);
            }
        }
    }


    // Search tests
    search_customerData(customer_data, table_rows, NULL, currencies, DISPLAY_ALL);
    //search_customerData(customer_data, table_rows, "Eggsontoast", currencies, DISPLAY_SEARCH);
    search_customerData(customer_data, table_rows, NULL, currencies, DISPLAY_NAMES);

    // Write to file
    handle_fileCustomerData("change.csv", customer_data, "w", CREATE_CSV, &table_rows);
    
    // Free customer_data
    free_customerData(customer_data,  table_rows);

    pauseExitProgram();
    //printf("%s, %i, Coins: %i, %i, %i, %i\n", currencies[0].currency_code, currencies[0].position, currencies[0].coins[0], currencies[0].coins[1], currencies[0].coins[2], currencies[0].coins[3]);

    /*
    // ==== COINS ====
    int coinValue_1, coinValue_2, coinValue_3, coinValue_4;
    int coinAmount_1, coinAmount_2, coinAmount_3, coinAmount_4;

    // ==== VARIABLES ====
    int userCurrencyType = 0;
    int userChange = 0;  
    int exitProgram = 0;

    do {
        // [Step 1] - Get user input for currency selection
        promptUserCurrency();                                                                          
        userCurrencyType = getUserInt(CURRENCY_MIN, CURRENCY_MAX);              

        // [Step 2] - Get the correct coin values according to currency type selected
        coinValue_1 = getCoinValue(userCurrencyType, COIN_VAL_50, COIN_VAL_50, COIN_VAL_20); 
        coinValue_2 = getCoinValue(userCurrencyType, COIN_VAL_25, COIN_VAL_20, COIN_VAL_10);
        coinValue_3 = getCoinValue(userCurrencyType, COIN_VAL_10, COIN_VAL_10, COIN_VAL_5);
        coinValue_4 = getCoinValue(userCurrencyType, COIN_VAL_1,  COIN_VAL_5,  COIN_VAL_1); // Lowest coin values

        // [Step 3] - Get user input for change value                                   
        promptUserChange(coinValue_4, CHANGE_RANGE_MAX, userCurrencyType);           
        userChange = getUserInt(coinValue_4, CHANGE_RANGE_MAX);
        
        // [Step 4] - Display user's values
        displayUserValues(userCurrencyType, userChange);     

        // [Step 5] - Calculate correct amount of coins
        coinAmount_1 = getCoinAmount(coinValue_1, userChange);
        userChange = getChangeRemaining(coinValue_1, coinAmount_1, userChange);

        coinAmount_2 = getCoinAmount(coinValue_2, userChange);
        userChange = getChangeRemaining(coinValue_2, coinAmount_2, userChange);

        coinAmount_3 = getCoinAmount(coinValue_3, userChange);
        userChange = getChangeRemaining(coinValue_3, coinAmount_3, userChange);
        
        coinAmount_4 = getCoinAmount(coinValue_4, userChange);

        // [Step 6] - Display the number of coins                            
        displayCoinResults(coinValue_1, coinAmount_1);
        displayCoinResults(coinValue_2, coinAmount_2);
        displayCoinResults(coinValue_3, coinAmount_3);                        
        displayCoinResults(coinValue_4, coinAmount_4);   

        // [Step 7] - Ask user to quit/retry
        promptUserExit();                                                                               
        exitProgram = getUserInt(PROG_CONT, PROG_EXIT);

    } while (exitProgram != PROG_EXIT);

    pauseExitProgram();
    */
    return 0;
}

// ---- HEAP ----

void handle_sortCoinVariants(Customer *customer_data, const Currency *currencies, const int table_rows)
{
    for (int i = 0; i < table_rows; i++)
    {
        for (int j = 0; j < MAX_CURRENCY_TYPES; j++)
        {
            if (!customer_data[i].change_values[j])
                continue;

            sort_coinVariants(customer_data[i].change_values[j], customer_data[i].coins_ptr[j], currencies[j]);
        }
    }
    return;
}

void sort_coinVariants(const int customer_change, int customer_coins[], const Currency currencies)
{
    // Insert number of coins based on customer change
    int change = customer_change;
    for (int i = 0; i < MAX_COIN_VARIANTS; i++)
    {
        customer_coins[i] =  getCoinAmount(currencies.coins[i], change);
        change = getChangeRemaining(currencies.coins[i], customer_coins[i], change);
    }

    return;
}

void search_customerData(Customer *customer_data, const int table_rows, const char *name_search, const Currency *currencies, enum DISPLAY_MODE search)
{
    switch (search) 
    {
        case DISPLAY_SEARCH: printf("---- %s Data ----\n", name_search); break;
        case DISPLAY_ALL: printf("---- All Customer Data ----\n"); break;
        case DISPLAY_NAMES: printf("---- All Customer names ----\n"); break;
        default: return;
    }   



    for (int i = 0; i < table_rows; i++)
    {
        if (customer_data[i].name == NULL)
            break;

        if (search == DISPLAY_SEARCH) {

            if (compare_nameCaseInsensitive(customer_data[i].name, name_search))
                display_customerData(customer_data[i], currencies); 
            else
                printf("Name: %s\nNot found\n", name_search);
        }

        if (search == DISPLAY_ALL) {
            display_customerData(customer_data[i], currencies);
        }

        if (search == DISPLAY_NAMES)
            printf("- %s  \t[%i]\n", customer_data[i].name, i);
    }
    printf("\n\n");

    return;
}

void display_customerData(const Customer customer, const Currency *currencies)
{
    printf("\nCustomer: %s\n", customer.name);

    for (int i = 0; i < MAX_CURRENCY_TYPES; i++)
    {
        if (customer.change_values[i]) // If customer has any valid USD/AUD/EUR
        {
            printf("Change in cents %s: %i\n", currencies[i].currency_code, customer.change_values[i]);

            for (int j = 0; j < MAX_COIN_VARIANTS; j++)
            {
                if(customer.coins_ptr[i][j])
                    printf("Cents %i: \t%i\n", currencies[i].coins[j], customer.coins_ptr[i][j]);
            }

            printf("\n");
        }
    }
    return;
}

void display_customerDataValues(Customer customer, const int index, const int customer_coins[], const Currency currencies)
{
    printf("Change in cents %s: %i\n", currencies.currency_code, customer.change_values[index]);
    for (int i = 0; i < MAX_COIN_VARIANTS; i++)
    {
        if(customer_coins[i])
            printf("Cents %i: \t%i\n", currencies.coins[i], customer_coins[i]);
    }
    printf("\n");
    return;
}

void free_customerData(Customer *customer_data, const int table_rows)
{
    if (!customer_data) return;

    for (int i = 0; i < table_rows; i++)
        free(customer_data[i].name);

    free(customer_data); 
    return;
}