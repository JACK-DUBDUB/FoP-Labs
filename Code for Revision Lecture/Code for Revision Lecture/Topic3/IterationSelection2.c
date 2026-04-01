//
//  IterationSelection2.c
//
//
//  Created by Robert Herne on 6/3/2026.
//

#include <stdio.h>

int main()
{
    for (int i = 0; i <= 20; i++)
    {
        // On each line, count up all even numbers to i, but display odd numbers as XX.
        for (int j = 0; j <= i; j++)
        {
            if (j % 2 == 0)
            {
                printf("%d ", j);
            }
            else
            {
                printf("XX ");
            }
        }
        
        // Line is finished, insert a new line.
        printf("\n");
    }
    
    return 0;
}
