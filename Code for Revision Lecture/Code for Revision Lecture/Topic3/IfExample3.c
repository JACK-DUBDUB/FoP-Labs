//
//  IfExample3.c
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
    if ((response == 'a') || (response == 'A'))
    {
        printf("You have selected option 1.\n");
    }
    else if ((response == 'b') || (response == 'B'))
    {
        printf("You have selected option 2.\n");
    }
    else if ((response == 'c') || (response == 'C'))
    {
        printf("You have selected option 3.\n");
    }
    else
    {
        printf("You haven't selected a valid option.\n");
    }
    
    printf("Thank you for using this exciting program.\n");
    
    return 0;
}
