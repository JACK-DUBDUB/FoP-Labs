/**
 * /// Compile and Run
 * gcc '.\ex6_a_count_main.c' '.\ex6_a_count_func.c'  -o ex6_a_count
 * .\ex6_a_count.exe
 */

#include <stdio.h>
#include "ex6_a_count_func.h"

int main()
{
    char userString[LIMIT]; // Char array ->
    getUserString(userString, sizeof(userString));
    printf("User entered: %s", userString);
    searchUserString(userString, sizeof(userString));
}
