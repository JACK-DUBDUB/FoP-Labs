#include "ex8_func.h"

void handle_convertCaps(char *userString)
{
    if (!userString) {
        return;
    }

    // Base on the custom library function i made for this lab
    // let userString   -> [a][b][c]
    // *userString          ^
    // 
    // userString++
    // 
    // userString       -> [a][b][c]
    // *userString             ^

    while(*userString){ // till '\0'
        if (*userString >= 'A' && *userString <= 'Z'){
            *userString += CONVERT_CAP ; // to lower
        }
        else if (*userString >= 'a' && *userString <= 'z'){
            *userString -= CONVERT_CAP ; // to upper
        }
        userString++; // Next index
    }
    
    return;
}