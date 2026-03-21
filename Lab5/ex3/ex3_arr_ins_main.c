








#include <stdio.h>

#define SIZE 20

int main()
{
    // Declaration of arrays (values at elements unassigned)
    int numbers[SIZE];
    int half = SIZE / 2;

    numbers[0] = 10, numbers[half] = 50, numbers[SIZE] = 35;

    printf("Value at element %d: %d\n", 0, numbers[0]);
    printf("Value at element %d: %d\n", half, numbers[half]);
    printf("Value at element %d: %d\n", SIZE, numbers[0]);

    return 0;
}


