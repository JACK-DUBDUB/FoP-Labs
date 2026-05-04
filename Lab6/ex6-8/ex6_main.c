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
 * Program prompts the user to enter an integer value for a string length (1-100)
 * Then the user may enter a string into the stdin input buffer, displaying the exact string back to the user.
 * The program then converts the same string to lower case capitalization and displays the string back to the user
 * Program then prompts the user to enter a character to:
 *          - Enter any alphabetical value to search through the string
 *          - Enter any non=alphabetial value to quit the program
 * 
 * /// Compile and Run
 * Compile: gcc .\ex6_main.c .\ex6_func.c ..\LAB_6_LIB.c -o ex6
 * Run: .\ex6.exe
 * 
 */

#include "ex6_func.h"

int main ()
{
    // Read string length integer
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