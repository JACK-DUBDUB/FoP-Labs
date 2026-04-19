#include <stdio.h>
#include "LAB_5_LIB.h"


#define MY_LIMIT 11

int main()
{
    int stringLength = 0;
    char myString[MY_LIMIT]; 

    printf("Please enter a string: ");
    read_string(myString, sizeof(myString));
    stringLength = get_string_length(myString);

    printf("\nString you provided: '%s'\n", myString);

    program_status_pause(CONTINUE);
    printf("String length: %i\n", stringLength);

    program_status_pause(QUIT);
    return 0;
}