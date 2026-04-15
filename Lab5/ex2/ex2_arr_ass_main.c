#include <stdio.h>
#include "ex2_arr_ass_func.h"

int main()
{
    // Declaration of arrays (values at all elements unassigned)
    int numbers[ARRAY_LIMIT];
    int half = ARRAY_LIMIT / 2;

    // Assign element to specified index
    numbers[0] = 10, numbers[half] = 50, numbers[ARRAY_LIMIT] = 35;

    // Display values at indexes
    displayElementAtIndex(0, numbers[0]);
    displayElementAtIndex(half, numbers[half]);
    displayElementAtIndex(ARRAY_LIMIT, numbers[ARRAY_LIMIT]);
    return 0;
}
