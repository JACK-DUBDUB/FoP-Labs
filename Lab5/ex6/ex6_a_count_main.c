/**
 * /// DATE ///
 * 17/04/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 6
 * Reads a string input from user
 * search and count through the user string for values of 'a'
 * search and count through the user string for values of 'A' and 'a'
 * search and count through the user string for values of a user specified char
 * 
 * /// Compile and Run
 * gcc '.\ex6_count_main.c' '.\ex6_count_func.c'  -o ex6
 * .\ex6.exe
 * 
 */

#include "..\LAB_5_LIB.h"
#include "ex6_a_count_func.h"

int main()
{
    char userString[MAX_MSG_LEN];
    read_userString(userString, MAX_MSG_LEN);
    int stringLength = get_string_length(userString);
    
    handle_searchModules(userString, stringLength);
    program_status_pause(QUIT);
    return 0;
}