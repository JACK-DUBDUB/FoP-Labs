/**
 * /// DATE ///
 * 16/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 6 Part B - extension
 * Program gets a user input of data type 'int'
 * Displays every odd number between 0 and the user's number
 * 
 * /// ALGORITHM ///
 * Get user input positive value 'n' of data type integer
 *      If user did not enter a valid integer, quit the program
 *      If the user entered a negative value, prompt the user again to insert a positive value 'n'
 *
 * Loop from loop 1 to value 'n', incrementing the loop by + 2 until loop value is equal to or more than value 'n'
 *  Display each odd value between and inclusive of loop 1 to value 'n'    
 *  
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename.c' -o 'filename'
 * To run: .\filename
*/

// Libraries
#include <stdio.h>

// Declared functions
void pauseExitProgram();
void displayOddNum(int input);

int main()
{
    int userInput;
    // This while loop will keep prompting the user to insert a non-negative value -> unless the user inserts a non-numerical character.
    printf("Program displays all odd values between 0 and the number you have chosen.");
    do
    {
        // Get user input
        printf("\nPlease insert a positive value (non zero) integer: ");
        if (scanf("%d", &userInput) != 1) 
        {
            printf("\nUser entered an invalid value.\n");
            pauseExitProgram();
            return 1;   // Exit program code 1
        }

        if (userInput < 0)
        {
            printf("\n*** Error ***\nUser entered a negative value.\n");
        }
        else if (userInput == 0)
        {
            printf("\n*** Error ***\nUser entered zero.\n");
        }
    } while (userInput <= 0);

    displayOddNum(userInput);

    pauseExitProgram();
    return 0;
}

#pragma region Functions
void pauseExitProgram()
{
    printf("\nPress enter to quit...");
    while(getchar() != '\n');
    getchar();
    return;
}

void displayOddNum(int input)
{
    printf("\nAll odd values between and inclusive of: 0 to %d\n", input);
    for(int i = 1; i <= input; i += 2 )
    {
        printf(" %d ", i);
    }
    printf("\n");
    return;
}
#pragma endregion