#include <stdio.h>
#include <ctype.h>
#include "ex1_func.h"

// ---- salaries ---- 

void handle_readSalaries(SalaryArray salaries)
{
    int index = 0; 
    printf("-------- Get Salaries --------\n\n");
    printf("Enter a positive numeric value for up to %i employee salaries.", salaries.count);

    do 
    {
        printf("\nEmployee [%d] salary amount: $ ", index + 1);

        if(read_userFloat(&salaries.data[index])){
            index++;
        } 

    } while (index != salaries.count);

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

void handle_getSalaryMinMax(SalaryArray salaries) 
{
    int min = 0, max = 0;
    
    get_salaryMinMax(salaries, &min, &max);

    printf("\n-------- Minimum and Maximum --------\n\n");
    printf("Lowest employee salary:  Employee [%d]: $ %.2f\n", min + 1, salaries.data[min]);
    printf("Highest employee salary: Employee [%d]: $ %.2f\n\n", max + 1, salaries.data[max]);
    
    program_status_pause(CONTINUE);
    return;
}

void get_salaryMinMax(SalaryArray salaries, int *min, int *max)
{
    for (int i = 0; i < salaries.count; i++)
    {
        if(salaries.data[*max] < salaries.data[i])
            *max = i;
        
        if(salaries.data[*min] > salaries.data[i])
            *min = i;
    }
    return;
}

// ---- average ----

void handle_getSalaryAverage(SalaryArray salaries)
{
    float salary_sum = 0;
    float salary_average = get_salaryAverage(salaries, &salary_sum );

    printf("\n-------- Average Of Salaries --------\n\n");
    printf("The total number of salaries: %i\n", salaries.count);
    printf("The total sum of salaries: %.2f\n", salary_sum);
    printf("The average salary is: $ %.2f\n\n", salary_average );

    program_status_pause(CONTINUE);
    return;
}

float get_salaryAverage(SalaryArray salaries, float *salary_sum)
{
    for (int i = 0; i < salaries.count; i++)
    {
        *salary_sum += salaries.data[i];
    }
    return *salary_sum / salaries.count; // Average
}

// ---- search ----

void handle_getEmployeeSalaries(SalaryArray salaries)
{
    bool quit_program = false;
    do {
        get_employeeSalaries(salaries);
        quit_program = read_quitSearch();
    } while (!quit_program);
    return;
}



void get_employeeSalaries(SalaryArray salaries)
{
    printf("\n-------- Search And Count Salaries --------\n\n");
    printf("Enter a salary search value to find all employee salaries below it.\n");
    printf("Enter a search value: ");
    float search_value = 0;
    if(read_userFloat(&search_value)) {

        int employee_count = 0; 
        for(int i = 0; i < salaries.count; i++) 
        {
            if(salaries.data[i] < search_value) {
                printf("Employee [%d] salary: $%.2f\n", i + 1, salaries.data[i]);
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