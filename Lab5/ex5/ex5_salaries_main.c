








#include <stdio.h>
#include <ctype.h>

#define SIZE 10
#define PAYRISE 1.2

float getSalaries();

int main()
{
    // Declaration of arrays (values at elements unassigned)
    float salaries[SIZE];

    printf("-------- Get Salaries --------");
    for(int i = 0; i < SIZE; i++)
    {
        printf("\nSalary [%d] amount: ", i + 1);
        salaries[i] = getSalaries();
    }

    printf("\n-------- After Pay Rise --------");
    for(int i = 0; i < SIZE; i++)
    {
         if(salaries[i] != -1.0)
         {
            salaries[i] *= PAYRISE;
            printf("\nSalary [%d] after payrise: %.2f\n", i + 1, salaries[i]);
         }
    }

    return 0;
}


float getSalaries()
{
    float salaryInput = 0.0;
    if(scanf("%f", &salaryInput) != 1)
        salaryInput = -1.0;

    if(getchar() != '\n')
        salaryInput = -1.0;

    if(salaryInput <= 0.0)
    {
        salaryInput = -1.0;
        printf("Not a valid value.\n");
    }

    // Passed basic filter
    return salaryInput;
}