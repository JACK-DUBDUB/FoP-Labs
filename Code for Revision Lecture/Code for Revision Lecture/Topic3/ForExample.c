//
//  ForExample.c
//  
//
//  Created by Robert Herne on 6/3/2026.
//

#include <stdio.h>

int main()
{
    double sum = 0;
    
    for (int i = 0; i <= 1000000; i++)
    {
        sum += i;
    }
    
    printf("Sum of all integers between 0 and one million is: %f\n", sum);
}
