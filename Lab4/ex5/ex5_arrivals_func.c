#include <stdio.h>
#include "ex5_arrivals_func.h"

void calculations(int arrivalTime, double dist, double speed, const char *CLOCKDISP_S[])
{
    // Calculations
    // Rounding the double with + 0.5 because converting it to type int truncates the fraction with no rounding 
    int fDepTime  = (int) ((dist / speed) * SIXTY_M) + 0.5;   // Find: Departure TIME (min)     = ((DISTANCE(km) / SPEED(km/h)) x 60 + rounding

    // Convert to 12H clock structure 
    int hrs[ARRLIMIT] = {(arrivalTime /  SIXTY_M), (arrivalTime - fDepTime) / SIXTY_M};    // hours    ->  {arrival, departure} 
    int min[ARRLIMIT] = {(arrivalTime %  SIXTY_M), (arrivalTime - fDepTime) % SIXTY_M};    // minutes      
    int ampm[ARRLIMIT] = {(0), (0)};                                                    // am/pm        
    
    // Get am/pm 
    for (int i = 0; i < ARRLIMIT; i++)
    {
        if (hrs[i] >= TWELVE_H)
        {
            if(hrs[i] > TWELVE_H) // 1300 -> 01:00 PM
                hrs[i] -= TWELVE_H;
            
            ampm[i] = 1;        // 1259 -> 12:59 PM
        } 
    }

    // Display calculations
    printf("\n-------- /// CALCULATIONS /// --------\n");
    printf("For an arrival time of ");
    displayTime(hrs[0], min[0], CLOCKDISP_S[ampm[0]]);
    printf("Travelling a distance of %.3lf km\n", dist);
    printf("At a constant speed of %.3lf km/h\n", speed);
    if ((arrivalTime - fDepTime) < 0) // Arrival time (minutes) - departure time (minutes)
    {
        printf("The departure could not have been on the same day.\n");
        return;
    }
    printf("The approximate departure time was: ");
    displayTime(hrs[1], min[1], CLOCKDISP_S[ampm[1]]);
    return;
}


void displayTime(int h, int m, const char *disp)
{
    // h = hours, m = minutes, disp = am/pm
    printf("%d%d:%d%d %s\n", (h / 10), (h % 10), (m / 10), (m % 10), disp);
    return;
}

void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    return;
}

int getTime(const char *CLOCKDISP_S[], const char *KEYWORDS_S)
{
    int inputHours, inputMinutes = 0;
    int time24h = 0;
    int ampm = 0;       // Where: 0 = am, 1 = pm

    // Get 2 inputs and check if they are valid.
    if (scanf("%2d %2d", &inputHours, &inputMinutes) != 2)   // We are inputting values into two variables so... != 2 :^)
        return -1;
    // If the buffer contains invalid values -> exit
    if (getchar() != '\n')  
        return -1;

    // Validate that the values entered are within 24 hour clock structure
    if(inputHours < 0 || inputHours > 23 || inputMinutes < 0 || inputMinutes > 59)
        return -1;
    
    // Makes all calculatiosn easier to manage
    time24h = (inputHours * SIXTY_M) + inputMinutes;    // <- You guys should reasonably explain why i should return it as its full value ***
    
    // All filters passed. Change value to 12 hour time
    if((inputHours - TWELVE_H) >= 0)
    {
        if((inputHours - TWELVE_H) != 0)    // Why? Because 12 PM does not go to 00:00, it goes 12:00 pm to 12:59 pm
            inputHours -= TWELVE_H;         // Remove the 24hr time

        ampm = 1;                           // Always assign PM if >= 12
    }    
    
    // Display 12 hour time and return 24hr value
    printf("The %s is: ", KEYWORDS_S);              // Ex: The "arrival time" is: "12:30 PM"
    displayTime(inputHours, inputMinutes, CLOCKDISP_S[ampm]);
    return time24h;
}

double getDistanceOrSpeed()
{
    double inputVal = 0.0;
    if(scanf("%lf", &inputVal) != 1)
        return -1;
    if(getchar() != '\n')
        return -1;
    if(inputVal < 0)
        return -1;
    
    return inputVal;
}