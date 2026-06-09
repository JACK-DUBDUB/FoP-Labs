






#include <stdio.h>
#include <stdlib.h>

// employee_func.h
// #include <stdlib.h>

typedef struct
{
    char name[32];
    int age;
    float salary;
} Employee;

typedef struct
{
    Employee *data;
    int count;
    int max;
} Employee_Wrapper;


int read_firstLine(const char* file_name);
void read_employeeData(const char* file_name, Employee_Wrapper *emps_data);
void display_employeeData(const Employee_Wrapper *emps_data);
void write_employeeData(const char* file_out, const Employee_Wrapper *emps_data);

// main.c

int main()
{
    const char* file_in = "myfile.txt";
    const char* file_out = "outfile.csv";
    int entries = read_firstLine(file_in);

    printf("Employee max: %i\n", entries);

    if (entries < 0)
    {
        return 1;
    }

    Employee *emps = calloc(entries, sizeof(Employee));
    if (emps == NULL)
    {
        return 2;
    }

    Employee_Wrapper emps_data = {emps, 0, entries};

    read_employeeData(file_in, &emps_data);

    display_employeeData(&emps_data);

    write_employeeData(file_out, &emps_data);

    free(emps);

    return 0;
}

// employee_func.c

// #include <stdio>
// #include "employee_func.h"


int read_firstLine(const char* file_name)
{
    FILE *source = fopen(file_name, "r");
    if (source == NULL)
    {
        return -2;
    }

    char buffer[256];

    int size = 0;

    if(fgets(buffer, 256, source) != NULL)
    {
        if(sscanf(buffer, "%i", &size) == 0)
        {
            size = -1;
        }
    }
    fclose(source);
    return size;
}

void read_employeeData(const char* file_name, Employee_Wrapper *emps_data)
{
    FILE *source = fopen(file_name, "r");
    if (source == NULL)
    {
        return;
    }

    char buffer[256];
    int count = 0;

    while(fgets(buffer, 256, source) != NULL)
    {
        if (emps_data->count == emps_data->max) {break;}

        if (sscanf(buffer, "%63s %i %f", emps_data->data[count].name, &emps_data->data[count].age, &emps_data->data[count].salary) == 3)
        {
            emps_data->count++;
            count++;
        }
    }

    fclose(source);

}

void display_employeeData(const Employee_Wrapper *emps_data)
{
    for (int i = 0; i < emps_data->count; i++)
    {
        printf("Employee: %i\n", i+1);
        printf("Name: %s\n", emps_data->data[i].name);
        printf("Age: %i\n", emps_data->data[i].age);
        printf("Salary: %.2f\n\n", emps_data->data[i].salary);
    }
}

void write_employeeData(const char* file_out, const Employee_Wrapper *emps_data)
{
    FILE *output = fopen(file_out, "w");
    if (output == NULL || emps_data->count == 0)
    {
        return;
    }

    for (int i = 0; i < emps_data->count; i++)
    {
        fprintf(output, "%i,%s,%i,%.2f\n", i+1, emps_data->data[i].name, emps_data->data[i].age, emps_data->data[i].salary);
    }
}








