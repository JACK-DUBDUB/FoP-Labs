#include "program.h"


// Exercise 4 of Lab 9 ??? what?

int main (int argc, char *argv[])
{
    Employee employees[EMPLOYEE_MAX];
    EmployeeArray emparr = {employees, 0, sizeof(employees) / sizeof(Employee)};
    
    if (argc < 2)
    {
        argv[1] = "data.txt";
    }

    if (argc < 3)
    {
        argv[2] = "output.csv";
    }

    file_read(&emparr, argv[1]);

    handle_menu(emparr);

    file_write(&emparr, argv[2]);

    getchar();
    return 0;
}


