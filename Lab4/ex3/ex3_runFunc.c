
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

void calculateRunnerTimes(double runnerTimes[])
{
    printf("\n/// RESULTS ///\n");
    for(int i = 0; i < LIMIT; i++)
    {
        double speedFeet = FEETPERMILE / runnerTimes[i];
        double speedMeters = speedFeet / FEETPERMETER;
        displayRunnertimes(speedFeet, speedMeters, runnerTimes[i], i + 1);
    }
    return;
}

void displayRunnertimes(double speedFeet, double speedMeters, double runnerTime, int index)
{
    printf("--- Runner %d ---\n", index);
    printf("Time (seconds): %f\nSpeed in (feet): %f per second\nSpeed in (meters): %f per second\n\n", runnerTime, speedFeet, speedMeters);
    return;
}

void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    return;
}