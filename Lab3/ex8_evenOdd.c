/**
 * /// DATE ///
 * 16/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 8 + Extension
 * Program gets a user input of data type 'int'
 * Perform modulus, displaying if the user input is an odd or even number
 * Prompt user if they want to try again, if they do, we loop back to the first step.
 * Else quit program. 
 * 
 * /// ALGORITHM ///
 * Start loop
 *      Get user input positive value 'n' of data type integer
 *      If user did not enter a valid integer, quit the program
 *      If user did input an even number
 *          Display number is even
 *      Else if user input an odd number
 *          Display number is odd
 *      
 *      Prompt user to quit program or start loop again
 *      If user inputs 'y'/'Y'
 *          Go back to start loop
 *      Else if user inputs 'n'/'N'
 * End loop
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename.c' -o 'filename'
 * To run: .\filename
*/

// Libraries
#include <stdio.h>

// Declared functions
int getUserSelection();
void displayEvenOdd(int input);
void pauseExitProgram();

int main()
{
    int userInput;
    int selection;

    // Get user input
    do
    {
        printf("Program displays if the number you have chosen is even or odd.\nPlease insert a positive value integer: ");
        if (scanf("%d", &userInput) != 1) 
        {
            printf("\nUser entered an invalid value. Please enter a valid positive integer.\nQuitting program...\n\n");
            return 1;   // Exit program code 1
        }

        if(getchar() != '\n')
        {
            printf("\nUser entered an invalid value. Please enter a valid positive integer.\nQuitting program...\n\n");
            return 2;   // Exit program code 2
        }

        // Display message even or odd
        displayEvenOdd(userInput);

        // Prompt user to try again
        selection = getUserSelection();

    } while(selection);   // while selection == 1

    pauseExitProgram();
    return 0;
}

#pragma region Functions
int getUserSelection()
{
    char charSelection;

    printf("\n\nDo you want to continue and test another number? (Y/N) ");
    scanf("%c", &charSelection);

    if(getchar() != '\n')
    {
        printf("User entered an invalid value.\n"); // Quit but because of user stupidity
        while(getchar() != '\n');                   // Clear input buffer - user added additional chars...
        return 0;                                   // User quits - undesirable
    }
    else if(charSelection == 'Y' || charSelection == 'y')
    {
        printf("\n");
        return 1;                                   // User tries again
    }
    else if(charSelection == 'N' || charSelection == 'n')
    {
        printf("User chose to quit program.\n");    // Quit because the user selected to
        return 0;                                   // User quits - desirable
    }
    else
    {
        printf("User entered an invalid value.\n"); // Quit but because of user stupidity
        return 0;                                   // User quits - undesirable
    }
}

void displayEvenOdd(int input)
{
    if((input % 2) == 0)
        printf("Number is even");
    else
        printf("Number is odd");

    return;
}

void pauseExitProgram()
{
    printf("\nPress enter to quit...");
    getchar();
    return;
}
#pragma endregion