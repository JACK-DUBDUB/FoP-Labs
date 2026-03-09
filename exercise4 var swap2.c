/** 
 * 4/03/2026
 * Jack du boulay - 32712899 
 * Basic program - swaps 2 variables <- received by user input
 * Uses no additional variables <- arithmetic only
 * Does not validate the numerical inputs (yet)
 * 
 * to compile -> gcc 'filename.c' -o 'filename'
 * to run -> .\filename
*/

// Libraries
#include <stdio.h> 

// Declared functions
void computeSwap(int *a, int *b);       // Performs the swap between the two variables

#pragma region MAIN 
int main () 
{
    // Variables/data types
    int a, b;

    // Display first instruction
    // Get user input for first value
    printf("Enter the first no: ");  
    scanf("%d*c", &a);                    // %d integers, &a is the var address -> This does not validate the input

    // Display second instruction
    // Get user input for second value.
    printf("Enter the second no: "); 
    scanf("%d*c", &b);                

    // Display what the user has provided
    printf("Values provided: A = %d     B = %d\n", a, b);

    // Perform swap of values and displays the result in the same function.
    // print message
    computeSwap(&a, &b);                
    printf("Post swapped values: A = %d    B = %d\n", a, b);

    // Halts program so it doesn't auto-close immediately
    printf("Press any key to exit program: "); 
    getchar();
    getchar();

    // exited program safely
    return 0;
}
#pragma endregion

// We don't return anything here - use void, also no creating of new variables so we have to use the "global" address of the integers
void computeSwap(int *a, int *b) 
{
    // Tricky for sure, nowhere near as intuitive as the other one.
    // Brief example of whats going on: 
    // Where A = 1     B = 
    // a = 1 + 2 = 3
    // b = 3 - 2 = 1 
    // a = 3 - 1 = 2
    *a = *a + *b; 
    *b = *a - *b;
    *a = *a - *b;

    // Could also use the bitwise XOR swap 
    // *a = *a ^ *b;
    // *b = *a ^ *b;
    // *a = *a ^ *b;
    return;
}