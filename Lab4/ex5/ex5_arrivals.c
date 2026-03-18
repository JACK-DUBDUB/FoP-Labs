

// Most poorly written question yet!


// Libraries
#include <stdio.h>

// Defined constants
#define LIMIT 4

// Declared functions
int getDepTime();
int validator(int input[]);
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
       

    //double distance = getDist();
    //double speed = getSpeed();

    //double arrivalT = distance / speed;

    return 0;
}

int getDepTime()
{
    int inputDepTime;
    printf("Enter departure time (24hr): ");

    // Get Input and check if it was valid.
    if (scanf("%d", &inputDepTime) != 1)
        return -1;
    if (getchar() != '\n')
        return -1;

    // Clock notation: AM = 0, PM = 1
    int notation = 0;
    if (inputDepTime / 100 > 11)
    {
         inputDepTime -= 1200;                  // Half it obviously... make it easier for yourself, jesus
         notation = 1;
    }
       
    // Get each individual digit
    int inheritVal = inputDepTime;
    int validateTime[LIMIT] = {0, 0, 0, 0};     // This will flag if the value's inserted are invalid -> if values were inserted at all?
    int divisor = 1000;                         // This is okay because we do not go past 1
    for (int i = 0; i < LIMIT; i++)
    {
        validateTime[i] = inheritVal / divisor;
        inheritVal = inheritVal % divisor;
        divisor = divisor / 10;
        //printf("%d  ", validateTime[i]);
    }

    // Validate the number
    int isValid = validator(validateTime);
    if (!isValid)
        return -1;

    // Convert to 12hr time
    char *halves[] = {"AM", "PM"};
    printf("\nThe departure time is %d%d:%d%d %s\n", validateTime[0], validateTime[1], validateTime[2], validateTime[3], halves[notation]);

    return inputDepTime;
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


int validator(int input[])
{
    for (int i = 0; i < LIMIT; i++)
    {
        int digit = input[i];
        if(digit < 0 || digit > 9)                      // Any digit
            return 0;
        if (i == 0 && digit > 1)                        // digit 1
            return 0;
        if (i == 1 && input[0] == 1 && digit > 1)       // digit 2
            return 0;
        if (i == 2 && digit > 5)                        // digit 3
            return 0;
    }
    return 1;
}