#include <stdio.h>
#include "ex5_salaries_func.h"

#pragma region User Inputs
float getSalaries()
{
    float salaryInput = 0;
    if(scanf("%f", &salaryInput) != 1)
        salaryInput = INPUT_ERROR;

    if(getchar() != '\n')
    {
        salaryInput = INPUT_ERROR;
        while(getchar() != '\n');
    }
        
    if(salaryInput <= 0)
    {
        salaryInput = INPUT_ERROR;
        printf("Not a valid value.\n");
    }

    // Passed basic filter
    return salaryInput;
}
#pragma endregion

#pragma region Display Functions

 /** "Code reuse"
 * I'm well aware that i could combine both displayMinMax() & displayAverage() functions into a single function.
 * But for clarity, i have decied to separate them so that its obvious what each function is processing, for readability.
 */

void displayMinMax(float salaries[])
{
    int max = 0;      
    int min = 0;
    printf("\n-------- Minimum and Maximum --------\n\n");
    for (int i = 0; i < SIZE; i++)
    {
        if(salaries[i] != INPUT_ERROR)
        {
            if((salaries[max] < salaries[i]))
                max = i;
        
            if((salaries[min] > salaries[i]))
                min = i;
            else if (salaries[min] == INPUT_ERROR)  // Fail safe as element 0 could equal -1
                min = i;
        }
    }

    if (salaries[max] != INPUT_ERROR)
    {
        printf("Highest salary at element [%d]: $ %.2f\n", max, salaries[max]);
        printf("Lowest salary at element [%d]: $ %.2f\n\n", min, salaries[min]);
        return;
    }
    else
        printf("Did not perform min max calculation.\nUser did not enter any valid salaries.\n\n");
    
    return;
}

void displayAverage(float salaries[])
{
    int counter = 0;
    float sum = 0;
    float average = 0;

    printf("\n-------- Average Of Salaries --------\n\n");
    for (int i = 0; i < SIZE; i++)
    {
        if(salaries[i] != INPUT_ERROR)  // No addition of invalid values
        {
            counter++;                  // Required for the division of sum
            sum += salaries[i];
        }
    }

    if(counter > 0) // Protects against Divide by 0 issues
    {
        average = sum / counter;
        printf("Using %d valid salaries.\n", counter);
        printf("The total sum of salaries: %.2f\n", sum);
        printf("The average salary is: $ %.2f\n\n", average);
        return;
    }
    else
        printf("Did not perform average calculation.\nUser did not enter any valid salaries.\n\n");

    return;
}

void pauseExitProgram()
{
    printf("Press enter to exit program...");
    getchar();
    return;
}
#pragma endregion