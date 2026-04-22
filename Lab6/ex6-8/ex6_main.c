



#include <stdbool.h>
#include "ex6_func.h"




int main ()
{
    const int string_length = handle_readStringLength();
    char user_string[string_length];

    // Original case
    handle_readUserString(user_string, string_length);
    handle_displayStrings(user_string);

    // Lower case only
    handle_convertToLower(user_string);
    handle_displayStrings(user_string);

    // Vowels only
    char vowel_string[handle_countVowels(user_string)];
    handle_insertVowels(user_string, vowel_string);
    handle_displayStrings(vowel_string);
    
    // Search
    handle_searchUserString(user_string);
    return 0;
}