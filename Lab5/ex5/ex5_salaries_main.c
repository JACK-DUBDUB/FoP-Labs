/**
 * /// DATE ///
 * 17/04/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 5
 * Modular program single function
 * Program can receive up to 10 salary values by the user
 * Validates salaries through a filter
 * If any salaries are valid then apply a +20% pay rise to each valid salary
 *
 * 
 * /// Compile and Run
 * gcc '.\ex5_salaries_main.c' '.\ex5_salaries_func.c'  -o ex5_salaries
 * .\ex5_salaries.exe
 * 
 */

#include <stdio.h>
#include "ex5_salaries_func.h"

int main()
{
    float salaries[SIZE];

    if (handle_getSalaries(salaries))
    {
        handle_getMinMax(salaries);
        handle_getAverage(salaries);      
        handle_linearSearch(salaries);
    }
    else{
        printf("\n*** All employee salaries invalid - Quitting program ***\n\n");
    }   

    // Pause before exit
    pauseExitProgram();
    return 0;
}