#include <stdio.h>

#define INT_ARR_LIMIT 100
#define FLT_ARR_LIMIT 20
#define CHR_ARR_LIMIT 51

int main()
{
    // Declaration of arrays (values at elements unassigned)
    int arrayInt[INT_ARR_LIMIT];
    float arrayFloat[FLT_ARR_LIMIT];
    char arrayChar[CHR_ARR_LIMIT];    // 50 + 1 because the final element must store the null terminator '\0'

    // Expected values:
    // 100 * 4 Bytes = 400
    // 20 * 4 Bytes = 80
    // 51 * 1 Byte = 51

    // Total memory / element memory = number of elements
    unsigned short sizeInt = sizeof(arrayInt) / sizeof(arrayInt[0]);       // 400 / 4 = 100
    unsigned short  sizeFloat = sizeof(arrayFloat) / sizeof(arrayFloat[0]); // 80 / 4 = 20
    unsigned short  sizeChar = sizeof(arrayChar) / sizeof(arrayChar[0]);    // 51 / 1 = 51

    printf("Size of int array: %hi\n", sizeInt);
    printf("Size of float array: %hi\n", sizeFloat);
    printf("Size of char array: %hi\n", sizeChar);

    return 0;
}
