//
//  NestedLoopExample.c
//  
//
//  Created by Robert Herne on 6/3/2026.
//

#include <stdio.h>

int main()
{
    for (int i = 0; i <= 20; i++)
    {
        // On each line, count up to i.
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", j);
        }
        
        // Line is finished, insert a new line.
        printf("\n");
    }
}
