/** 
 * 4/03/2026 
 * Jack du boulay - 32712899 
 * Basic program - swaps 2 variables <- received by user input
 * Does not validate the numerical inputs (yet)
 * 
 * to compile -> gcc 'filename.c' -o 'filename'
 * to run -> .\filename
*/

// Libraries
#include <stdio.h> 

// Declared functions
void computeSwap(int a, int b);       // Performs the swap between the two variables
void displaySwappedValues(int a, int b);

#pragma region MAIN 
int main () 
{
    // Variables/data types
    int a, b;

    // Display first instruction
    // Get user input for first value
    printf("Enter the first int: ");  
    scanf("%d", &a);                    // expects %d integers, &a at the address of a -> This does not validate the input

    // Display second instruction
    // Get user input for second value.
    printf("Enter the second int: "); 
    scanf("%d", &b);                

    // Display what the user has provided
    printf("Values provided: A = %d     B = %d\n", a, b);

    // Perform swap of values and displays the result in the same function.
    // using values at the address of a and b
    computeSwap(a, b);    

    // Halts program so it doesn't auto-close immediately
    printf("Press any key to exit program: "); 
    getchar();
    getchar();

    // exited program safely
    return 0;
}
#pragma endregion

#pragma region Functions
// We don't return anything here - use void
void computeSwap(int a, int b)
{
    // create temporary var c to perform swap
    int c = a;      // value at: a
    a = b;          // value at: a = value at: b
    b = c;          // value at: b = c

    displaySwappedValues(a, b);
    return;
}

void displaySwappedValues(int a, int b)
{
    printf("Post swapped values of A = %d    B = %d\n", a, b);
    return;
}

#pragma endregion