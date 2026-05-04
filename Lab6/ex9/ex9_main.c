/**
 * /// DATE ///
 * 17/04/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 9
 * Program prompts the user to enter an integer value for a string length (1-100)
 * Then user may enter a string into the stdin input buffer, displaying the exact string back to the user.
 * program then calculates the number of vowels in the string
 * program inserts vowels of the user_string into the vowel_string
 * program displays the vowel_string
 * program then displays the total number of each vowel


---- Compile and run ----
Compile: gcc ex9_main.c ex9_func.c ..\LAB_6_LIB.c -o ex9
Run: .\ex9.exe

*/

#include <stdbool.h>
#include "ex9_func.h"


int main ()
{
    // Step 1 define the vowels and creates an array to store the total number of each vowel
    const char vowels[] = "aeiou";
    int total_vowels[sizeof(vowels) - 1] = {};

    // Step 2 get the string length to define the actual user_string length
    const int string_length = handle_readStringLength();
    char user_string[string_length];
    
    // Step 3 read the string from the user, then display it back to them
    handle_readUserString(user_string, string_length);
    handle_displayStrings(user_string, ORIGINAL_STRING);

    // Step 4 count the number of vowels, storing the number of each vowel into the total_vowels array to keep track of total of each vowel, 
    int vowel_count = handle_countVowels(user_string, total_vowels);
    char vowel_string[vowel_count];

    // Step 5 insert the vowels into the vowel string
    handle_insertVowels(user_string, vowel_string);
    handle_displayStrings(vowel_string, VOWEL_STRING);
    
    // Step 6 display the vowel totals and each vowel's first index
    handle_displayVowels(user_string, vowels, total_vowels);

    return 0;
}