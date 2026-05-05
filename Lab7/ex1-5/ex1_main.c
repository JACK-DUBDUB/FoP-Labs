//**
// -- Date --
// 05/05/2026
// 
// -- Author --
// Name: Jack du Boulay
// Student ID: 32712899
// 
// -- About Program -- 
// Exercise 1 to 5
// Basic read, create, search program.
//
// What it does:
// The program reads a text file that the user specifies as an argument "ex1.txt"
// The program reads through each line and stores the values into a typedef struct array
// The program then displays each data entry including a name, age, and wage.
// The program then creates a new output file called "output.csv", which converts the data we've read into a .csv file (comma separated values) 
// The program then prompts the user to search the data we've read or quit the program (enter 'q' to quit). 
//
// --  Compile and run ---
// Compile:     gcc .\ex1_main.c .\ex1_func.c ..\LAB_7_LIB.c -o ex1
// Run:         .\ex1.exe ex1.txt                                  
// 
//  */

#include <stdio.h>
#include "ex1_func.h"

int main (int argc, char *argv[])
{
    switch(argc)
    {
        case 1:     printf("ERROR - One argument is expected \n"); return 1;
        case 2:     printf("The argument provided is '%s'\n", argv[1]); break;
        default:    printf("ERROR = Too many arguments provided \n"); return 2;
    }

    file_data_entries user_data[MAX_ENTRY_NUMBER];
    int line_count = handle_readUserFile(argv[1], user_data);

    switch(line_count)
    {
        case -1:    printf("ERROR - Failed to open file in 'r' mode. Make sure its a .txt file \n"); return 3;
        case 0:     printf("ERROR - Could not read lines of file '%s' in 'r' mode \n", argv[1]); return 4;
        default:    break;
    }

    display_userFileData(line_count, user_data);
    handle_createCSVFile(line_count, user_data);
    handle_searchDataByName(line_count, user_data);

    return 0;
}
