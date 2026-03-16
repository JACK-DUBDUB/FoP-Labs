/**
 * /// DATE ///
 * 17/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 9
 * Program (potentially) gets multiple user inputs of data type integer
 * 
 * 
 * /// ALGORITHM ///
 * Get user input of data type 'char'
 *      convert char value to int value
 *      if char is alphabetical, swap upper and lower cases +- 32
 *      display char ascii and int value 
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename.c' -o 'filename'
 * To run: .\filename
*/



#include <stdio.h>
#include <limits.h>

#define LIMIT 10  

int calcSum(int numbers[], int counter);
int calcMax(int numbers[], int counter);
int calcMin(int numbers[], int counter);
float calcAverage(int sum, int counter);

int main()
{
    int numbers[LIMIT];
    int counter;

    // program should terminate when the user enters the value 0?
    printf("\nThis program requires multiple numerical inputs from the user.\nTo stop inserting numbers, type in any non-numerical character or type 0, then hit enter.\n\nPlease provide a number: ");
    for(counter = 0; counter < LIMIT; counter++)
    {
        if(scanf("%d", &numbers[counter]) != 1)
            break;

        if(numbers[counter] == 0)
            break;

        if(counter != LIMIT - 1)
            printf("Next number: ");
    }

    printf("\nNumbers you provided: ");
    for(int i = 0; i < counter; i++)
    {
        printf(" %d ", numbers[i]);
    }

    int sum = calcSum(numbers, counter);
    int max = calcMax(numbers, counter);
    int min = calcMin(numbers, counter);
    float average = calcAverage(sum, counter);

    printf("\n\n/// Results ///\nTotal: %d\nMaximum: %d\nMinimum: %d\nAverage: %f\n\n", sum, max, min, average);

    return 0;
}

#pragma region Functions
/**
 * Technically, this would be cleaner if i put it all into one function.
 * I'm sure code reuse is possible but alas i'm too tired for this scheisse.
 */

int calcSum(int numbers[], int counter)
{
    int total = 0;
    for(int i = 0; i < counter; i++)
    {
        total +=  numbers[i];
    }
    return total;
}

int calcMax(int numbers[], int counter)
{
    int currentMax = INT_MIN;
    for(int i = 0; i < counter; i++)
    {
        if(numbers[i] > currentMax)
            currentMax = numbers[i];
    }
    return currentMax;
}

int calcMin(int numbers[], int counter)
{
    int currentMin = INT_MAX;
    for(int i = 0; i < counter; i++)
    {
        if(numbers[i] < currentMin)
            currentMin = numbers[i];
    }
    return currentMin;
}

float calcAverage(int sum, int counter)
{
    return (float) sum / counter;
}
#pragma endregion