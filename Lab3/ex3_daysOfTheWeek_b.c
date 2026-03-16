/**
 * /// DATE ///
 * 16/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 3 - Part B
 * Program gets a user input of data type 'int'
 * Program goes through a switch case statement that displays the corresponding day to the number the user had inserted
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

// Main function
int main(){

    // Char pointer array of days of the week
    char *daysOfTheWeek[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    int userInput;

    // Prompt user with instructions
    printf("Where: Monday = 1 <-> Sunday = 7\n");
    printf("Please enter a number between 1 - 7 to display the corresponding day: ");

    // Get the user int
    if (scanf("%d", &userInput) != 1) 
    {
        printf("\nYou entered an invalid value. Please enter a valid integer.\n");
        pauseExitProgram();
        getchar();
        return 1;
    }

    /* More info on switch cases
     * Theres two ways of doing this switch case optimally
     * One way is to do the FALL-THROUGH case method
     * Example:
     * Switch(someVariable)
     * {
     *      case 1:
     *      case 2:
     *      case ...
     *      case 7: do process
     *      default:
     * }
     * 
     * Another way of doing this is using IF-ELSE inside the switch  
     * And technically this isn't part of standard C, it's actually a GCC extension AFAIA.
     * Example:
     * Switch(someVariable)
     * {
     *      case 0 ... 7:
     *          perform process
     *      default:
     *          perform default process    
     * }
     */

    // For standard C, I'll use the FALL-THROUGH case method (mainly for clarity, that and if someone isn't using GCC, they will still be able to compile it probably...)
    switch (userInput)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7: 
            printDay(userInput, daysOfTheWeek);
            break;
        default:
            printf("User entered: %d which is not a valid integer for this program.\n\n", userInput);
            break;
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
    printf("Press enter to quit...");
    getchar();
    getchar();
}
#pragma endregion