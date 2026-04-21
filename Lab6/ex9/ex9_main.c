

/*



---- Compile and run ----
Compile: gcc ex9_main.c ex9_func.c ..\LAB_6_LIB.c -o ex9
Run: .\ex9.exe


*/

#include <stdbool.h>
#include "ex9_func.h"


int main ()
{
    // Step 1
    const char vowels[] = "aeiou";
    const int string_length = handle_readStringLength();
    char user_string[string_length];

    // Step 2
    handle_readUserString(user_string, string_length);
    handle_displayString(user_string);

    // Stores total vowels found
    int user_string_vowels[sizeof(vowels) - 1] = {};

    // Step 3
    int vowel_count = handle_countVowels(user_string, user_string_vowels);
    char vowel_string[vowel_count];

    handle_insertVowels(user_string, vowel_string);
    handle_displayString(vowel_string);
    
    // Step 6
    handle_displayVowels(user_string, user_string_vowels);

    return 0;
}