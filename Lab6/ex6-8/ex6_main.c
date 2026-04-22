/**
 * /// DATE ///
 * 17/04/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 6-8
 * 
 *
 * 
 * /// Compile and Run
 * Compile: gcc .\ex6_main.c .\ex6_func.c ..\LAB_6_LIB.c -o ex6
 * Run: .\ex6.exe
 * 
 */

//#include <stdbool.h>
//#include <stdio.h>
#include "ex6_func.h"

int main ()
{
    const int string_length = handle_readStringLength();
    char user_string[string_length];

    // Original string case
    handle_readUserString(user_string, string_length);
    handle_displayStrings(user_string, ORIGINAL);

    // Convert string to lower case
    handle_convertToLower(user_string);
    handle_displayStrings(user_string, LOWER_CASE_ONLY);

    // Vowels only string
    char vowel_string[handle_countVowels(user_string)];
    handle_insertVowels(user_string, vowel_string);
    handle_displayStrings(vowel_string, VOWEL_ONLY);
    
    // Search string -> Question Ex8: Does exercise 8 require the user to input a completely new string using the same length?
    handle_searchUserString(user_string);
    

    return 0;
}