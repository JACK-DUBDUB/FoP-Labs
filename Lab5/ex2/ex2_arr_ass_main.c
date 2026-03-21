








#include <stdio.h>

#define INT_LIMIT 21

int main()
{
    // Declaration of arrays (values at elements unassigned)
    int numbers[INT_LIMIT];
    int half = INT_LIMIT / 2;

    numbers[0] = 10, numbers[half] = 50, numbers[INT_LIMIT] = 35;

    printf("Value at element %d: %d\n", 0, numbers[0]);
    printf("Value at element %d: %d\n", half, numbers[half]);
    printf("Value at element %d: %d\n", INT_LIMIT, numbers[0]);

    return 0;
}

