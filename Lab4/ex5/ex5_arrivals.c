

// Most poorly written question yet!


// Libraries
#include <stdio.h>

// Defined constants
#define LIMIT 4

// Declared functions
int getDepTime();
double getDist();
double getSpeed();

int main()
{
    int departureT = getDepTime();
    if (departureT == -1)
    {
        printf("\nNot a valid time\n");
        return 1;
    }
    
    printf("24H time: %d", departureT);

    //double distance = getDist();
    //double speed = getSpeed();

    //double arrivalT = distance / speed;

    return 0;
}

int getDepTime()
{
    int inputHours, inputMinutes;
    int notation = 0;
    char *clockDis[] = {"AM", "PM"};
    printf("Enter departure time (24hr): ");

    /** What a shit show this part was.
     * Most difficult exercise as of yet.
     * Unless there was an alternative way of going about this, but i'm not knowledgable enough about C
     * 
     * /// How to get values for two different variables in a single scanf /// -> https://stackoverflow.com/a/18832043 
     * My old way was too cluttered before lord knows how everyone else did this exercise
     * 
     * /// How to get only two digits using scanf /// -> https://stackoverflow.com/a/31630375
     * Tricky, i didn't know it was a thing, but it is!
     * %2d <- takes two digits only.
     * However, it does not reject numbers larger than 2 digits, which means the input buffer may have chars remaining still.
     * 
     * Was also momentarily stuck on the if(scanf()) part but this answer clarified it ->  https://stackoverflow.com/a/16685393
     * int result = ("%2d %2d ", &x, &y); returns a value of 2 if it worked
     * 
     * /// Other neat tricks
     * scanf("%d ", &x);    This actually removes any trailing white spaces 
     * scanf("%d*c", &x);   This actually performs a getchar() but its kind of fkn useless if theres many values still residing in buffer  
     * scanf("%11s", name) where limit = 12, it reads a maxmimum of 11 + the null terminator
     * scanf("%[abcde]", letters); This is a scan set -> any letter than isn't contained in the brackets is not read (a rinky dink REGEX)
     */

    // Get Input and check if it was valid.
    if (scanf("%2d %2d ", &inputHours, &inputMinutes) != 2)   // We are inputting values into two variables so... != 2 :^)  silly billy 
        return -1;
    if (getchar() != '\n')
        return -1;

    // Change to 12 hour time
    if((inputHours - 12) >= 0)
    {
        inputHours -= 12;   // Removing the 24hr time
        notation = 1;       // PM
    }
    
    // Validate
    if(inputHours < 0 || inputHours > 11 || inputMinutes < 0 || inputMinutes > 59)
        return-1;

    // Display 12 hour time
    printf("The departure time is: %d%d:%d%d %s\n", (inputHours / 10), (inputHours % 10), (inputMinutes / 10), (inputHours % 10), clockDis[notation]);

    // Revert back to 24 hour time
    if(notation)
        inputHours += 12;

    // Can only return a single number
    return (inputHours * 100) + inputMinutes;
}

double getDist()
{
    double dist;
    printf("Distance (km): ");
    scanf("%f", &dist);

    return dist;
}

double getSpeed()
{
    double speed;
    printf("Speed (km/h): ");
    scanf("%f", &speed);
}