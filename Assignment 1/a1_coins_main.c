
/** Assignment 1 -  Coin sorting program
 * ---- Author ----
 * Name:    Jack du Boulay
 * ID:      32712899
 * 
 * ---- About ----
 * CLI program that sorts change (money) into the appropriate coin values
 * Takes in 2 user inputs using the CLI, one input for the change (money) amount, another input for choosing the currency type (US/AU/EU). 
 * The displays the correct amount of change (ideally). 
 * 
 * ---- Compile and Run ----
 * gcc '.\a1_coins_main.c' '.\a1_coins_const.c' '.\a1_coins_func.c' -o a1_coins
 * 
 */

/** QUESTIONS
 * - Ensure that the multiple value is equal to 5 for AUD <- WHAT? Why can't i just round
 */

#include <stdio.h>
#include "a1_coins_func.h"
#include "a1_coins_const.h"

int main()
{
    int exitProgram = 0;
    int userChange = 0;
    int userSelection = 0;
    int arraySize = 0;

    do
    {
        /** [Step 1] - Get user input for change value
         *      a. Prompt the user to enter an integer value between (1-95) inclusive.
         *      b. Get the user input and filter it for validity, returning a value to main.
         *      c. If the user input fails, then quit program.
         *      d. If the user input is valid we continue with program.
         */
        printf("\nPlease enter change amount (%d-%d cents): ", CHANGE_MIN, CHANGE_MAX);                
        userChange = getUserInt(CHANGE_MIN, CHANGE_MAX);                // (1, 95) -> the range min and max of whats valid
        if(userChange == USER_INPUT_ERROR)                              // Exit program code: 1
        {
            printf("User entered an invalid change amount.");
            pauseExitProgram();
            return 1;                                       
        }

        /** [Step 2] - Get user input for currency selection
         *      a. Display the selection menu, then prompt the user to enter an integer value between (1-3) inclusive.
         *      b. Get the user input and filter it for validity, returning a value to main.
         *      c. If the user input fails, then quit program.
         *      d. If the user input is valid we continue with program.
         */
        printf("%s", MENUSELECTION_S);                                      
        printf("Please enter currency type (%d-%d): ", SELECTION_MIN, SELECTION_MAX);                       
        userSelection = getUserInt(SELECTION_MIN, SELECTION_MAX) - 1;   // Range min and max: (1, 3)  | -1 because array index starts at 0;
        if(userSelection + 1 == USER_INPUT_ERROR)                       // Exit program code: 2
        {
            printf("User entered an invalid currency type selection.");
            pauseExitProgram();
            return 2;  
        }

        /** [Step 3] - Display correct amount of change
         *      a. Get the correct array size based on the valid currency selection made in [Step 2]. 
         *      b. Display the correct change allocation for the change inserted in [Step 1].
         */
        arraySize = coinsArraySizes[userSelection];
        displayChange(userChange, coinsArray[userSelection], arraySize, CURRENCYTYPE_S[userSelection]);  
        printf("\n\nPress enter to continue...");
        getchar();

        /** [Step 4] - Ask user to quit/try again
         *      a. Display exit selection menu, prompt user to enter an integer value between 0 and 1 inclusive
         *      b. Exit/continue program based on selection.
         */
        printf("\nKeys: \n[0] - Exit program\n[1] - Try again \n");
        printf("Would you like to test another change amount or quit program?\n");
        printf("Selection: ");
        exitProgram = getUserInt(0, 1);
        if(!exitProgram)
            exitProgram = USER_INPUT_ERROR;
    } while (exitProgram != USER_INPUT_ERROR);

    // Exit
    pauseExitProgram();
    return 0;
}