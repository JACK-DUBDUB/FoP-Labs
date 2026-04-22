



#include <stdio.h>




int main()
{
    int some_int = 0;        // Stores value
    int *ptr_si = &some_int; // Stores address

    printf("Address: 0x%x\n", ptr_si);  // Hex
    printf("Value: %i\n", *ptr_si);     // Decimal value

    return 0;
}