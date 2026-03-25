/** 
 * 4/03/2026
 * Jack du boulay - 32712899 
 * Basic program - computes a division of 2 vars - received by user input
 * Does not validate the numerical inputs (yet)
 * 
 * to compile -> gcc 'filename.c' -o 'filename'
 * to run -> .\filename
*/

// Libraries
#include <stdio.h> 

// Declared functions
float computeFloatDiv(int a, int b);
int computeIntDiv(int a, int b);

#pragma region MAIN 
int main () 
{
    // Variables/data types
    int a, b;                               // signed int
    float result;     

    // Display first instruction
    // Get user input for first value
    printf("Enter the first no: ");  
    scanf("%d*c", &a);                      // %d integer, &a is the var -> This does not validate the input

    // Display second instruction
    // Get user input for second value.
    printf("Enter the second no: "); 
    scanf("%d*c", &b);                

    // computes the division of the 2 vars [a, b]
    // Displays the result
    result = computeFloatDiv(a, b);
    printf("The division of values [%d by %d] \nResult: %f\n\n", a, b, result);

    // <- Ideally I would make an If else statement in case theres a divide by zero error...

    // Exercise 3 part B: The extension.
    int resultint = computeIntDiv(a, b);  
    int resultmod = a - (b * resultint);            // I can't use modulus for this exercise - Just why?
    printf("The division of values [%d by %d] \nDivision result: %d\nRemainder: %d\n\n", a, b, resultint, resultmod);

    // Halts program so it doesn't auto-close immediately
    printf("Press any key to exit program: "); 
    getchar();
    getchar();

    // exited program safely
    return 0;
}
#pragma endregion

#pragma region Functions
float computeFloatDiv(int a, int b)
{
    //float c = (a * 1.0) / (b * 1.0); <- force a float
    return (float) a / b;
}

int computeIntDiv(int a, int b)
{
    return a / b;
}
#pragma endregio