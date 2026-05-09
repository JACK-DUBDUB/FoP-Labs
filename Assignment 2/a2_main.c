
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

void sort_coinVariants(int customer_change, int customer_currency[], const Currency currency_type);

void search_customerData(Customer *customer_data, const int table_rows, const char *name_search, const Currency *currencies, enum DISPLAY_MODE search);

void display_customerData(const Customer customer, const Currency *currencies);
void display_customerDataValues(Customer customer, const int index, const int customer_coins[], const Currency currency_type);
void free_customerData(Customer *customer_data, const int table_rows);


int main(const int argument_count, const char *argument_values[])
{
    // Heap
    Customer *customer_data; //   , Freed by free_customerData() 

    // Stack
    Currency currencies[MAX_CURRENCY_TYPES] = {
        USD,
        AUD,
        EUR
    };

    int table_rows = 0;
    

    switch(argument_count)
    {
        case 1:     printf("ERROR - One additional argument was expected \n"); return 1;
        case 2:     printf("The argument value provided is '%s'\n", argument_values[1]); break;
        default:    printf("ERROR = Too many arguments provided \n"); return 2;
    }


    handle_fileCustomerData(argument_values[1], customer_data, "r", READ_ROWS, &table_rows);

    switch(table_rows)
    {
        case -1:    printf("ERROR - Failed to open file in 'r' mode. Make sure its a .txt file \n"); return 3;
        case 0:     printf("ERROR - Could not read lines of file '%s' in 'r' mode \n", argument_values[1]); return 4;
        default:    break;
    }

    // Based on the number provided in the text file create table_rows number of customers
    // Calloc intializes all bytes to zero (- which is a good thing!) 
    customer_data = (Customer*) calloc(table_rows, sizeof(Customer)); // (Cast operator*)

    // Display initial line count
    printf("Line count: %i\n\n", table_rows );

    /*//Proof that it works
    for (int i = 0; i < CURRENCY_MAX; i++)
    {
        printf("\n\nCurrency %i: ", i);
        for (int j = 0; j < MAX_COIN_VARIANTS; j++)
        {
            printf("%i ", currencies[i].coins[j]);
        }

    }*/


    // Read values from customers
    handle_fileCustomerData(argument_values[1], customer_data, "r", READ_DATA, &table_rows);


    
    // Sort coins
    for (int i = 0; i < table_rows; i++)
    {
        if (customer_data[i].change_values[CURRENCY_USD] > 0) {
            sort_coinVariants(customer_data[i].change_values[CURRENCY_USD], customer_data[i].coins_usd, currencies[CURRENCY_USD]);
        }
            
        if (customer_data[i].change_values[CURRENCY_AUD] >= MIN_AUD_LIMIT) {
            sort_coinVariants(customer_data[i].change_values[CURRENCY_AUD], customer_data[i].coins_aud, currencies[CURRENCY_AUD]);
        }

        if (customer_data[i].change_values[CURRENCY_EUR] > 0) {
            sort_coinVariants(customer_data[i].change_values[CURRENCY_EUR], customer_data[i].coins_eur, currencies[CURRENCY_EUR]);
        }
    }


    // Search tests
    search_customerData(customer_data, table_rows, NULL, currencies, DISPLAY_ALL);
    search_customerData(customer_data, table_rows, "Eggsontoast", currencies, DISPLAY_ONLY);

    // Write to file
    handle_fileCustomerData("change.csv", customer_data, "w", CREATE_CSV, &table_rows);
    

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


void sort_coinVariants(const int customer_change, int customer_coins[], const Currency currencies)
{
    // Filter 
    if (customer_change > 95) 
        return;

    if (currencies.position == CURRENCY_AUD && customer_change % MIN_AUD_LIMIT != 0) 
        return;

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
    for (int i = 0; i < table_rows; i++)
    {
        if (customer_data[i].name == NULL)
            break;

        if (search == DISPLAY_ONLY) {

            if (compare_nameCaseInsensitive(customer_data[i].name, name_search))
                display_customerData(customer_data[i], currencies); 
            else
                printf("Name: %s\nNot found\n", name_search);
        }

        if (search == DISPLAY_ALL) {
            display_customerData(customer_data[i], currencies);
        }

    }
    return;
}

void display_customerData(const Customer customer, const Currency *currencies)
{
    printf("\nCustomer: %s\n", customer.name);
    for (int i = 0; i < MAX_CURRENCY_TYPES; i++)
    {
        if (customer.change_values[i] > MAX_CHANGE_LIMIT) {
            printf("%s change exceeded limit: %i cents\n", customer.name, MAX_CHANGE_LIMIT); 
            continue;
        }
            

        if (currencies[i].position == CURRENCY_AUD && customer.change_values[i] % MIN_AUD_LIMIT != 0 ) {
            printf("%s change is not a multiple of %i\n", customer.name, MIN_AUD_LIMIT); 
            continue;
        }
            

        if (customer.change_values[i] > 0) // If customer has any valid USD/AUD/EUR
        {
            switch (i) 
            {
                case CURRENCY_USD: display_customerDataValues(customer,  i, customer.coins_usd, currencies[CURRENCY_USD]); break;
                case CURRENCY_AUD: display_customerDataValues(customer,  i, customer.coins_aud, currencies[CURRENCY_AUD]); break;
                case CURRENCY_EUR: display_customerDataValues(customer,  i, customer.coins_eur, currencies[CURRENCY_EUR]); break;
                default: break;
            }
        }

    }
}

void display_customerDataValues(Customer customer, const int index, const int customer_coins[], const Currency currencies)
{
    printf("Change in cents %s: %i\n", currencies.currency_code, customer.change_values[index]);
    for (int i = 0; i < MAX_COIN_VARIANTS; i++)
    {
        if(customer_coins[i])
            printf("%i cents: %i\n", currencies.coins[i], customer_coins[i]);
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