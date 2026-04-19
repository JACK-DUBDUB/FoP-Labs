/**
 * /// DATE ///
 * 17/04/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 1
 * Initialize arrays with the specified constants
 * Get the size of the arrays
 * Display the size of each array
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\ex1_arr_ins_main.c' -o ex1
 * To run: .\ex1
*/


#include <stdio.h>

#define MAX_PEOPLE      100
#define MAX_STUDENTS    20
#define MAX_MSG_LEN     51  // Char values + Null term

int main()
{
    // Declaration of arrays (values at elements unassigned)
    int agesList[MAX_PEOPLE];
    float marksList[MAX_STUDENTS];
    char messageBuffer[MAX_MSG_LEN];

    // Expected values:
    // 100 * 4 Bytes = 400
    // 20 * 4 Bytes = 80
    // 51 * 1 Byte = 51

    // Total memory / element memory = number of elements
    unsigned short  sizeInt = sizeof(agesList) / sizeof(agesList[0]); // (400 / 4) = 100
    unsigned short  sizeFloat = sizeof(marksList) / sizeof(marksList[0]); // (80 / 4) = 20
    unsigned short  sizeChar = sizeof(messageBuffer) / sizeof(messageBuffer[0]);  // (51 / 1) = 51

    printf("Size of age array: %hi\n", sizeInt);
    printf("Size of student marks array: %hi\n", sizeFloat);
    printf("Size of message array: %hi\n", sizeChar);

    return 0;
}
