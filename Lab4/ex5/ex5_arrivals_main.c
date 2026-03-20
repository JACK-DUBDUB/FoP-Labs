

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
    double distanceSpeed[ARRLIMIT] = {0.1, 0.1};    // Distance, Speed

    // Glorious code reuse to get values for both the arrival variable as  distance and speed.
    for (int i = 0; i < LOOPLIMIT; i++)
    {
        printf("\n--------------------------------\n");
        printf("Enter %s (%s): ", KEYWORDS_S[i], UNITS_S[i]);

        // Get arrival
        if (i == 0)
            arrivalTime = getTime(CLOCKDISP_S, KEYWORDS_S[i]);

        /// Get distance, then get speed ///
        else       
            distanceSpeed[i - 1] = getDistanceOrSpeed();

        // 0 Is a valid value -> 0 = 00:00 am that why we use -1
        // As for dist/speed, calculations require divisions of those numbers so distSpeed cannot equal 0 
        if(arrivalTime == -1 || distanceSpeed[i] <= 0)                      
        {
            printf("Not a valid %s.\n\n", KEYWORDS_S[i]);
            pauseExitProgram();
            return 1;
        }
    }

    // Perform calculations
    calculations(arrivalTime, distanceSpeed, CLOCKDISP_S);
    
    // Brief pause before quitting program
    pauseExitProgram();
    return 0;
}