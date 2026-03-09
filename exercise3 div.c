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
float computeDiv(int a, int b);

#pragma region MAIN 
int main () 
{
    // Variables/data types
    int a, b;               // signed int
    float result;     

    // Display first instruction
    // Get user input for first value
    printf("Enter the first no: ");  
    scanf("%d*c", &a);                    // %d integer, &a is the var -> This does not validate the input

    // Display second instruction
    // Get user input for second value.
    printf("Enter the second no: "); 
    scanf("%d*c", &b);                

    // computes the division of the 2 vars [a, b]
    // Displays the result
    result = computeDiv(a, b);
    printf("The division of values [%d by %d] \nResult: %f\n", a, b, result);

    // Ideally I would make an If else statement -> in case theres a divide by zero error...

    // Halts program so it doesn't autoclose immediately
    printf("Press any key to exit program: "); 
    getchar();
    getchar();

    // exited program safely
    return 0;
}
#pragma endregion

float computeDiv(int a, int b)
{
    //float c = (a * 1.0) / (b * 1.0); <- force a float
    return (float) a / b;
}