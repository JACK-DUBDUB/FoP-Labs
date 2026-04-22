#include <stdio.h>
#include <ctype.h>
#include "ex5_salaries_func.h"
#include "..\LAB_5_LIB.h"

// ---- salaries ---- 

void handle_readSalaries(float salaries[], const int salary_count)
{
    int index = 0; 
    printf("-------- Get Salaries --------\n\n");
    printf("Enter a positive numeric value for up to %i employee salaries.", salary_count);

    do 
    {
        printf("\nEmployee [%d] salary amount: $ ", index + 1);

        if(read_userFloat(&salaries[index])){
            index++;
        } 

    } while (index != salary_count);

    clear_input_buffer();
    return;
}

// ---- read user float ----

bool read_userFloat(float *out_value)
{
    if(read_float(out_value) != true) {
        printf("\nUser did not enter a numeric value.\n");
        return false;
    }

    if(*out_value < 0) {
        printf("\nUser did not enter a positive float value.\n");
        return false;
    } 
    return true;  
}


// ---- min max ----

void handle_getSalaryMinMax(float salaries[], const int salary_count) 
{
    int min = 0, max = 0;
    
    get_salaryMinMax(salaries, salary_count, &min, &max);

    printf("\n-------- Minimum and Maximum --------\n\n");
    printf("Lowest employee salary:  Employee [%d]: $ %.2f\n", min + 1, salaries[min]);
    printf("Highest employee salary: Employee [%d]: $ %.2f\n\n", max + 1, salaries[max]);
    
    program_status_pause(CONTINUE);
    return;
}

void get_salaryMinMax(float salaries[], const int salary_count, int *min, int *max)
{
    for (int i = 0; i < salary_count; i++)
    {
        if(salaries[*max] < salaries[i])
            *max = i;
        
        if(salaries[*min] > salaries[i])
            *min = i;
    }
    return;
}

// ---- average ----

void handle_getSalaryAverage(float salaries[], const int salary_count)
{
    float salary_sum = 0;
    float salary_average = get_salaryAverage(salaries, salary_count, &salary_sum );

    printf("\n-------- Average Of Salaries --------\n\n");
    printf("The total number of salaries: %i\n", salary_count);
    printf("The total sum of salaries: %.2f\n", salary_sum);
    printf("The average salary is: $ %.2f\n\n", salary_average );

    program_status_pause(CONTINUE);
    return;
}

float get_salaryAverage(float salaries[], const int salary_count, float *salary_sum)
{
    for (int i = 0; i < salary_count; i++)
    {
        *salary_sum += salaries[i];
    }
    return *salary_sum / salary_count; // Average
}

// ---- search ----

void handle_getEmployeeSalaries(float salaries[], const int salary_count)
{
    bool quit_program = false;
    do {
        get_employeeSalaries(salaries, salary_count);
        quit_program = read_quitSearch();
    } while (!quit_program);
    return;
}



void get_employeeSalaries(float salaries[], const int salary_count)
{
    printf("\n-------- Search And Count Salaries --------\n\n");
    printf("Enter a salary search value to find all employee salaries below it.\n");
    printf("Enter a search value: ");
    float search_value = 0;
    if(read_userFloat(&search_value)) {

        int employee_count = 0; 
        for(int i = 0; i < salary_count; i++) 
        {
            if(salaries[i] < search_value) {
                printf("Employee [%d] salary: $%.2f\n", i + 1, salaries[i]);
                employee_count++;
            }
        }

        printf("\nNumber of employee salaries below $%.2f : %d \n", search_value, employee_count);
        clear_input_buffer();
    }
    else {
        printf("\nUser did not enter a valid float value\n\n");
    }
    program_status_pause(CONTINUE);
    return;
}

bool read_quitSearch()
{
    printf("\n-------- Do you wish to exit search? --------");
    printf("\nPlease enter one of the following character options:");
    printf("\n '%c' - Retry search", SEARCH_RETRY);
    printf("\n '%c' - Quit search", SEARCH_QUIT);
    char selection = '\0';
    do{
        printf("\n\nPlease enter an option: ");
        read_char(&selection);
        switch (toupper(selection)) 
        {
            case SEARCH_QUIT: clear_input_buffer(); return true;
            case SEARCH_RETRY: clear_input_buffer(); return false;
            default: break;
        }
        printf("\nUser did not enter a valid character");
    } while(1);
}