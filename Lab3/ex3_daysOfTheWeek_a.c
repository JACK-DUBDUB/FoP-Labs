/**
 * /// DATE ///
 * 16/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 3 - Part A
 * Program gets a user input of data type 'int'
 * Program goes through a IF-ELSE statement that displays the corresponding day to the number the user had inserted
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename.c' -o 'filename'
 * To run: .\filename
*/

// Libraries
#include <stdio.h>

// Declared functions
void printDay(int input, char *dotw[]);
void pauseExitProgram();

int main(){

    // Array of pointers --- Days of the week ---
    char *daysOfTheWeek[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int userInput;

    printf("Where: Monday = 1 <-> Sunday = 7\n");
    printf("Please enter a number between (1 - 7) to display the corresponding day: ");

    // Get the user int
    if (scanf("%d", &userInput) == 1) 
    {
        if (userInput >= 1 && userInput <= 7)
        {
            printDay(userInput, daysOfTheWeek);
        }
        else
        {
            printf("\nUser entered: %d which is not a valid integer for this program.\n\n", userInput);
        }
    }
    else
    {
        printf("\nYou entered an invalid value. Please enter a valid integer.\n");
    }

    pauseExitProgram();
    return 0;
}

#pragma region FUNCTIONS
void printDay(int input, char *dotw[])
{
    // Monday = 0 in the array, so if user inputs 1 for monday, then we need to deduct 1 to get 0
    printf("\nUser entered: %d\nCorresponding day: %s\n\n", input, dotw[input - 1]);
    return;
}

void pauseExitProgram()
{
    while(getchar() != '\n');
    printf("Press enter to quit...");
    getchar();
    return;
}
#pragma endregion