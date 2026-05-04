
#include <stdio.h>

int main()
{
    int some_int = 0;        // Stores value
    int *ptr_si = &some_int; // Stores address

    char arr_char[] = {'a', 'b', 'c', '\0'};
    int *arr_ptrs[10]; 

    const char *my_copy = arr_char;

    while(*my_copy)
    {
        printf("Address: 0x%x\n", *my_copy);
        my_copy++;
    }

    printf("Address: 0x%x\n", ptr_si);  // Hex
    printf("Value: %i\n", *ptr_si);     // Decimal value

    return 0;
}