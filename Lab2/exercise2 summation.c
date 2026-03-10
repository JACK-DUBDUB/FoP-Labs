/** 
 * 4/03/2026
 * Jack du boulay - 32712899 
 * Basic program - computes the summation of 3 floats - received by user input
 * Does not validate the numerical inputs (yet)
 * 
 * to compile -> gcc 'filename.c' -o 'filename'
 * to run -> .\filename
*/

// Libraries
#include <stdio.h> 

// Declare functions
float computeSum(float a, float b, float c);

#pragma region MAIN 
int main () 
{
    // Variables
    float a, b, c, result;     

    // Display first instruction
    // Get user input for first value
    printf("Enter the first no: ");  
    scanf("%f*c", &a);                    // This does not validate the input

    // Display second instruction
    // Get user input for second value.
    printf("Enter the second no: "); 
    scanf("%f*c", &b);                

    // Display third instruction
    // Get user input for third value.
    printf("Enter the third no: "); 
    scanf("%f*c", &c);         

    // computes the summation of the 3 values a, b, c.
    // Displays the result
    result = computeSum(a, b, c);
    printf("The summation of values [%f, %f, %f] \nResult: %f\n", a, b, c, result);

    // Halts program so it doesn't autoclose immediately
    printf("Press any key to exit program:"); 
    getchar();
    getchar();

    return 0;
}
#pragma endregion

float computeSum(float a, float b, float c)
{
    return a + b + c;
}