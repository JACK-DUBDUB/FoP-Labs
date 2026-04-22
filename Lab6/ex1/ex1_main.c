

#include <stdio.h>

int main()
{
    int x, y, z;
    int *ap;

    x= 10;
    y = 25;

    ap = &x;    // stores address
    *ap = 6;    // Dereferences *ap and modifies the value of x

    // Q1
    // x is assigned a value of 10
    // *ap is declared as a pointer type
    // *ap = &x: now stores the address of x
    // if *ap = 6, then the value at x = 6;
    // Why: because *ap dereferences the pointer to access the variable value of x, directly modifying it. 

    printf("x = %d\n", x);

    // Q2
    // Dereferences pointer, decrements the value of x by 1
    // y is assigned a new value of (5 * 2) = 10
    // Expected print statement: y = 10

    (*ap)--;        // Decrement the value at *ap (-> x = 6) by 1 -> x = 6 - 1 = 5
    y = x * 2;      // x = 5, so 5 * 2 = 10

    printf("y = %d\n", y);

    return 0;
}