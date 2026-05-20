/**
 * /// DATE ///
 * 17/04/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 1
 * Struct "wrapper" for an array <- not dynamic memory allocation
 * Modular program single function
 * Program can receive up to 10 salary values by the user
 * Validates salaries through a filter
 *
 * 
 * /// Compile and Run
 *      gcc .\ex1_main.c .\ex1_func.c ..\LAB_8_LIB.c -o ex1
 * Run
 *      .\ex1.exe
 */

#include "ex1_func.h"
#include "..\LAB_8_LIB.h"

int main()
{
    float array[ARRAY_SIZE];
    SalaryArray salaries = {array, (sizeof(array) / sizeof(float))};

    handle_readSalaries(salaries);

    handle_getSalaryMinMax(salaries);

    handle_getSalaryAverage(salaries);

    handle_getEmployeeSalaries(salaries);
    
    program_status_pause(QUIT);
    return 0;
}