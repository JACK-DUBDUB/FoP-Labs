/**
 * /// DATE ///
 * 17/04/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 2
 * 
 *
 * 
 * /// Compile and Run
 * Compile: gcc .\ex2_main.c .\ex2_func.c .\ex2_search.c ..\LAB_6_LIB.c -o ex2
 * Run: .\ex2.exe
 * 
 */

#include "ex2_func.h"
#include "ex2_search.h"

int main()
{
    const int salary_count = handle_readSalaryNumber();
    float salaries[salary_count];

    if (salary_count) {
        handle_readSalaries(salaries, salary_count);
        handle_getSalaryMinMax(salaries, salary_count);
        handle_getSalaryAverage(salaries, salary_count);
        handle_controlSalariesSearch(salaries, salary_count);   
    }

    return 0;
}