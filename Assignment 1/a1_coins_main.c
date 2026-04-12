
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
 *              -> [Step 3] Program then displays the correct amount of change after receiving valid input
 *      - [Step 4] 1 input to continue/quit program
 *              -> If user continues: Repeat 3 input process again -> Back to [Step 1]
 *              -> Else quit program [End]
 * 
 * If the user inserts an invalid value for their inputs, they will be displayed an error message then re-prompted to try again until they insert a valid value for the.
 * 
 * ---- My thoughts of Assignment 1 ----
 * 2. The structure chart (10%)
 *  I fundamentally disagree with the idea of strict adherence:"your algorithm / program should match this structure chart otherwise marks will be deducted."
 *  REAL PROGRAMMERS REFACTOR CONSTANTLY!!!
 *  As you progress with the programming itself, new solutions will always be found for how things can be refactored, implemented and/or reused.
 *  The more one programs, the more insight, knowledge and concepts become accessible to them as programmer as they progress and gain experience.
 *  So I disagree with strict adherence to the structure chart as it relies on the user's own pre-existing knowledge of what 'might' be required, not taking into account of the unknown unkowns.
 *  It does not take into account of user-error either, which is always abound, so coming up with new strategies to mitigate user-errors makes it an ever evolving process.
 *  So strict adherence prior to the structure chart prior to actuall programming as a novice you may be:
 *      - unaware of possible Edge Cases
 *      - unaware of pre-existing library functions that could replace the need of entire modules
 *      - forced into a design purely of PREDICTED needs and not ACTUAL needs
 * 
 * So why design an assignment that penalizes a student for learning and applying the correct concepts?
 * 
 * 
 * ---- Compile and Run ----
 * gcc '.\a1_coins_main.c' '.\a1_coins_const.c' '.\a1_coins_func.c' -o a1_coins
 * 
 */

#include <stdio.h>
#include "a1_coins_func.h"
#include "a1_coins_const.h"

int main()
{
    int exitProgram = 0;
    int userChange = 0;  
    int userCurrencyType = 0;
    int arraySize = 0;

    do
    {
        /** [Step 1] - Get user input for currency selection
         *      a. Display the selection menu 
         *      b. Prompt the user to enter an integer value between (1-3) inclusive.
         *      c. Get the user input and filter it for validity, returning a valid user selection.
         *      d. Display what currency type the user selected.
         */
        displayCurrencyMenu(currencyArray, currencyArrayNum, coinsArraySizes, CURRENCY_TYPE_S);                                                  
        userCurrencyType = getUserInt(CURR_SELECTION_MIN, currencyArrayNum, LOWEST_MULTIPLE, CURRENT_STEP_S[0]) - 1;   // Range min and max: (1, 3)  | -1 because array index starts at 0;
        printf("User selected: %s\n", CURRENCY_TYPE_S[userCurrencyType]);


        /** [Step 2] - Get user input for change value
         *      a. Prompt the user to enter an integer value between (x-95) inclusive.
         *      b. Get the user input and filter it for validity, returning a a valid change amount.
         *      c. Display the currency amount the user entered.
         */
        printf("\n/// Enter change value ///");
        userChange = getUserInt(USER_CHANGE_MIN, USER_CHANGE_MAX, currencyArray[userCurrencyType][currencyArrayNum], CURRENT_STEP_S[1]);                // (1, 95) -> the range min and max of whats valid
        printf("User change amount: %i\n", userChange);


        /** [Step 3] - Calculate and display correct amount of change
         *      a. Using the user selected currency type, and get the size of the array (number of available elements)
         *      b. Intialize the array sortedCoins with the number of elements equal to the arraySize of the currency type picked.
         *      c. Calculate the corrrect change amount (Technically we don't return anything with this process (void), however we insert the correct number of coins into the sortedCoins array)
         *      d. Display the optimal number of coins required to meet change amount the user had inserted.
         */
        arraySize = coinsArraySizes[userCurrencyType];
        int sortedCoins[arraySize]; 
        calculateChange(userChange, currencyArray[userCurrencyType], coinsArraySizes[userCurrencyType], CURRENCY_TYPE_S[userCurrencyType], sortedCoins);
        displayChange(userChange, sortedCoins, currencyArray[userCurrencyType], coinsArraySizes[userCurrencyType], CURRENCY_TYPE_S[userCurrencyType]);


        /** [Step 4] - Ask user to quit/retry
         *      a. Display exit selection menu, prompt user to enter an integer value between 0 and 1 inclusive
         *      b. Exit/retry program based on selection.
         *          1. If exit  -> exit program
         *          2. If retry -> "wipe screen" and start again 
         */
        printf("\n\n/// Retry or Exit ///\n");
        printf("Would you like to try again or exit program?\n");
        printf("[%i] - Exit program\n[%i] - Try again \n", PROG_EXIT, PROG_REPEAT);
        exitProgram = getUserInt(PROG_EXIT, PROG_REPEAT, LOWEST_MULTIPLE, CURRENT_STEP_S[2]);

        if(exitProgram == PROG_REPEAT){
            // Clears the screen but its the crude version. ANSI escape codes weren't working properly for me in CMD... it might be a GCC exclusive?
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        }

    } while (exitProgram != PROG_EXIT);

    // Exit
    pauseExitProgram();
    return 0;
}