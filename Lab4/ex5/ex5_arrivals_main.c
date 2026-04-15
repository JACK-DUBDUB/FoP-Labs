/**
 * /// DATE ///
 * 20/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 5
 * User is prompted for values: {arrivalTime, distance speed}
 * If all inputs are valid -> calculate departure time.
 * 
 * /// ALGORITHM ///
 * 1. LOOP [3] TIMES
 *      a. Prompt user for arrival time
 *      b. Prompt user for distance 
 *      c. Prompt user for speed
 * 2. END LOOP
 * 3. Display departure calculation
 * 4. Close program
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename_main.c' '.\filename_func.c'-o 'filename'
 * To run: .\filename
*/

// Learnt something cool -> for (;;){} is actually a while loop with no condition checking

// Libraries
#include <stdio.h>
#include "ex5_arrivals_func.h"

int main()
{
    // Immutable strings
    const char *CLOCKDISP_S[]   = {"AM", "PM"};
    const char *KEYWORDS_S[]    = {"arrival time", "distance", "speed"};
    const char *UNITS_S[]       = {"24h", "km", "km/h"};

    // User input variable arrays
    int arrivalTime = 0;                            // Arrival Time
    double distance = 0.1;
    double speed = 0.1;

    // Glorious code reuse to get values for both the arrival variable as  distance and speed.
    for (int i = 0; i < LOOPLIMIT; i++)
    {
        printf("\n--------------------------------\n");
        printf("Enter %s (%s): ", KEYWORDS_S[i], UNITS_S[i]);

        // Get arrival
        if (i == 0)
        {
            arrivalTime = getTime(CLOCKDISP_S);
        }

        /// Get distance
        if (i == 1)       
            distance = getDistanceOrSpeed();
        
        // Get speed
        if (i == 2)
            speed = getDistanceOrSpeed();
        
        // 0 Is a valid value -> 0 = 00:00 am that why we use -1
        // As for dist/speed, calculations require divisions of those numbers so distSpeed cannot equal 0 
        if(arrivalTime == -1 || distance <= 0 || speed <= 0)                      
        {
            printf("Not a valid %s.\n\n", KEYWORDS_S[i]);
            pauseExitProgram();
            return 1;
        }
    }

    // Perform calculations
    calculations(arrivalTime, distance, speed, CLOCKDISP_S);
    
    // Brief pause before quitting program
    pauseExitProgram();
    return 0;
}