



#include <stdbool.h>
#include "ex6_func.h"




int main ()
{
    const int string_length = handle_readStringLength();
    char user_string[string_length];

    handle_readUserString(user_string, string_length);
    handle_displayStrings(user_string);

    handle_convertToLower(user_string);
    handle_displayStrings(user_string);

    char vowel_string[handle_countVowels(user_string)];
    handle_insertVowels(user_string, vowel_string);
    handle_displayStrings(vowel_string);
    
    handle_searchUserString(user_string);

    return 0;
}