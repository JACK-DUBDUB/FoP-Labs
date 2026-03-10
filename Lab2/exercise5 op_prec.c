/** 
 * 4/03/2026 
 * Jack du boulay - 32712899 
 * Basic program - Proof of operator precedence using expressions with and without parenthesis 
 * 
 * to compile -> gcc 'filename.c' -o 'filename'
 * to run -> .\filename
*/

// Libraries
#include <stdio.h> 

// Declared functions: 
void printMessage(float *xprs_wo_prnths, float *xprs_w_prnths, int *ex_count);
// It has been brought to my attention that i don't need pointers for xprs_w or xprs_wo as the values aren't being altered.
// If the function only reads the var, then passing the var is adequate.
// If the function modifies the variable, then passing the pointer is correct.  
// If i'm passing a larger object such as an array or struct, then passing the pointer is also correct.

#pragma region MAIN 
int main () 
{
    /// Variables ///
    float xprs_wo_prnths, xprs_w_prnths;                        // Expressions without / with parenthesis
    int ex_count = 1;                                           // Exercise counter 

    /// Arithmetic ///
    // Ex.1
    xprs_wo_prnths  = 1 + 3 / 2.0;
    xprs_w_prnths   = (1 + (3 / 2.0));
    printMessage(&xprs_wo_prnths, &xprs_w_prnths, &ex_count);   // values at... -> 

    // Ex.2
    xprs_wo_prnths  = 2 - 3 * 4;
    xprs_w_prnths   = (2 - (3 * 4));
    printMessage(&xprs_wo_prnths, &xprs_w_prnths, &ex_count); 

    // Ex.3
    xprs_wo_prnths  = 2 / 3.0 * 4;
    xprs_w_prnths   = ((2 / 3.0) * 4);
    printMessage(&xprs_wo_prnths, &xprs_w_prnths, &ex_count); 

    // Ex.4
    xprs_wo_prnths  = 2 * 3 / 4.0;
    xprs_w_prnths   = ((2 * 3) / 4.0);
    printMessage(&xprs_wo_prnths, &xprs_w_prnths, &ex_count); 

    // Ex.5
    xprs_wo_prnths  = 2.0 / 3.0 / 4.0;
    xprs_w_prnths   = ((2.0 / 3.0) / 4.0);
    printMessage(&xprs_wo_prnths, &xprs_w_prnths, &ex_count); 

    // Ex.6
    xprs_wo_prnths  = 4.0 / 3.0 * 2.0 / 5.0;
    xprs_w_prnths   = (((4.0 / 3.0) * 2.0) / 5.0);
    printMessage(&xprs_wo_prnths, &xprs_w_prnths, &ex_count); 

    // Ex.7
    xprs_wo_prnths  = 6.0 * 3.0 / 4.0 * 5.0;
    xprs_w_prnths   = (((6.0 * 3.0) / 4.0) * 5.0);
    printMessage(&xprs_wo_prnths, &xprs_w_prnths, &ex_count);

    // Ex.8
    xprs_wo_prnths  = 4 * 3 / 2;
    xprs_w_prnths   = ((4 * 3) / 2);
    printMessage(&xprs_wo_prnths, &xprs_w_prnths, &ex_count);

    // Ex.9
    xprs_wo_prnths  = 2 - 2 / 3 * 2;
    xprs_w_prnths   = (2 - ((2 / 3) * 2));
    printMessage(&xprs_wo_prnths, &xprs_w_prnths, &ex_count);

    // Ex.10
    xprs_wo_prnths  = 2.0 / 3.0 * 4 / 2;
    xprs_w_prnths   = (((2.0 / 3.0) * 4) / 2);
    printMessage(&xprs_wo_prnths, &xprs_w_prnths, &ex_count);

    // Ex.11
    xprs_wo_prnths  = 1 + 2.0 / 3.0 * 4 + 5;
    xprs_w_prnths   = (1 + ((2.0 / 3.0) * 4) + 5);
    printMessage(&xprs_wo_prnths, &xprs_w_prnths, &ex_count);

    // Ex.12
    xprs_wo_prnths  = 5 / 2.0 * 2 + 4 % 3 + 9 - 3;
    xprs_w_prnths   = (((5 / 2.0) * 2) + (4 % 3) + 9 - 3);
    printMessage(&xprs_wo_prnths, &xprs_w_prnths, &ex_count);

    // Halts program so it doesn't auto-close immediately
    printf("Press any key to exit program:"); 
    getchar();

    // Exits program safely
    return 0;
}
#pragma endregion

void printMessage(float *xprs_wo_prnths, float *xprs_w_prnths, int *ex_count)
{
    // Displays message of exercise performed, then increment the counter.
    printf("Ex.%d\nExpression without parenthesis: %f\nExpression with parenthesis: %f\n", *ex_count, *xprs_wo_prnths, *xprs_w_prnths);
    
    // Display Pass/Fail message
    if (*xprs_wo_prnths == *xprs_w_prnths){     // If values are the same -> Display Pass
        printf("Pass\n\n");    
    }
    else{                                       // If values are not same -> Display Fail
        printf("Fail\n\n");                     
    }
    
    // Increment the counter.
    *ex_count += 1; //Can't increment with ex_count++ for some reason -> SOULUTION: you can use (*ex_count++); and that works.
    return;
}