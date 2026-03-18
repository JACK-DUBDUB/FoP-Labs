/**
 * /// DATE ///
 * 17/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Can potentially gets multiple user inputs of data type integer
 * Can quit loop when the user enters '0' or any non-numerical character, to quit the program
 * Validates the user inputs only, it only calculates the sum of all inputs.
 * Displays calculations of sum, smallest, largest, average values
 * 
 * 
 * /// ALGORITHM ///
 * 1. Display instructions 
 * 2. LOOP START
 *      3. Prompt user for first number input
 *      4. Validate user input
 *          A. If it's a value between and inclusive of 1-9, then it is valid, and is added to the sum
 *          B. Else if it's not a valid value, exit program
 *      5. Perform and display the calculations of the summation, min, max and average of the values
 *      6. Display next input instruction.
 * 7. LOOP END
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename.c' -o 'filename'
 * To run: .\filename
*/

// Library
#include <stdio.h>
#include <limits.h>

// Declared functions
void pauseExitProgram();

int main()
{
    // Variables
    int isValid;
    int max = INT_MIN;
    int min = INT_MAX;
    int sum = 0;
    int counter = 0;

    float average = 0.0;
    
    // User input variables
    int userInput;

    printf("\nThis program requires multiple numerical inputs from the user.\nTo stop inserting numbers, type in any non-numerical character or type 0, then hit enter.\n\nPlease provide a number: ");
    do
    {
        // If value is valid, isvalid = 1, if value is not valid, isValid = 0
        isValid = scanf("%d", &userInput);

        // If first value in input buffer is a not a '\n' (nextline) value, then input is no longer valid.
        if(getchar() != '\n' || isValid == 0)
        {
            printf("User did not enter a valid number.\n");
            while (getchar() != '\n');                          // Clear input buffer -> it WAS bugging out at the end.
            isValid = 0;  
        }
        /** Input tests:
         * Input 1: a32 ->  'a32\n' is detected in input buffer = invalid = 0     
         * Input 2: 3a2 ->  'a2\n'  is detected in input buffer = invalid = 0
         * Input 3: 32a ->  'a\n'   is detected in input buffer = invalid = 0
         */

        // If user input is 0, they've chosen to terminate program
        // Without && isValid, '0a' would go right through displaying both messages, thanks to the above if statement.
        if(userInput == 0 && isValid)   
        {
            printf("\nUser chose to quit program.");
            isValid = 0;
        }
            
        if(isValid)
        {
            // Increment counter (value required to calculate average)
            counter++;

            // Get Sum
            sum += userInput;

            // Get max
            if(userInput > max)
                max = userInput;

            // Get min
            if(userInput < min)
                min = userInput;

            // Get avrg
            average = (float) sum / counter;
            
            // Display results
            printf("\n\n/// Results ///\nNumber of values provided: %d\nSum total: %d\nMaximum: %d\nMinimum: %d\nAverage: %f\n\n", counter, sum, max, min, average);

            // Display prompt to get next number
            printf("Next number: ");
        }
    } while (isValid);
    
    pauseExitProgram();
    return 0;
}

#pragma region Functions
void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    return;
}
#pragma endregion