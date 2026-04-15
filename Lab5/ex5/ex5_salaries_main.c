/**
 * /// DATE ///
 * 15/04/2026 - updated
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 3
 * 
 * Simple insertion of element value to a specified index
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\ex3_arr_ins_main.c' '.\ex3_arr_ins_func.c' -o ex3_arr_ins
 * To run: .\filename
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

void handle_getSalaries(int *valid, float salaries[]);

int main()
{
    // Declaration of arrays (values at elements unassigned)
    float salaries[SIZE];
    int valid = 0;

    // Get user salaries
    handle_getSalaries(&valid, salaries);

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

void handle_getSalaries(int *valid, float salaries[])
{
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
            *valid += 1;
    }
    printf("%i", *valid);
    return;
}