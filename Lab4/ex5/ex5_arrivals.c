

// Most poorly written question yet!


// Libraries
#include <stdio.h>

// Defined constants
#define LIMIT 4

// Declared functions
int getTime(int compare);
double getDist();
double getSpeed();

int main()
{
    int arrivalT = 0;

    /// DEPARTURE TIME ///
    printf("Enter departure time (24hr): ");
    int departureT = getTime(arrivalT);
    if (departureT == -1)
    {
        printf("\nNot a valid departure time\n");
        return 1;
    }
    printf("24H time: %d\n", departureT);

    /// DISTANCE ///
    double destinationdist = getDist();
    if (destinationdist == -1)
    {
        printf("\nNot a valid distance\n");
        return 2;
    }
    printf("Distance selected: %f km\n", destinationdist);
    
    /// ARRIVAL TIME ///
    arrivalT = getTime(departureT);
    printf("Enter arrival time (24hr): ");
    if (arrivalT == -1)
        {
        printf("\nNot a valid arrival time\n");
        return 3;
    }   

    //double speed = getSpeed();

    //double arrivalT = distance / speed;

    return 0;
}

int getTime(int compare)
{
    int inputHours, inputMinutes = {0, 0};
    int notation = 0;
    char *clockDis[] = {"AM", "PM"};

    /** What a shit show this part was.
     * Most difficult exercise as of yet.
     * Unless there was an alternative way of going about this, but i'm not knowledgable enough about C
     * 
     * /// How to get values for two different variables in a single scanf /// -> https://stackoverflow.com/a/18832043 
     * My old getDepTime() was too complicated, but it worked, it was just really uneccessary as seen here -> https://github.com/JACK-DUBDUB/FoP-Labs/blob/1faded46f61b7fbbed663ef9187e635c659f349d/Lab4/ex5/ex5_arrivals.c
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
    if (scanf("%2d %2d", &inputHours, &inputMinutes) != 2)   // We are inputting values into two variables so... != 2 :^)  silly billy 
        return -1;
    if (getchar() != '\n')
        return -1;

    // Change to 12 hour time
    if((inputHours - 12) >= 0)
    {
        inputHours -= 12;   // Removing the 24hr time
        notation = 1;       // PM
    }

    // Validate that is within 12 hour clock structure
    if(inputHours < 0 || inputHours > 11 || inputMinutes < 0 || inputMinutes > 59)
        return -1;

    int time24h = ((inputHours + 12) * 100) + inputMinutes;
    
    // Display 12 hour time - I think seeing a leading 0 looks nicer to me.
    if(compare <= time24h)
        printf("The departure time is: %d%d:%d%d %s\n", (inputHours / 10), (inputHours % 10), (inputMinutes / 10), (inputMinutes % 10), clockDis[notation]);
    else if (compare > time24h)
        printf("The arrival time is: %d%d:%d%d %s\n", (inputHours / 10), (inputHours % 10), (inputMinutes / 10), (inputMinutes % 10), clockDis[notation]);

    // Can only return a single number
    return time24h;
}

double getDist()
{
    double dist;
    printf("Distance (km): ");
    if(scanf("%f", &dist) != 1)
        return -1;
    if(getchar() != '\n')
        return -1;
    if(dist < 0)
        return -1;
    
    return dist;
}

double getSpeed()
{
    double speed;
    printf("Speed (km/h): ");
    scanf("%f", &speed);

    return speed;
}
