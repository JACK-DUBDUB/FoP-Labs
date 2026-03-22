/**
 * 
 * 
 * 
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
    // Declaration of arrays (values at elements unassigned)
    float salaries[SIZE];
    int valid = 0;

    // Get user salaries
    printf("-------- Get Salaries --------\n\n");
    printf("Enter a positive non-zero value for up to %d employee salaries.\n", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        printf("Employee [%d] salary amount: $ ", i + 1);
        salaries[i] = getUserFloatValue();

        if(salaries[i] == INPUT_ERROR)
            printf("Not a valid value.\n");
        else
            valid++;
    }

    // Display messages and search function
    if (valid)
    {

        displayMinMax(salaries);
        displayAverage(salaries);      
        displaySearchResults(salaries);
    }
    else
        printf("\n*** All employee salaries invalid - Quitting program ***\n\n");

    // Pause before exit
    pauseExitProgram();
    return 0;
}