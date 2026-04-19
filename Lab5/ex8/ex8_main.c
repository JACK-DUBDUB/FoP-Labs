/**
 * /// DATE ///
 * 17/04/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 *  
 * /// ABOUT PROGRAM ///
 * Exercise 8
 * Reads A string value from the user
 * Replaces all letters of the string with their inverse capitalization
 * Displays the before and after of the letter replacement
 * 
 * /// Compile and Run
 * gcc '.\ex8_main.c' '.\ex8_func.c' ..\LAB_5_LIB.c  -o ex8
 * .\ex8.exe
 */

#include "../LAB_5_LIB.h"
#include "ex8_func.h"
#include <stdio.h>

int main ()
{
    char userString[STRING_LIMIT];

    // Read string
    printf("Please enter a string (LIMIT: %i): ", STRING_LIMIT);
    read_string(userString, STRING_LIMIT);

    // Display before and after conversion
    printf("String (before): %s\n", userString);
    handle_convertCaps(userString);
    printf("String  (after): %s\n", userString);

    program_status_pause(QUIT);
    return 0;
}