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
 *
 * 
 * /// Compile and Run
 * gcc '.\ex5_salaries_main.c' '.\ex5_salaries_func.c' '..\LAB_5_LIB.c' -o ex5 
 * .\ex5_salaries.exe
 * 
 */

#include "ex5_salaries_func.h"
#include "..\LAB_8_LIB.h"

int main()
{
    float array[SIZE];
    const int salary_count = sizeof(array) / sizeof(float);

    SalaryArray salaries = {array, salary_count};


    handle_readSalaries(salaries);

    handle_getSalaryMinMax(salaries);

    handle_getSalaryAverage(salaries);

    handle_getEmployeeSalaries(salaries);
    
    // Pause before exit
    program_status_pause(QUIT);
    return 0;
}