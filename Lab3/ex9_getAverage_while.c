/**
 * /// DATE ///
 * 17/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 9
 * Program (potentially) gets multiple user inputs of data type integer
 * 
 * 
 * /// ALGORITHM ///
 * 
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
    int max = INT_MIN;
    int min = INT_MAX;
    int sum = 0;
    int counter = 0;
    float average;
    
    // User input variables
    int userInput;


    printf("\nThis program requires multiple numerical inputs from the user.\nTo stop inserting numbers, type in any non-numerical character or type 0, then hit enter.\n\nPlease provide a number: ");
    do
    {
        if(scanf("%d", &userInput) == 1)
        {
            // If user input == 0, terminate program
            if(userInput == 0)
            {
                printf("\nUser chose to quit program.");
                break;
            }

            // Increment counter
            counter++;

            // Get Sum
            sum += userInput;

            // Get max
            if(userInput >= max)
                max = userInput;

            // Get min
            if(userInput <= min)
                min = userInput;

            // Get avrg
            average = (float) sum / counter;
            
            // Display results
            printf("\n\n/// Results ///\nNumber of values provided: %d\nSum total: %d\nMaximum: %d\nMinimum: %d\nAverage: %f\n\n", counter, sum, max, min, average);

            // Display prompt to get next number
            printf("Next number: ");
        }
        else
        {
            printf("\nUser did not enter a valid number.");
            getchar();
            userInput = 0;
        }
    } while (userInput != 0);
    
    pauseExitProgram();

    return 0;
}

#pragma region Functions
void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    getchar();
}
#pragma endregion