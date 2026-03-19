

// Libraries
#include <stdio.h>

// Defined constants
#define ARRLIMIT 2      // User array limit
#define LOOPLIMIT 4     // For loop limit
#define TWELVE_H 12     // 12 hours
#define SIXITY_M 60     // 60 minutes

// Declared functions
int getTime(int compare, const char *CLOCKDISP_S[], const char *KEYWORDS_S);
double getDistanceOrSpeed();
void calculations(int times[], double dstspd[], const char *CLOCKDISP_S[]);
void displayTime(int h, int m, const char *disp);
void pauseExitProgram();

int main()
{
    // Immutable strings
    const char *CLOCKDISP_S[] = {"AM", "PM"};
    const char *KEYWORDS_S[] = {"departure time", "arrival time", "distance", "speed"};
    const char *UNITS_S[] = {"24h", "24h", "km", "km/h"};

    // User input variable arrays
    int times[ARRLIMIT] = {0, 0};                  // Departure and Arrival Times
    double distanceSpeed[ARRLIMIT] = {0.0, 0.0};   // Distance and Speed

    // Glorious code reuse to get time for both departure and arrival variables as well as distance and speed.
    for (int i = 0; i < LOOPLIMIT; i++)
    {
        printf("--------------------------------\n");
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

        // Display what the user entered
        if (i < 2)
            printf("User entered %s %s: %d\n\n",UNITS_S[i] ,KEYWORDS_S[i], times[i]);           // Ex: 2000 
        else
            printf("User entered %s: %.3lf %s\n\n", KEYWORDS_S[i], distanceSpeed[i - 2], UNITS_S[i]);  // Ex: 100 km/h
    }

    calculations(times, distanceSpeed, CLOCKDISP_S);
    pauseExitProgram();
    return 0;
}

void calculations(int times[], double dstspd[], const char *CLOCKDISP_S[])
{
    // Departure / Arrival times
    int dep = times[0];  // ((times[0] / 100) * 60) + ((times[0] % 100) % 10);   // (1500 / 100) = 15  ->  (15 * 60) = 900  -> 900 + ()
    int arr = times[1];  // ((times[1] / 100) * 60) + ((times[1] % 100) % 10);

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
    printf("--------------------------------\n");
    printf("At a departure time of ");
    displayTime(h[0], m[0], CLOCKDISP_S[ampm[0]]);
    printf("To reach the destination at the designated time of ");
    displayTime(h[1], m[1], CLOCKDISP_S[ampm[1]]);
    printf("Approximate travel speed required to reach destination: %.3lf km/h\n\n", fSpeed);
    printf("At the a travel speed of %.3lf km/h provided.\n", dstspd[1]); 
    if ((fTime + dep) < (SIXITY_M * 24))
    {
        printf("Destination will be reached by: ");
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

/** GET TIME ()  
 * What a shit show this part was.
 * Most difficult part of the exercise as of yet.
 * Unless there was an alternative way of going about this, but i'm not knowledgable enough about C
 * 
 * /// How to get values for two different variables in a single scanf /// -> https://stackoverflow.com/a/18832043 
 * My old getDepTime() was too complicated, but it worked, it was just really uneccessary as seen here -> https://github.com/JACK-DUBDUB/FoP-Labs/blob/1faded46f61b7fbbed663ef9187e635c659f349d/Lab4/ex5/ex5_arrivals.c
 * 
 * /// How to get only two digits using scanf /// -> https://stackoverflow.com/a/31630375
 * Tricky, i didn't know it was a thing, but it is!
 * %2d <- takes the first two digits only.
 * However, it does not reject numbers larger than 2 digits, which means the input buffer may have chars remaining still.
 * 
 * Was also momentarily stuck on the if(scanf() != x) part but this answer clarified it ->  https://stackoverflow.com/a/16685393
 * int result = ("%2d %2d ", &x, &y); returns a value of 2 if it worked
 * 
 * /// Other neat scanf tricks
 * scanf("%d ", &x);    This actually removes any trailing white spaces 
 * scanf("%d*c", &x);   This actually performs a getchar() but its kind of fkn useless if theres many values still residing in buffer  
 * scanf("%11s", name) where LOOPlimit = 12, it reads a maxmimum of 11 + the null terminator
 * scanf("%[abcde]", letters); This is a scan set -> any letter than isn't contained in the brackets is not read (a rinky dink REGEX)
 */

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
    
    // Values passed filter -> store it as a four digit value
    time24h = (inputHours * 60) + inputMinutes;     // We are no longer returning the original user input -> 2330 now equals 1410 

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
    printf("The %s is: %d%d:%d%d %s\n", KEYWORDS_S, (inputHours / 10), (inputHours % 10), (inputMinutes / 10), (inputMinutes % 10), CLOCKDISP_S[ampm]);
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