//
//  IterationSelection.c
//
//
//  Created by Robert Herne on 6/3/2026.
//

#include <stdio.h>

int main()
{
    printf("All even numbers between 0 and 100:\n");
    
    for (int i = 0; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
