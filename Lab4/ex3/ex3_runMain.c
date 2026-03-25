/**
 * /// DATE ///
 * 20/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 3
 * Program gets user to insert 4 runner times for their 1 mile run
 * Program displays unit conversions of miles/km and feet/meters
 * 
 * /// ALGORITHM ///
 * 1. LOOP [4] times
 *      a. Get runner time
 *      b. Validate runner time
 * 2. END LOOP
 * 3. Display calculation if runner times are valid.
 * 4. Close program
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename_main.c' '.\filename_func.c'-o 'filename'
 * To run: .\filename
*/

// Libraries
#include <stdio.h>
#include "ex3_runFunc.h"

int main()
{
    double runnerTimes[LIMIT];  // = {232.83, 239.83, 240.03, 256.22};
    int isValid = 1;

    for (int i = 0; i < LIMIT; i++)
    {
        printf("\nRunner %d\n", i + 1);
        runnerTimes[i] = getRunnerTimes(); // Get runner time

        if(runnerTimes[i] == 0)
        {
            printf("\nUser entered non-positive values for Runner %d", i + 1);
            isValid = 0;
            break;
        }
        else if(runnerTimes[i] == -1)
        {
            printf("\nUser entered non-numerical values.");
            isValid = 0;
            break;
        }
    }

    if(!isValid)
        {
            printf("\n\nProgram auto-quit.");
            while(getchar() != '\n');           // Clear input buffer - because clearly the input was wrong...
            pauseExitProgram();
            return 1;
        }
    else
        calculateRunnerTimes(runnerTimes);
    
    pauseExitProgram();
    return 0;
}