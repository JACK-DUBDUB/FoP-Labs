
// Libraries
#include <stdio.h>
#include "ex3_runFunc.h"

double getRunnerTimes()
{
    int minutes;
    double seconds;
    printf("Minutes: ");
    scanf("%d*c", &minutes);

    printf("Seconds: ");
    scanf("%lf*c", &seconds);

    // Check for input errors
    if(((minutes * 60) + seconds ) <= 0)
        return 0;
    else if (getchar() != '\n')
        return -1;

    return (minutes * 60) + seconds;
}

void DisplayCalculations(double runnerTimes[])
{
    printf("\n/// RESULTS ///\n");
    for(int i = 0; i < LIMIT; i++)
    {
        double speedFeet = FEETPERMILE / runnerTimes[i];
        double speedMetres = speedFeet / FEETPERMETER;
        printf("--- Runner %d ---\n", i + 1);
        printf("Time (seconds): %f\nSpeed in (feet): %f per second\nSpeed in (meters): %f per second\n\n", runnerTimes[i], speedFeet, speedMetres);
    }
    return;
}

void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    return;
}