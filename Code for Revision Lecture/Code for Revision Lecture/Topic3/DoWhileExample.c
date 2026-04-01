//
//  DoWhileExample.c
//  
//
//  Created by Robert Herne on 6/3/2026.
//

#include <stdio.h>

int main()
{
    int n;
    
    do
    {
        printf("Enter a number:   ");
        scanf("%d", &n);
        
        if (n >= 0)
        {
            if (n % 2 == 0)
            {
                printf("The number %d is even.\n", n);
            }
            else
            {
                printf("The number %d is odd.\n", n);
            }
        }
    } while (n >= 0);
}
