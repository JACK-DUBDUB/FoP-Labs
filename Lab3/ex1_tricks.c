



#include <stdio.h>

int main()
{
    int x = 0, y = 5, z = 5;
    
    // A
    if(z != 0)
        y = 295;
    else
        x = 10;

    printf("Output 1: x = %d, y = %d, z = %d\n", x, y, z);

    // B
    x = 0, y = 5, z = 5;
    if(y + z > 10)
        y = 99;
    z = 8;
    x = z;

    printf("Output 2: x = %d, y = %d, z = %d\n", x, y, z);

    // C
    x = 0, y = 5, z = 5;
    if(x = 1)
    {
        x = x - 3;
        z = z + 3;
    }
    else
        y = 99;
    
    printf("Output 3: x = %d, y = %d, z = %d\n", x, y, z);

    // d
    x = 0, y = 5, z = 5;
    if(x == 1)
    {
        x = x - 3;
        z = z + 3;
    }
    else
        y = 99;
    printf("Output 4: x = %d, y = %d, z = %d\n", x, y, z);
}