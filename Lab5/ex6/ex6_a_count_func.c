/**
 * /// Compile and Run
 * gcc '.\ex6_a_count_main.c' '.\ex6_a_count_func.c'  -o ex6_a_count
 * .\ex5_salaries.exe
 */

#include <stdio.h>
#include <ctype.h>
#include "ex6_a_count_func.h"

void getUserString(char *userString, int stringSize) // Pointer to char array
{
    printf("Enter a string: ");

    // fgets(destination, size, FILE* ) // File* is a pointer
    // Where: stdin = standard input, stdout = standard ouput, stderr = stanndard error
    fgets(userString, stringSize, stdin);  // https://www.w3schools.com/c/ref_stdio_fgets.php  <- This one is super important to know ***
    
    return;
}

char getUserChar() // Pointer to char array
{
    char searchVal;
    printf("Enter a char value to search the string: ");
    scanf("%c", &searchVal);

    return searchVal;
}

void searchUserString(char *userString, int stringSize)
{
    int counter = 0;
    char searchVal = getUserChar();

    for(int i = 0; i < stringSize; i++)
    {
        if(toupper(userString[i]) == toupper(searchVal))
            counter++;
        if(userString[i] == '\n' || userString[i] == '\0') // Next line or Null terminator
            break;
    }
    printf("Total '%c's: %d", searchVal, counter);
    return;
}
