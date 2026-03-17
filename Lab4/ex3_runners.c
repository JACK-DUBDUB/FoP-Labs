



// Libraries
#include <stdio.h>

#define LIMIT           4
#define FEETPERMILE     5280
#define FEETPERMETER    3.28084

// Declare functions
void DisplayCalculations(float runnerTimes[]);
float getRunnerTimes();

int main()
{
    float runnerTimes[LIMIT];

    for (int i = 0; i < LIMIT; i++)
    {
        printf("Runner %d\n", i + 1);
        runnerTimes[i] = getRunnerTimes();
        printf("\n");
    }
    
    DisplayCalculations(runnerTimes);

    return 0;
}

float getRunnerTimes()
{
    int minutes;
    float seconds;
    printf("Minutes: ");
    scanf("%d*c", &minutes);

    printf("Seconds: ");
    scanf("%f*c", &seconds);

    return (minutes * 60) + seconds;
}

void DisplayCalculations(float runnerTimes[])
{
    for(int i = 0; i < LIMIT; i++)
    {
        float speedFeet = FEETPERMILE / runnerTimes[i];
        float speedMetres = speedFeet / FEETPERMETER;

        printf("Time (seconds): %f\nSpeed in (feet): %f per second\nSpeed in (meters): %f\n\n", runnerTimes[i], speedFeet, speedMetres);
    }
    return;
}