
/** Assignment 1 -  Coin sorting program
 * ---- Author ----
 * Name:    Jack du Boulay
 * ID:      32712899
 * Date:    12/04/2026
 * 
 * ---- About Program ----
 * CLI program that prompts the user to pick from 3 types of currencies.
 * Then prompts the user to insert their change amount that they want to sort into correct coin amounts/values.
 * Then displays the correct optimal/appropriate number of coin values.
 * Then prompts the user to try again or quit the program.  
 *  
 * ---- Summary of Steps ----
 * Takes in 3 user inputs using the CLI:
 *      - [Step 1] 1 input for choosing the currency type (US/AU/EU)
 *      - [Step 2] 1 input for the change value (cents) 
 *              -> [Step 4] Program calculates required coins
 *              -> [Step 3] Program displays the correct number of coins
 *      - [Step 4] 1 input to continue/quit program
 *              -> If user continues: Repeat 3 input process again -> Back to [Step 1]
 *              -> Else quit program [End]
 * 
 * If the user inserts an invalid value for their inputs, they will be displayed an error message then re-prompted to try again until they insert a valid value for the.
 * 
 * ---- Compile and Run ----
 * gcc '.\a1_coins_main.c' '.\a1_coins_const.c' '.\a1_coins_func.c' -o a1_coins
 * 
 */

#include <stdio.h>
#include "a1_coins_func.h"

int main()
{
    // ==== CONSTANTS ====
    // ---- Coin Arrays ---- 
    // Always largest to smallest value
    const int coinsUS[] = {50, 25, 10, 1};
    const int coinsAU[] = {50, 20, 10, 5};
    const int coinsEU[] = {20, 10,  5, 1};

    // Array of pointers to arrays
    const int *currencyArray[] = {coinsUS, coinsAU, coinsEU}; // 2D array

    // ---- Array Sizes ---- 
    // Store the size of each array
    const int coinsArraySizes[] = {
        sizeof(coinsUS) / sizeof(coinsUS[0]),
        sizeof(coinsAU) / sizeof(coinsAU[0]),
        sizeof(coinsEU) / sizeof(coinsEU[0]),
    };

    // Store size of pointer coins Array
    const int currencyArrayNum = sizeof(currencyArray) / sizeof(currencyArray[0]); 

    // ---- Strings ---- 
    // Array of pointers to "strings"
    const char *CURRENCY_TYPE_S[] = {
        "$ USD", 
        "$ AUD", 
        "$ EUR"
    };

    // ==== VARIABLES ====
    // User variables
    int userChange = 0;  
    int userCurrencyType = 0;

    // Calculation
    int arraySize = 0;

    // Exit
    int exitProgram = 0;

    do
    {
        /** [Step 1] - Get user input for currency selection
         *      a. Display the selection menu prompting the user to enter an integer value between (1-3) inclusive.
         *      b. Get the user input and filter it for validity, returning a valid user selection.
         *      c. Display what currency type the user selected.
         */
        promptUserCurrency();
        userCurrencyType = getUserInt(CURR_SELECTION_MIN, currencyArrayNum) - 1;   // Range min and max: (1, 3)  | -1 because array index starts at 0;
        printf("User selected: %s\n", CURRENCY_TYPE_S[userCurrencyType]);

        /** [Step 2] - Get user input for change value
         *      a. Prompt the user to enter an integer value between (x-95) inclusive.
         *      b. Get the user input and filter it for validity, returning a a valid change amount.
         *      c. Display the currency amount the user entered.
         */
        arraySize = coinsArraySizes[userCurrencyType] - 1; // will return size 4 but -1 to get actual index, otherwise we'll access memory where we shouldnt...
        promptUserChange(currencyArray[userCurrencyType][arraySize], CHANGE_RANGE_MAX);
        userChange = getUserInt(currencyArray[userCurrencyType][arraySize], CHANGE_RANGE_MAX);
        printf("User change amount: %i\n\n", userChange);

        /** [Step 3] - Calculate correct amount of coins
         *      a. Using the user selected currency type, and get the size of the array (number of available elements)
         *      b. Intialize the array sortedCoins with the number of elements equal to the arraySize of the currency type picked.
         *      c. Calculate the corrrect change amount (Technically we don't return anything with this process (void), however we insert the correct number of coins into the sortedCoins array)
         */
        arraySize = coinsArraySizes[userCurrencyType];
        int sortedCoins[arraySize];
        calculateCoins(userChange, currencyArray[userCurrencyType], sortedCoins, arraySize);

        /** [Step 4] - Display correct amount of coins
         *  A. Display the calculated optimal number of coins required to meet change amount the user had inserted.
         */
        printf("\n/// Calculated Coins ///\n");
        printf("Currency type selected: %s\n", CURRENCY_TYPE_S[userCurrencyType]);
        printf("Change value inserted: %i cents\n", userChange);
        displayCoins(sortedCoins, currencyArray[userCurrencyType], arraySize);


        /** [Step 5] - Ask user to quit/retry
         *      a. Display exit selection menu prompting user to enter an integer value between 0 and 1 inclusive
         *      b. Exit/retry program based on selection.
         *          1. If exit  -> exit program
         *          2. If retry -> "wipe screen" and start again 
         */
        promptUserExit();
        exitProgram = getUserInt(PROG_REPEAT, PROG_EXIT);
        if(exitProgram == PROG_REPEAT){
            // Crude version of a screenwipe. 
            // ANSI escape codes weren't working properly for me in CMD... it might be a GCC exclusive?
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        }

    } while (exitProgram != PROG_EXIT);

    // Exit
    pauseExitProgram();
    return 0;
}