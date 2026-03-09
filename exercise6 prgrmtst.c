/**
 * 4/03/2026 
 * Jack du boulay - 32712899 
 * Exercise 6 -> Program Testing
 * Input comparison algorithm, values must be a signed int (min = 32768, max = 32768) -> Can't i use a short for this? 
 * Program reads two integer numbers: X, Y
 * Compare values if they are == or !=
 * Compare values again and report which one is larger
 * 
 * to compile -> gcc 'filename.c' -o 'filename'
 * to run -> .\filename
**/

// Libraries
#include <stdio.h> 

#pragma region MAIN 
int main () 
{
    /// Variables ///
    short uInputX, uInputY;                             // Errr is this cheating??? -> 2^16 bits AKA 2 bytes  -> still a signed integer

    /// Get user values ///
    // Value 1
    printf("Enter first number: ");
    scanf("%hd*c", &uInputX);                           // h -> short, d -> decimal       

    // Value 2
    printf("Enter second number: ");
    scanf("%hd*c", &uInputY); 

    // Simple Compare Algorithm
    if (uInputX == uInputY){
        printf("Both values are equal\n%d = %d\n\n",uInputX, uInputY);
    }
    else if(uInputX > uInputY){
        // If first value larger than second value -> print message
        printf("\nFirst value is larger than second value\n%d > %d\n\n", uInputX, uInputY);
    }
    else{
        //second value larger than first value -> print message
             printf("\nSecond value is larger than first value\n%d < %d\n\n", uInputX, uInputY);
    }

    // Exits program safely
    return 0;
}
#pragma endregion