//
//  IfExample1.c
//  
//
//  Created by Robert Herne on 6/3/2026.
//

#include <stdio.h>

int main()
{
    char response;
    
    /* Print menu giving choices */
    printf("You have three choices.\n");
    printf("Enter a for option 1.\n");
    printf("Enter b for option 2.\n");
    printf("Enter c for option 3.\n");
    
    /* Read in user's response */
    scanf("%c", &response);
    
    /* Perform appropriate response */
    if (response == 'a')
    {
        printf("You have selected option 1.\n");
    }
    
    if (response == 'b')
    {
        printf("You have selected option 2.\n");
    }
    
    if (response == 'c')
    {
        printf("You have selected option 3.\n");
    }
    
    return 0;
}
