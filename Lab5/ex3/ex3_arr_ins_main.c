








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


