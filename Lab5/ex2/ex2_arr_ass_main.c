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
 * Initialize an array with a magic number: 21
 * Then insert element values at specified indexes
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\ex2_arr_ins_main.c' '.\ex2_arr_ins_func.c' -o ex2
 * To run: .\ex2
*/

#include "ex2_arr_ass_func.h"

int main()
{
    // Declaration of array
    int numbers[21];

    // Integers
    int max = (sizeof(numbers) / sizeof(numbers[0]));
    int mid = max / 2;
    int min = 0;

    // Assign element to specified index
    numbers[0] = 10, numbers[mid] = 50, numbers[max] = 35;

    // Display values at indexes
    displayElementAtIndex(0, numbers[0]);
    displayElementAtIndex(mid, numbers[mid]);
    displayElementAtIndex(max, numbers[max]);

    return 0;
}
