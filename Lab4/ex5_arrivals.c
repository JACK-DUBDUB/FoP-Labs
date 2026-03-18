

// Most poorly written question yet!


// Libraries
#include <stdio.h>

#define LIMIT 4

// Declared functions
int getDepTime();
int validator(char input[]);
double getDist();
double getSpeed();

int main()
{
    int departureT = getDepTime();
    if (departureT == -1)
        printf("\nNot a valid time\n");

    double distance = getDist();
    double speed = getSpeed();

    double arrivalT = distance / speed;

    return 0;
}


int getDepTime()
{
    char inputDepTime[LIMIT];
    printf("Departure time (24hr): ");
    scanf("%s", inputDepTime); // expecting string

    // Get actual value and validate
    if (!validator(inputDepTime))
        return -1;
    
    int time = 0;
    int mult = 1000;            

    for(int i = 0; i < LIMIT; i++)
    {
        time += inputDepTime[i] * mult;
        mult = mult / 10;   
    }
    
    time = time % 2400;

    printf("\n24hr time: %d\n", time);
    return time;
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

int validator(char input[])
{
    // Absolute values
    for(int i = 0; i < LIMIT; i++)
    {
        input[i] = input -= 48;
    }

    // Comparison
    for (int i = 0; i < LIMIT; i++)
    {
        int digit = input[i];
        printf("%d ", digit);           // <-  Comment this out ***

        if(digit < 0 || digit > 9)                      // Any digit
            return 0;
        if (i == 0 && digit > 2)                        // digit 1
            return 0;
        if (i == 1 && input[0] == 2 && digit > 4 && input[2] > 0 && input[3] > 0)   // digit 2
            return 0;
        if (i == 2 && input[i - 1] > 3 && digit > 5)    // digit 3
            return 0;
        if (i == 2 && digit > 5)                        // digit 3
            return 0;
    }
    return 1;
}


