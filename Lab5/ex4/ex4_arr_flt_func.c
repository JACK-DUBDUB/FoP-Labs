//

#include <stdio.h>
#include "ex4_arr_flt_func.h"

float getSalaries()
{
    float salaryInput = 0.0;
    if(scanf("%f", &salaryInput) != 1) {
        printf("Cannot insert a non-numeric character.\n");
        return salaryInput = USER_INPUT_ERROR;
    }
       
    if(getchar() != '\n') {
        printf("User inserted a numeric character with a non-numeric character.\n");
        while (getchar() != '\n');
        return salaryInput = USER_INPUT_ERROR;
        
    }

    if(salaryInput <= 0.0) {
        printf("Cannot insert a negative value.\n");
        return salaryInput = USER_INPUT_ERROR;
    }

    // Passed basic filter
    return salaryInput;
}

void handle_GetSalaries(float salaries[])
{
    for(int i = 0; i < SIZE; i++) {
        printf("\nSalary [%d] amount: ", i + 1);
        salaries[i] = getSalaries();
    }
    return;
}

void handle_PayRise(float salaries[])
{
    for(int i = 0; i < SIZE; i++) {
         if(salaries[i] != USER_INPUT_ERROR) {
            salaries[i] *= PAYRISE;
            printf("\nSalary [%d] after payrise: %.2f\n", i + 1, salaries[i]);
         }
    }
}