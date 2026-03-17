/**
 * /// DATE ///
 * 16/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 7 - Part B
 * Program gets a user input of data type 'char'
 * Program displays the char's int value and it's ascii value
 * Program swaps upper and lower cases with each other. 
 * 
 * /// ALGORITHM ///
 * Get user input of data type 'char'
 *      convert char value to int value
 *      if char is alphabetical, swap upper and lower cases +- 32
 *      display char ascii and int value 
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
    char userInput;

    // Get user input
    printf("Please enter a single character: ");
    if (scanf("%c", &userInput) != 1) 
    {
        printf("\nUser entered an invalid value. Please enter a valid character.\n");
        return 1;   // Exit program code 1
    }

    if(userInput >= 65 && userInput <= 90)          // Swap upper case letters to lower case letters
        userInput += 32;
        
    else if(userInput >= 97 && userInput <= 122)    // Swap lower case letters to upper case letters
        userInput -= 32;

    printf("User input: %c\nASCII value: %d", userInput, (int)userInput);

    return 0;
}