

// Libraries
#include <stdio.h>
#include "ex5_arrivals_func.h"

int main()
{
    // Immutable strings
    const char *CLOCKDISP_S[] = {"AM", "PM"};
    const char *KEYWORDS_S[] = {"departure time", "arrival time", "distance", "speed"};
    const char *UNITS_S[] = {"24h", "24h", "km", "km/h"};

    // User input variable arrays
    int times[ARRLIMIT] = {0, 0};                  // Departure and Arrival Times
    double distanceSpeed[ARRLIMIT] = {0.0, 0.0};   // Distance and Speed

    // Glorious code reuse to get time for both departure and arrival variables as well as values for distance and speed.
    for (int i = 0; i < LOOPLIMIT; i++)
    {
        printf("\n--------------------------------\n");
        printf("Enter %s (%s): ", KEYWORDS_S[i], UNITS_S[i]);

        /// Get departure and arrival ///
        if (i < 2)  
            times[i] = getTime(times[0], CLOCKDISP_S, KEYWORDS_S[i]);     // times[0] make sure the comparison is always zero to begin with.
        /// Get distance and speed ///
        else       
            distanceSpeed[i - 2] = getDistanceOrSpeed();

        // Why -1 and not 0? Because 0 is a valid value: 0 = 00:00 am  || Where as 0 distance and 0 speed ***********************
        if(times[i] == -1 || distanceSpeed[i] < 0)                      
        {
            printf("Not a valid %s.\n\n", KEYWORDS_S[i]);
            pauseExitProgram();
            return 1;
        }
    }

    calculations(times, distanceSpeed, CLOCKDISP_S);
    pauseExitProgram();
    return 0;
}