/**
 * TODO:
 * STRUCTURE CHART
 * ABOUT
 */



// Libraries
#include <stdio.h>

// Defined constants
#define LIMIT           4
#define FEETPERMILE     5280
#define FEETPERMETER    3.28084

// Declare functions
void DisplayCalculations(double runnerTimes[]);
double getRunnerTimes();
void pauseExitProgram();

int main()
{
    double runnerTimes[LIMIT];  // = {232.83, 239.83, 240.03, 256.22};
    int isValid = 1;

    for (int i = 0; i < LIMIT; i++)
    {
        printf("\nRunner %d\n", i + 1);
        runnerTimes[i] = getRunnerTimes();

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
            while(getchar() != '\n');           // Clear input buffer - because clearly the input was wrong
            pauseExitProgram();
            return 1;
        }
    else
        DisplayCalculations(runnerTimes);
    
    pauseExitProgram();
    return 0;
}

#pragma region Functions
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
        printf("Time (seconds): %f\nSpeed in (feet): %f per second\nSpeed in (meters): %f\n\n", runnerTimes[i], speedFeet, speedMetres);
    }
    return;
}

void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    return;
}
#pragma endregion