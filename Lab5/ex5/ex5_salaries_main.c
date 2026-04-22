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
#include "..\LAB_5_LIB.h"

int main()
{
    float salaries[SIZE];
    const int salary_count = sizeof(salaries) / sizeof(float);
    handle_readSalaries(salaries, salary_count);
    handle_getSalaryMinMax(salaries, salary_count);
    handle_getSalaryAverage(salaries, salary_count);
    handle_getEmployeeSalaries(salaries, salary_count);
    
    // Pause before exit
    program_status_pause(QUIT);
    return 0;
}