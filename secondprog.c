/** 
 * 4/03/2026
 * Jack du boulay - 32712899 
 * Basic program - computes the product using two user inputs
 * Does not validate the numerical inputs (yet)
 * 
 * to compile -> gcc 'filename.c' -o 'filename'
 * to run -> .\filename
*/

// Libraries
#include <stdio.h> 

// Declare functions
float computeProduct(float a, float b);

#pragma region MAIN 
int main () 
{
    // Variables
    float a, b, result;     

    // Display first instruction
    // Get user input for first value
    printf("Enter the first no: ");  
    scanf("%f", &a);                

    // Display second instruction
    // Get user input for second value.
    printf("Enter the second no: "); 
    scanf("%f", &b);                

    // computes the product of the two values then displays the result
    result = computeProduct(a, b);
    printf("The product of %f and %f is: %f\n", a, b, result); 

    // Halts program so it doesn't autoclose immediately
    printf("Press any key to exit program:"); 
    getchar(); // consume left over newline
    getchar();

    // Exit
    return 0; 
}
#pragma endregion

float computeProduct(float a, float b)
{
    // Multiply: a x b
    return a * b;               
}


