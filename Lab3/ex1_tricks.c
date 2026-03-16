/**
 * /// DATE ///
 * 16/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 1
 * Syntactic nonsense that is questions B and C
 * Ideally people don't write their code like that....
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename.c' -o 'filename'
 * To run: .\filename
*/

// Libraries
#include <stdio.h>

int main()
{
    // Variables
    int x = 0, y = 5, z = 5;
    
    // A
    if(z != 0)
        y = 295;        // <--
    else
        x = 10;         // X
    printf("Output a: x = %d, y = %d, z = %d\n", x, y, z);

    // B
    x = 0, y = 5, z = 5;
    if(y + z > 10)
        y = 99;         // X  Only the first line with no brackets is processed as part of the if function
        z = 8;          // <-- Tricky, i blame python for this...
    x = z;              // <--
    printf("Output b: x = %d, y = %d, z = %d\n", x, y, z);

    // C
    x = 0, y = 5, z = 5;
    if(x = 1)           // If(any value that does not equal 0) which means -> (x = 1) == 1 
    {
        x = x - 3;      // <--
        z = z + 3;      // <--
    }
    else
        y = 99;         // X

    printf("Output c: x = %d, y = %d, z = %d\n", x, y, z);

    // d
    x = 0, y = 5, z = 5;
    if(x == 1)
    {
        x = x - 3;      // X
        z = z + 3;      // X
    }
    else
        y = 99;         // <--
    printf("Output d: x = %d, y = %d, z = %d\n\n", x, y, z);
}