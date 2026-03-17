/**
 * /// DATE ///
 * 16/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 4 - Part A & B
 * Program gets a user input of data type 'int'
 * Program goes through a IF-ELSE statement that displays the corresponding day to the number the user had inserted
 * 
 * /// ALGORITHM ///
 * Get speed with a user input of data type integer
 * 
 * If speed is less than 0
 *      Display not valid integer
 * Else If speed less than or equal to 60
 *      Display not speeding
 * Else if speed less than or equal to 65
 *      Display speeding
 *      Issue warning
 * Else if speed less than or equal to 70 
 *      Display speeding
 *      Apply a fine of $80
 * Else if speed less than or equal to 80 
 *      Display speeding
 *      Apply a fine of $150
 * Else if the speed is over 80
 *      Display speeding
 *      Apply a fine of $500
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename.c' -o 'filename'
 * To run: .\filename
*/

// PART B
// Libraries
#include <stdio.h>

// Declared functions
void pauseExitProgram();

int main()
{
    // Constants
    const int speedLevel0 = 60;
    const int speedLevel1 = 65;
    const int speedLevel2 = 70;
    const int speedLevel3 = 80;

    // Input variable
    int userInput;

    // Get user input
    printf("Please insert an integer to validate a speeding fine: ");
    if (scanf("%d", &userInput) != 1) 
    {
        printf("\nUser entered an invalid value. Please enter a valid positive integer.\n");
        pauseExitProgram();
        return 1;   // Exit program code 1
    }

    // Comparison if-else statement
    if (userInput < 0)                  // Less than 0
    {
        printf("\nUser entered an invalid value. Please enter a valid positive integer.\n");
    }
    else if (userInput <= speedLevel0)  // Less than or equal to 60
    {
        printf("\nNot speeding\nNo fine\n");
    }
    else if (userInput <= speedLevel1)  // Less than or equal to 65
    {
        printf("\nSpeeding\nWarning\n");
    }
    else if (userInput <= speedLevel2)  // Less than or equal to 70
    {
        printf("\nSpeeding\n$80 speeding fine applied.\n");
    }
    else if (userInput <= speedLevel3)  // Less than or equal to 80
    {
        printf("\nSpeeding\n$150 speeding fine applied.\n");
    }
    else if (userInput > speedLevel3)   // More than 80
    {
        printf("\nSpeeding\n$500 speeding fine applied.\n");
    }
    
    pauseExitProgram();
    return 0;
}

void pauseExitProgram()
{
    printf("\nPress enter to quit...");
    while(getchar() != '\n');
    getchar();
}