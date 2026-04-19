/**
 * /// DATE ///
 * 17/04/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 3
 * Initialize an array with a defined size
 * Then insert element values at specified indexes
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\ex3_arr_ins_main.c' '.\ex3_arr_ins_func.c' -o ex3
 * To run: .\ex3
*/

#include "ex3_arr_ins_func.h"

int main()
{
    // Declaration of arrays (values at all elements unassigned)
    int numbers[SIZE];

    // Indexes
    const int max = SIZE - 1;
    const int mid = SIZE / 2;
    const int min = 0;

    // Insert element values
    numbers[min] = 10, numbers[mid] = 50, numbers[max] = 35;

    // Display element values
    displayElementAtIndex(min, numbers[min]);
    displayElementAtIndex(mid, numbers[mid]);
    displayElementAtIndex(max, numbers[max]);
    return 0;
}


