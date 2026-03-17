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
 * Can potentially gets multiple user inputs of data type integer
 * Can quit loop when the user enters '0' or any non-numerical character, to quit the program
 * Validates the user inputs and stores them into an integer array
 * Displays all the numbers the user entered.
 * Displays calculations of sum, smallest, largest, average values
 * 
 * /// ALGORITHM ///
 * 1. Display instructions 
 * 2. LOOP START
 *      3. Prompt user for first number input
 *      4. Validate user input
 *          A. If it's a value between and inclusive of 1-9, then it is valid and is stored in an array.
 *          B. Else if it's not a valid value, exit program
 *      5. Display the number's the user has inserted into the array
 *      6. Perform and display the calculations of the summation, min, max and average of the values stored in the array.
 *      7. Display next input instruction.
 * 8. LOOP END
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename.c' -o 'filename'
 * To run: .\filename
*/

// Libraries
#include <stdio.h>
#include <limits.h>

// Defined constants
#define LIMIT 100 

// Declared functions
void displayUserNumbers(int numbers[], int counter);
void displayCalculations(int numbers[], int counter);
void invalidClearBuffer();
void pauseExitProgram();

int main()
{
    int numbers[LIMIT];
    int counter;

    // For some arbitrary LIMIT prompt the user to enter a number until they decide to quit by typing 0 or a non-numeric character.
    printf("\nThis program requires multiple numerical inputs from the user.\nTo quit the program, type in '0' then hit enter.\n\nPlease provide a number: ");
    for(counter = 0; counter < LIMIT; counter++)
    {
        // If the first value is not numeric, this means the value is invalid.
        if(scanf("%d", &numbers[counter]) != 1)
        {
            invalidClearBuffer();
            break;
        }

        // If the first char isn't '\n', that means there are other chars remaining in the input buffer making it an invalid input...
        if(getchar() != '\n')                       
        {                                          
            invalidClearBuffer();
            break;
        }

        // User chose to quit the program
        if(numbers[counter] == 0)                   
        {
            printf("\nUser chose to quit program.");
            break;
        }
        
        // Display the numbers provided + the calculations performed
        // (counter + 1) because the current input value made it through the above if-else statements that are checking for errors.
        displayUserNumbers(numbers, counter + 1);   
        displayCalculations(numbers, counter + 1);

        // If the counter is equal to the LIMIT - 1, the message "next number: " will be displayed without the user being able to insert the next value.
        if(counter != LIMIT - 1)        
            printf("\nNext number: ");
        else
            printf("\nLimit of available values reached.");
    }

    pauseExitProgram();
    return 0;
}

#pragma region Functions
void displayUserNumbers(int numbers[], int counter)
{
    printf("\n/// Results ///\nNumbers provided: ");
    for(int i = 0; i < counter; i++)
    {
        printf(" %d ", numbers[i]);
    }
    return;
}

void displayCalculations(int numbers[], int counter)
{
    int max = INT_MIN;
    int min = INT_MAX;
    int sum = 0;
    float average = 0.0;

    for(int i = 0; i  < counter; i++)
    {
         // Get sum
        sum += numbers[i];

        // Get max
        if(numbers[i] > max)   // Why More than or equal to? -> If the user inserts the value INT_MAX
            max = numbers[i];

        // Get min
        if(numbers[i] < min)
            min = numbers[i];

        // Get average
        if(counter != 0)
            average = (float) sum / counter;
    }

    printf("\nNumber of values provided: %d\nSum total: %d\nMaximum: %d\nMinimum: %d\nAverage: %f\n", counter, sum, max, min, average);
    return;
}

void invalidClearBuffer()
{
    printf("\nUser did not enter a valid number.");
    while (getchar() != '\n');              // Remove all remaining chars in input buffer until '\n' (nextline)
    return;
}

void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    return;
}
#pragma endregion