

// Most poorly written question yet!


// Libraries
#include <stdio.h>

// Defined constants
#define LIMIT 2
#define TWELVE_H 12

// Declared functions
int getTime(int compare, const char *CLOCKDISP_S[], const char *DEPARR_S);
double getDistanceOrSpeed();

int main()
{
    // Immutable strings
    const char *CLOCKDISP_S[] = {"AM", "PM"};
    const char *DEPARR_S[] = {"departure time", "arrival time", "24hr", "24hr"};    // Unfortunate to duplicate 24hr for this to work // all could go here?
    const char *DSTSPD_S[] = {"distance", "speed", "km", "km/h"};

    // User input variables
    int times[LIMIT] = {0, 0};                  // Departure and Arrival Times
    double distanceSpeed[LIMIT] = {0.0, 0.0};   // Distance and Speed

    // Yes its doable.. all of them could use the same for loop LOL 
    // Glorious code reuse to get time for both departure and arrival variables
    for (int i = 0; i < LIMIT; i++)
    {
        printf("--------------------------------\nEnter %s (%s): ", DEPARR_S[i], DEPARR_S[i + 2]);

        // IF i < 2 get departure and arrival time
        // else get distance and speed (type double)
        times[i] = getTime(times[0], CLOCKDISP_S, DEPARR_S[i]);     // times[0] make sure the comparison is always zero to begin with.
        if(times[i] == -1)                                          // Why -1 and not 0? Because 0 is a valid value as 00:00 am
        {
            printf("Not a valid %s.\n\n", DEPARR_S[i]);
            return 1;
        }
        printf("User entered %s %s: %d\n\n", DEPARR_S[i + 2] ,DEPARR_S[i], times[i]);           // *** can comment this one out
    }

    /// DISTANCE and SPEED ///
    for (int i = 0; i < LIMIT; i++)
    {
        printf("--------------------------------\nEnter %s (%s): ", DSTSPD_S[i], DSTSPD_S[i + 2]); // Example: Enter 'distance' '(km)': 
        distanceSpeed[i] = getDistanceOrSpeed();
        if(distanceSpeed[i] == -1)
        {
            printf("Not a valid %s.\n\n", DSTSPD_S[i]);
            return 2;
        }
        printf("User entered %s: %.3lf %s\n\n", DSTSPD_S[i], distanceSpeed[i], DSTSPD_S[i + 2]);
    }

    return 0;
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
 * scanf("%11s", name) where limit = 12, it reads a maxmimum of 11 + the null terminator
 * scanf("%[abcde]", letters); This is a scan set -> any letter than isn't contained in the brackets is not read (a rinky dink REGEX)
 */

int getTime(int compare, const char *CLOCKDISP_S[], const char *DEPARR_S)
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
    time24h = (inputHours * 100) + inputMinutes;

    // If the comparison value is more than the user inputt time - the first compare is always 0
    if(time24h < compare)
    {
        printf("Same day arrivals only.\n");    // Hard coded, theres no way for time24h to be below compare as we have filtered the value already.
        return -1;
    }
        
    // All filters passed. Change values to 12 hour time
    if((inputHours - TWELVE_H) >= 0)
    {
        if((inputHours - TWELVE_H) != 0)    // Why? Because 12 PM does not go to 00:00 but it goes 12:00 pm to 12:59 pm
            inputHours -= TWELVE_H;         // Remove the 24hr time
        ampm = 1;                           // Always assign PM
    }    
    
    // Display 12 hour time - I think seeing a leading 0 looks nicer to me.
    printf("The %s is: %d%d:%d%d %s\n", DEPARR_S, (inputHours / 10), (inputHours % 10), (inputMinutes / 10), (inputMinutes % 10), CLOCKDISP_S[ampm]);

    // Can only return a single number
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