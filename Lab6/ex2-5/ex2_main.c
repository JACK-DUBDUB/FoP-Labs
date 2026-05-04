/**
 * /// DATE ///
 * 17/04/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 2-5
 * 
 * Programs prompts the user for the number of salaries they wish to enter (between 1 - 100)
 * Program then prompts the user for salary values for number of salaries.
 * Program then displays the min max values of the total salaries
 * Program then displays the average of the salaries
 * Program then prompts the user with a selection menu to select either an option of:
        - 'A' searching all salaries below a search value
        - 'S' searching all salaries equal to the exact search value
        - 'Q' to quit the search
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

    handle_readSalaries(salaries, salary_count);
    handle_getSalaryMinMax(salaries, salary_count);
    handle_getSalaryAverage(salaries, salary_count);
    handle_controlSalariesSearch(salaries, salary_count);   

    return 0;
}