/**
 * /// DATE ///
 * 18/05/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 2-4 LAB 8
 * Basic file IO using a data structure typedef struct <- no memory allocation involved (only stack)
 * If the user did not include their own arguments for the {infile} {outfile}
 *      -> Default files will be used
 * Basic menu and search 
 * Quitting program writes to file.
 *
 * /// Compile and Run
 * gcc main.c src/program.c ..\LAB_8_LIB.c -o ex2 
 * .\ex2.exe
 * 
 */

#include "include/includes.h"

// Continue from Exercise 4 of Lab 9... WAIT WHAT!!?!?

int main (int argc, char *argv[])
{
    Employee employees[EMPLOYEE_MAX];
    EmployeeArray emparr = {employees, 0, sizeof(employees) / sizeof(Employee)}; 
    
    if(program_argCheck(argc, argv))
    {
        return 1;
    }

    file_read(&emparr, argv[1]);

    handle_menu(emparr);

    file_write(&emparr, argv[2]);

    printf("\nPress enter to quit program...");
    getchar();
    return 0;
}


