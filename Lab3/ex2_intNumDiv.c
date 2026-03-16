/**
 * /// DATE ///
 * 16/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 2
 * Program gets two user input of data type 'int'
 * Program performs calculuation of division of modulus of the user inputs and displays results
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename.c' -o 'filename'
 * To run: .\filename
*/

// Libraries
#include <stdio.h>

// Declared functions
void performCalc(int int1, int int2);
void pauseExitProgram();

int main()
{
    // Variables
    int usrInt1, usrInt2;

    // FIRST INPUT
    printf("This program divides two integers given by the user.\nIt provides both the actual division and modulus results.\nPlease enter the first value: ");
    if (scanf("%d", &usrInt1) != 1) 
    {
        printf("\nYou entered an invalid value. Please enter a valid integer.\n");
        pauseExitProgram();
        getchar();
        return 1;   // Exit program - code 1
    }

    // SECOND INPUT
    printf("Please enter the second value: ");
    if (scanf("%d", &usrInt2) != 1) 
    {
        printf("\nYou entered an invalid value. Please enter a valid integer.\n");
        pauseExitProgram();
        getchar();
        return 2;   // Exit program - code 2
    }

    // Check if the second input is equal to 0,     else perform calculation
    if(usrInt2 == 0)
    {
        printf("\nSecond input is not valid. Cannot divide by zero.\n\n");
    }
    else{
        performCalc(usrInt1, usrInt2);
    }

    // Pauses the program 
    pauseExitProgram();
    return 0;
}


#pragma region 
// Could my variables be named better?
// Yes, but these are just exercises.
void performCalc(int int1, int int2)    
{
    // TECHNICALLY I dont actually need these variables but i did it for clarity sake
    double divOfInts = int1 / (double) int2;
    int modulusOfInts = int1 % int2;
    //printf("\nFirst user input: %d\n",  int1);
    //printf("Second user input: %d\n", int2);
    printf("\n/// RESULTS ///\n");
    printf("%d divided by %d equals: %f\n", int1, int2, divOfInts);
    printf("%d modulus %d equals: %d, remainder: %d\n\n", int1, int2, int1/int2, modulusOfInts);
}

void pauseExitProgram()
{
    printf("Press enter to quit...");
    getchar();
    getchar();
}
#pragma endregion
