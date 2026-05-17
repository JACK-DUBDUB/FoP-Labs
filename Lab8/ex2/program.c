#include "program.h"
#include <stdio.h>

int file_write(const EmployeeArray *emparr, const char *fname)
{
    printf("\nWriting to file: %s\n", fname);

    FILE *fp = fopen(fname, "w");

    if (fp == NULL)
    {
        printf("Could not write to file.\n");
        return 1;
    }

    for (int i = 0; i < emparr->count; i++)
    {
        fprintf(fp, "%s,%i,%.2f\n", emparr->data[i].name, emparr->data[i].age, emparr->data[i].wage);
    }

    printf("Successfully wrote to file: %s\n\n", fname);
    fclose(fp);
    return 0;
}

int file_read(EmployeeArray *emparr, const char *fname)
{
    printf("\nReading file: %s\n", fname);

    FILE *fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("Could not read file.\n");
        return 1;
    }

    int count = 1;
    char buffer[LINE_BUFFER_MAX];
    while(fgets(buffer, 128, fp) && emparr->count < emparr->max)
    {
        if(sscanf(buffer, "%s %i %f", emparr->data[emparr->count].name, &emparr->data[emparr->count].age, &emparr->data[emparr->count].wage) == 3)
        {
            emparr->count++;
        }
        else 
        {
            printf("Could not parse line: %i\n", count);
        }
        count++;
    }
    fclose(fp);
    printf("Successfully read from file: %s\n\n", fname);
    return 0;
}

void display_employee(Employee emp)
{
    printf("\nName: %s\n", emp.name);
    printf("Age:\t%i\n",emp.age);
    printf("Wage:\t%.2f\n\n",  emp.wage);
    return;
}


int read_intInRange(const int min, const int max)
{
    int int_value;
    do 
    {
        printf("Please enter an integer value: ");
        if (scanf("%i", &int_value) && getchar() == '\n')
        {   
            if (int_value >= min && int_value <= max)
            {
                 return int_value;
            }
            printf("User entered an integer out of range (%i - %i)!\n",min, max);
        }
        printf("Please enter a valid value\n\n");
    }while (1);
    return 0;
}


void handle_menu(const EmployeeArray emparr)
{
    int selection;
    do 
    {
        printf("[1] - Search name\n");
        printf("[2] - Exit program\n");
        selection = read_intInRange(1, 2);
        switch (selection) 
        {
            case 1:
                search_employees(emparr);
                break;
            case 2:
                break;
        }

    } while(selection != 2);

    return;
}

void search_employees(const EmployeeArray emparr)
{
    int found = 0;
    char search[LINE_BUFFER_MAX];

    printf("Please enter a name: ");
    read_string(search, LINE_BUFFER_MAX);

    for (int i = 0; i < emparr.count; i++)
    {
        if (string_compare_insensitive(emparr.data[i].name, search) == 0)
        {
            display_employee(emparr.data[i]);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Name: %s\nNot found\n\n",search);
    }
    return;
}

int string_compare_insensitive(const char *string1, const char *string2)
{
    if ((string1 == NULL || string2 == NULL)) 
    {
         return 1;
    }

    if (get_string_length(string1) != get_string_length(string2))
    {
        return 1;
    }

    while (*string1 && *string2)
    {
        if (toupper(*string1) != toupper(*string2)) 
        {
             return 1;
        }
        string1++, string2++;
    }
    return 0;
}
