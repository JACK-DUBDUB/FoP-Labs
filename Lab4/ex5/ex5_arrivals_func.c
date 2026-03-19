#include <stdio.h>
#include "ex5_arrivals_func.h"

void calculations(int times[], double dstspd[], const char *CLOCKDISP_S[])
{
    // Departure / Arrival times
    int dep = times[0];  
    int arr = times[1];  

    // Calculations
    double fTime  = ((dstspd[0] / dstspd[1]) * SIXITY_M);       // Find: TIME (min)     = ((DISTANCE(km) / SPEED(km/h)) x 60 
    double fSpeed = (dstspd[0] / ((arr - dep) / SIXITY_M));     // Find: SPEED (km/h)   = (DISTANCE(km) / (TIME(min)) / 60)

    // Hours, minutes, am/pm
    int h[] = {(dep / SIXITY_M), (arr /  SIXITY_M), ((dep + (int) fTime) /  SIXITY_M)};
    int m[] = {(dep %  SIXITY_M), (arr %  SIXITY_M), ((dep + (int) fTime) %  SIXITY_M)};
    int ampm[] = {(0), (0), (0)};

    // Get am/pm 
    for (int i = 0; i < 3; i++)
    {
        if (h[i] >= TWELVE_H)
        {
            if(h[i] > TWELVE_H)
                h[i] -= 12;
            ampm[i] = 1;
        } 
    }

    // Display messages
    printf("\n-------- /// CALCULATIONS /// --------\n");
    printf("At a departure time of ");
    displayTime(h[0], m[0], CLOCKDISP_S[ampm[0]]);
    printf("To reach the destination at the designated time of ");
    displayTime(h[1], m[1], CLOCKDISP_S[ampm[1]]);
    printf("Approximate travel speed required to reach destination: %.3lf km/h\n\n", fSpeed);

    printf("At the travel speed of %.3lf km/h provided.\n", dstspd[1]);
    if ((fTime + dep) < TOTAL_M) // (D/S * 60) + (departure time) does not exceed 24:00 or 1440 minutes
    {
        printf("Destination of %.3lf km will be reached by: ", dstspd[0]);
        displayTime(h[2], m[2], CLOCKDISP_S[ampm[2]]);
    }
    else
        printf("Destination will not be reached on the same day.\n");
    
    return;
}

void displayTime(int h, int m, const char *disp)
{
    printf("%d%d:%d%d %s\n", (h / 10), (h % 10), (m / 10), (m % 10), disp);
    return;
}

void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    return;
}

int getTime(int compare, const char *CLOCKDISP_S[], const char *KEYWORDS_S)
{
    int inputHours, inputMinutes = 0;
    int time24h = 0;
    int ampm = 0;                           // Where: 0 = am, 1 = pm

    // Get Input and check if it was valid.
    if (scanf("%2d %2d", &inputHours, &inputMinutes) != 2)   // We are inputting values into two variables so... != 2 :^)  silly billy 
        return -1;
    if (getchar() != '\n')  // Does the input buffer still have values? - if it does its not a valid input.
        return -1;

    // Validate that the values entered are within 24 hour clock structure
    if(inputHours < 0 || inputHours > 23 || inputMinutes < 0 || inputMinutes > 59)
        return -1;
    
    // Makes all calculatiosn easier to manage
    time24h = (inputHours * SIXITY_M) + inputMinutes; 
    
    // If the comparison value is more than the user inputt time - the first compare is always 0
    if(time24h < compare)
    {
        printf("Same day arrivals only.\n"); 
        return -1;
    }
        
    // All filters passed. Change values to 12 hour time
    if((inputHours - TWELVE_H) >= 0)
    {
        if((inputHours - TWELVE_H) != 0)    // Why? Because 12 PM does not go to 00:00 but it goes 12:00 pm to 12:59 pm
            inputHours -= TWELVE_H;         // Remove the 24hr time
        ampm = 1;                           // Always assign PM
    }    
    
    // Display 12 hour time and return 24hr value
    printf("The %s is: ", KEYWORDS_S);
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