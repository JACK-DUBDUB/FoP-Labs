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
void displayEvenOdd(int input);
int getSelection();

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
            printf("\nUser entered an invalid value. Please enter a valid positive integer.\nQuitting program...\n");
            return 1;   // Exit program code 1
        }

        // Display message even or odd
        displayEvenOdd(userInput);

        // Prompt user to try again
        selection = getSelection();

    } while(selection);   // while selection == 1

    printf("\nUser quit program.\n\n");
    return 0;
}

void displayEvenOdd(int input)
{
    if((input % 2) == 0)
    {
        printf("\nNumber is even");
    }
    else if((input % 2) != 0)
    {
        printf("\nNumber is odd");
    }

    return;
}

int getSelection()
{
    char charSelection;
    getchar(); // consumes leftover \n

    printf("\n\nDo you want to continue and test another number? (Y/N) ");
    if (scanf("%c", &charSelection) != 1) 
    {
        printf("\nUser entered an invalid value.\n");
    }

    if(charSelection == 'Y' || charSelection == 'y')
    {
        printf("\n");
        return 1;   // Try again
    }
    else if(charSelection == 'N' || charSelection == 'n')
    {
        return 0;   // Quit
    }
    else
    {
        printf("\nUser entered an invalid value.\nQuitting program..."); // Quit but because of user stupidity
        return 0;
    }
}