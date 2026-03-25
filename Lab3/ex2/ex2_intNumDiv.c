/**
 * /// DATE ///
 * 16/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 2
 * Program gets two user input of data type 'int'
 * Program performs calculuation of division of modulus of the user inputs and displays results
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename.c' -o 'filename'
 * To run: .\filename
*/

// Libraries
#include <stdio.h>

// Define
#define LIMIT 2

// Declared functions
void performCalc(int userValues[]);
void displayCalc(int value1, int value2, double divOfInts, int modofInts);
void pauseExitProgram();

int main()
{
    // Variables
    int userValues[LIMIT];

    printf("This program divides two integers given by the user.\nIt provides both the actual division and modulus results.\n");
    for(int i = 0; i < LIMIT; i++ )
    {
        printf("Please enter no.%d: ", i + 1);
        if (scanf("%d", &userValues[i]) != 1) 
        {
            printf("\nYou entered an invalid value. Please enter a valid integer.\n");
            pauseExitProgram();
            return 1;   // Exit program - code 1
        }
    }

    // Check if the second input is equal to 0,     else perform calculation
    if(userValues[1] == 0)
        printf("\nSecond input is not valid. Cannot divide by zero.\n\n");

    else
        performCalc(userValues);

    // Pauses the program 
    pauseExitProgram();
    return 0;
}


#pragma region 
void performCalc(int userValues[])    
{
    double divOfInts  = userValues[0] / (double)userValues[1];
    int modOfInts = userValues[0] % userValues[1];
    displayCalc(userValues[0], userValues[1], divOfInts, modOfInts);
    return;
}

void displayCalc(int value1, int value2, double divOfInts, int modOfInts)
{
    printf("\n/// RESULTS ///\n");
    printf("%d divided by %d equals: %f\n", value1 , value2, divOfInts);
    printf("%d modulus %d equals: %d, remainder: %d\n\n", value1, value2, value1 / value2, modOfInts);
}

void pauseExitProgram()
{
    printf("Press enter to quit...");
    while(getchar() != '\n');
    getchar();
    return;
}
#pragma endregion
