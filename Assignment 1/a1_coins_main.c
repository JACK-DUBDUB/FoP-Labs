
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
 *  [Step 2] Get 1 input for the change value (1-95) 
 *      -> [Step 3] Program calculates required coins
 *      -> [Step 4] Program displays the correct number of coins
 *  [Step 5] Get 1 input to continue/quit program (1-2)
 *       -> If user continues: Repeat 3 input process again -> Back to [Step 1]
 *       -> Else quit program 
 *  [END]
 * 
 * Takes in 3 user inputs using the CLI
 * If user inserts an invalid value for any inputs, CLI will display error message type then re-prompted to try again.
 * 
 * ---- Compile and Run ----
 * gcc '.\a1_coins_main.c' '.\a1_coins_func.c' -o a1_coins
 * 
 */

#include <stdio.h>
#include "a1_coins_func.h"

int main()
{
    // ==== CONSTANTS ====
    const int coinsUS[] = {50, 25, 10, 1};
    const int coinsAU[] = {50, 20, 10, 5};
    const int coinsEU[] = {20, 10,  5, 1};
    const int *currencyArray[] = {coinsUS, coinsAU, coinsEU}; // Essentially a 2D array but better
    const char *currencyType_str[] = {"$ USD", "$ AUD", "$ EUR"};

    // ==== VARIABLES ====
    int userCurrencyType = 0;
    int userChange = 0;  
    int exitProgram = 0;

    do {
        int sortedCoins[] = {0, 0, 0, 0};

        // [Step 1] - Get user input for currency selection
        promptUserCurrency();                                                                          
        userCurrencyType = getUserInt(CURR_SELECTION_MIN, CURR_SELECTION_MAX) - 1; // Get actual index                    

        // [Step 2] - Get user input for change value                                   
        promptUserChange(currencyArray[userCurrencyType][COIN_LAST_INDEX], CHANGE_RANGE_MAX);           
        userChange = getUserInt(currencyArray[userCurrencyType][COIN_LAST_INDEX], CHANGE_RANGE_MAX);    

        // [Step 3] - Calculate correct amount of coins                                                                                                 
        calculateCoins(userChange, currencyArray[userCurrencyType], sortedCoins);

        // [Step 4] - Display values and correct number of coins
        displayUserValues(currencyType_str[userCurrencyType], userChange);                               
        displayCoins(sortedCoins, currencyArray[userCurrencyType]);                    

        // [Step 5] - Ask user to quit/retry
        promptUserExit();                                                                               
        exitProgram = getUserInt(PROG_REPEAT, PROG_EXIT);

    } while (exitProgram != PROG_EXIT);

    pauseExitProgram();
    return 0;
}