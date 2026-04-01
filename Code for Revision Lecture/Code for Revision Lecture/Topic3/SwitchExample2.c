//
//  SwitchExample2.c
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
    switch (response)
    {
    case 'a':
    case 'A':
        printf("You have selected option 1.\n");
        break;
    case 'b':
    case 'B':
        printf("You have selected option 2.\n");
        break;
    case 'c':
    case 'C':
        printf("You have selected option 3.\n");
        break;
    default:
        printf("You haven't selected a valid option.\n");
    }
    
    return 0;
}
