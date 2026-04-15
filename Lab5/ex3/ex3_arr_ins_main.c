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
*/








#include <stdio.h>
#include "ex3_arr_ins_func.h"

#define SIZE 20

int main()
{
    // Declaration of arrays (values at all elements unassigned)
    int numbers[SIZE];
    int half = SIZE / 2;

    numbers[0] = 10, numbers[half] = 50, numbers[SIZE] = 35;

    displayElementAtIndex(0, numbers[0]);
    displayElementAtIndex(half, numbers[half]);
    displayElementAtIndex(SIZE, numbers[SIZE]);
    return 0;
}


