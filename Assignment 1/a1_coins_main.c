
/** Assignment 1 -  Coin sorting program
 * ---- Author ----
 * Name:    Jack du Boulay
 * ID:      32712899
 * 
 * ---- About ----
 * CLI program that sorts change (money) into the appropriate coin values
 * Takes in 2 user inputs using the CLI, one input for the change (money) amount, another input for choosing the currency type (US/AU/EU). 
 * Program then displays the correct amount of change (but thats just a theory, a game theory...)
 * 
 * ---- Compile and Run ----
 * gcc '.\a1_coins_main.c' '.\a1_coins_const.c' '.\a1_coins_func.c' -o a1_coins
 * 
 */

/** QUESTIONS
 * - Ensure that the multiple value is equal to 5 for AUD <- WHAT! Why can't i just round it?
 */

#include <stdio.h>
#include "a1_coins_func.h"
#include "a1_coins_const.h"

int main()
{
    int exitProgram = 0;
    int userChangeInitial = 0;  
    int userChangeFinal = 0; 
    int userSelection = 0;
    int arraySize = 0;

    do
    {
        /** [Step 1] - Get user input for currency selection
         *      a. Display the selection menu, then prompt the user to enter an integer value between (1-3) inclusive.
         *      b. Get the user input and filter it for validity, returning a value to main.
         *      c. If the user input fails, then quit program.
         *      d. If the user input is valid we continue with program.
         */
        displayMenu(currencyArray, currencyArrayNum, coinsArraySizes, CURRENCY_TYPE_S);                                                  
        userSelection = getUserInt(CURR_SELECTION_MIN, currencyArrayNum, 1, CURRENT_STEP_S[0]) - 1;   // Range min and max: (1, 3)  | -1 because array index starts at 0;
        printf("User selected: %s", CURRENCY_TYPE_S[userSelection]);
        /** [Step 2] - Get user input for change value
         *      a. Prompt the user to enter an integer value between (1-95) inclusive.
         *      b. Get the user input and filter it for validity, returning a value to main.
         *      c. If the user input fails, then quit program.
         *      d. If the user input is valid we continue with program.
         */
        printf("\n/// Enter change value ///");
        userChangeInitial = getUserInt(USER_CHANGE_MIN, USER_CHANGE_MAX, currencyArray[userSelection][currencyArrayNum], CURRENT_STEP_S[1]);                // (1, 95) -> the range min and max of whats valid

        /** [Step 3] - Calculate and display correct amount of change
         *      a. Get the correct array size based on the valid currency selection made in [Step 1]. 
         *      b. Calculate the number of coins required to total to the user's change
         *      c. Display the correct change allocation for the change inserted from [Step 2].
         */
        arraySize = coinsArraySizes[userSelection];
        int sortedCoins[arraySize]; 
        userChangeFinal = calculateChange(userChangeInitial, currencyArray[userSelection], arraySize, CURRENCY_TYPE_S[userSelection], sortedCoins); // Retursn change if any
        displayChange(userChangeInitial, userChangeFinal, sortedCoins, currencyArray[userSelection], arraySize, CURRENCY_TYPE_S[userSelection]);

        /** [Step 5] - Ask user to quit/retry
         *      a. Display exit selection menu, prompt user to enter an integer value between 0 and 1 inclusive
         *      b. Exit/retry program based on selection.
         *          1. If exit  -> exit program
         *          2. If retry -> wipe screen and start again 
         */
        printf("\n/// Retry or Exit ///\n");
        printf("Would you like to try again or quit program?\n");
        printf("[%i] - Exit program\n[%i] - Try again \n", PROG_EXIT, PROG_REPEAT);
        exitProgram = getUserInt(PROG_EXIT, PROG_REPEAT, 1, CURRENT_STEP_S[2]);
        if(exitProgram != 1){
            exitProgram = USER_INPUT_ERROR;
        }
        else{ // clear screen - crude version
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // the ANSI escape codes weren't working properly for me...
        }
    } while (exitProgram != USER_INPUT_ERROR);

    // Exit
    pauseExitProgram();
    return 0;
}