#include <stdlib.h>

#ifndef PROGRAM_HEADER
#define PROGRAM_HEADER


#define NAME_MAX 64
#define LINE_BUFFER_MAX 256
#define EMPLOYEE_MAX 10


typedef struct
{
    char name[NAME_MAX];
    int age;
    float wage; 
} Employee;

typedef struct
{
    Employee *data;
    int count;
    int max;
} EmployeeArray;



int program_argCheck(const int argc, char *argv[]);

int strcmp_insensitive(const char *string1, const char *string2);

int file_read(EmployeeArray *emparr, const char *fname);

void display_employee(Employee emp);

void handle_menu(const EmployeeArray emparr);

int read_intInRange(const int min, const int max);

void search_employees(const EmployeeArray emparr);

int file_write(const EmployeeArray *emparr, const char *fname);

#endif










