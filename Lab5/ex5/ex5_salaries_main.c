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

    // Get user salaries
    printf("-------- Get Salaries --------");
    for (int i = 0; i < SIZE; i++)
    {
        printf("\nSalary [%d] amount: $ ", i);
        salaries[i] = getSalaries();
    }

    // Display calculations
    displayMinMax(salaries);
    displayAverage(salaries);
    
    // Pause before exit
    pauseExitProgram();
    return 0;
}