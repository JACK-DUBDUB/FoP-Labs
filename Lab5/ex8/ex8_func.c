#include "ex8_func.h"
#include <ctype.h>

void handle_convertCaps(char *user_string)
{
    // Based on the custom library function i made for this lab
    // let user_string   -> [a][b][c]
    // *user_string          ^
    // 
    // user_string++
    // 
    // user_string      -> [a][b][c]
    // *user_string            ^

    while(*user_string) // till '\0'
    { 
        if (isupper(*user_string)){
            *user_string = tolower(*user_string) ; // to lower
        }
        else if (islower(*user_string)){
            *user_string = toupper(*user_string);
        }

        user_string++; // Next index
    }
    
    return;
}