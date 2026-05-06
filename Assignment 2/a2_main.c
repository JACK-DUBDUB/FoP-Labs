
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

int main(int argc, char *argv[])
{
    // Initialize array of customers
    Customer *customer_data;

    switch(argc)
    {
        case 1:     printf("ERROR - One argument is expected \n"); return 1;
        case 2:     printf("The argument provided is '%s'\n", argv[1]); break;
        default:    printf("ERROR = Too many arguments provided \n"); return 2;
    }

    int table_rows = handle_fileCustomerData(argv[1], customer_data, "r", READ_ROWS);

    switch(table_rows)
    {
        case -1:    printf("ERROR - Failed to open file in 'r' mode. Make sure its a .txt file \n"); return 3;
        case 0:     printf("ERROR - Could not read lines of file '%s' in 'r' mode \n", argv[1]); return 4;
        default:    break;
    }


    customer_data = (Customer*) malloc(sizeof(Customer) * table_rows);

    // Zero ALL variables
    for (int i = 0; i < table_rows; i++)
    {
        customer_data[i].change_usd = 0;
        customer_data[i].change_aud = 0;
        customer_data[i].change_eur = 0;

        for (int j = 0; j < MAX_COIN_VARIANTS; j++)
        {
            customer_data[i].coins_usd[j] = 0;
            customer_data[i].coins_aud[j] = 0;
            customer_data[i].coins_eur[j] = 0;
        }
    }

    printf("Line count: %i\n\n", table_rows );


    handle_fileCustomerData(argv[1], customer_data, "r", READ_DATA);


    // Print contents
    for (int i = 0; i < table_rows; i++)
    {
        printf("Index: %i\n", i+1);
        printf("Customer Name: %s\n", customer_data[i].name);
        printf("%u \n%u \n%u\n",customer_data[i].change_usd, customer_data[i].change_aud, customer_data[i].change_eur);
        printf("Coin variants USD: %i, %i, %i, %i\n", customer_data[i].coins_usd[0], customer_data[i].coins_usd[1], customer_data[i].coins_usd[2], customer_data[i].coins_usd[3]);
        printf("Coin variants AUD: %i, %i, %i, %i\n", customer_data[i].coins_aud[0], customer_data[i].coins_aud[1], customer_data[i].coins_aud[2], customer_data[i].coins_aud[3]);
        printf("Coin variants EUR: %i, %i, %i, %i\n\n", customer_data[i].coins_eur[0], customer_data[i].coins_eur[1], customer_data[i].coins_eur[2], customer_data[i].coins_eur[3]);
    }

    free(customer_data);

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