//
//  IfElseExample.c
//  
//
//  Created by Robert Herne on 6/3/2026.
//

#include <stdio.h>

int main()
{
    int number;
    
    /* Ask the use for the number */
    printf("Please enter a number.\n");
    
    /* Read in the number from the user */
    scanf("%d", &number);
    
    /* Determine whether it is even and give an appropriate response */
    if (number % 2 == 0)
    {
        printf("The number is even.\n");
    }
    else
    {
        printf("The number is odd.\n");
    }
    
    return 0;
}
