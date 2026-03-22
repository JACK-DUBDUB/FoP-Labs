#include <stdio.h>
#include "ex5_salaries_func.h"

#pragma region User Inputs
float getUserFloatValue()
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
        salaryInput = INPUT_ERROR;

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

    printf("Highest employee salary: Employee [%d]: $ %.2f\n", max + 1, salaries[max]);
    printf("Lowest employee salary:  Employee [%d]: $ %.2f\n\n", min + 1, salaries[min]);
    pauseContinueProgram();
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

    // Get average
    average = sum / counter;

    // Display
    printf("Using %d valid salaries.\n", counter);
    printf("The total sum of salaries: %.2f\n", sum);
    printf("The average salary is: $ %.2f\n\n", average);
    pauseContinueProgram();
    return;
}


void displaySearchResults(float salaries[])
{
    int counter;            // Counts number of employees below search value
    float searchVal = 0;
    printf("\n-------- Search Salaries --------\n\n");
    printf("Enter a search value to find all employee salaries below it.\n");
    printf("Enter any: | non-numerical | negative | zero | value to quit search.\n");
    printf("\nEnter a search value: ");

    do
    {
        // Get the user search value
        searchVal =  getUserFloatValue();

         // If it's not a valid search -> exit
        if(searchVal != INPUT_ERROR)       
        {
            // Reset counter to 0
            counter = 0; 
            printf("Searching for employee salaries below: $ %.2f\n\n", searchVal);

            // Linear search (Complexity: O(n)) 
            for(int i = 0; i < SIZE; i++)
            {
                // Being sure to not include invalid values...
                if(salaries[i] < searchVal && salaries[i] != INPUT_ERROR)
                {
                    counter++;
                    printf("Employee [%d] salary: $ %.2f\n", i + 1, salaries[i]);
                }
            }
            printf("Number of employee salaries below search value: %d Employees\n", counter);
            printf("\nEnter next search value: ");
        }
    } while (searchVal != INPUT_ERROR);

    printf("User stopped search.\n\n");
    return;
}

void pauseContinueProgram()
{
    printf("Press enter to continue...");
    getchar();
    return;
}

void pauseExitProgram()
{
    printf("Press enter to exit program...");
    getchar();
    return;
}
#pragma endregion