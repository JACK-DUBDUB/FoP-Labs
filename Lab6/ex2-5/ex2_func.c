#include <stdio.h>
#include "ex2_func.h"
#include "..\LAB_6_LIB.h"

// ---- Ex2: Dynamic Allocation ----
int handle_readSalaryNumber()
{
    int input = 0;
    bool valid = false;
    printf("\n-------- Number of salary values --------\n");
    do
    {
        printf("\nPlease insert the number of salaries you wish to enter: ");
        valid  = read_salaryNumber(&input);

    } while(!valid );
    return input;
}


bool read_salaryNumber(int *out_value)
{
    if((read_int(out_value) != true)) {
        printf("\nUser did not enter a numerical value.\n");
        return false;
    }
    if(*out_value <= 0) {
        printf("\nUser did not enter a positive integer.\n");
        return false;
    } 
    else {
        return true;
    }
}

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
    else {
        return true;
    }   
}


// ---- min max ----

void handle_getSalaryMinMax(float salaries[], const int salary_count) 
{
    int min = 0;
    int max = 0;
    
    printf("\n-------- Minimum and Maximum --------\n\n");

    get_salaryMinMax(salaries, salary_count, &min, &max);

    printf("Lowest employee salary:  Employee [%d]: $ %.2f\n", min + 1, salaries[min]);
    printf("Highest employee salary: Employee [%d]: $ %.2f\n\n", max + 1, salaries[max]);
    
    program_status_pause(CONTINUE);
    return;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// why two functions for this??? EX4

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ---- average ----

void handle_getSalaryAverage(float salaries[], const int salary_count)
{
    printf("\n-------- Average Of Salaries --------\n\n");
    
    float salary_sum = 0;
    float salary_average = get_salaryAverage(salaries, salary_count, &salary_sum );

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