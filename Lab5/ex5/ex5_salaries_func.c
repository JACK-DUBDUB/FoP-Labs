#include <stdio.h>
#include "ex5_salaries_func.h"

// ---- get float ----

float getUserFloat()
{
    float salaryInput = 0;
    scanf_s("%f", &salaryInput);
    
    if(getchar() != '\n') {
        // printf("Cannot enter a non-numeric character.\n");
        while(getchar() != '\n');       // clear input buffer
        return salaryInput = INPUT_ERROR;
    }
    
    if(salaryInput <= 0) {
        // printf("Cannot enter a non-positive value.\n");
        return salaryInput = INPUT_ERROR;
    }

    return salaryInput;
}

// ---- salaries ---- 

int handle_getSalaries(float salaries[])
{
    int iCount = 0; 

    printf("-------- Get Salaries --------\n\n");
    printf("Enter a positive numeric value for up to %i employee salaries.", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        printf("\nEmployee [%d] salary amount: $ ", i + 1);

        salaries[i] = getUserFloat();

        if(salaries[i] != INPUT_ERROR){
            iCount++;
        }
        else{
            printf("\nUser entered an invalid value.\n");
        }
    }

    if (iCount) // At least 1 valid salary
        return TRUE;
    
    return FALSE;
}

// ---- min max ----

void handle_getMinMax(float salaries[]) 
{
    int iMin = 0;
    int iMax = 0;
    
    printf("\n-------- Minimum and Maximum --------\n\n");

    getMinMax(salaries, &iMin, &iMax);

    printf("Lowest employee salary:  Employee [%d]: $ %.2f\n", iMin + 1, salaries[iMin]);
    printf("Highest employee salary: Employee [%d]: $ %.2f\n\n", iMax + 1, salaries[iMax]);
    
    pauseContinueProgram();
    return;
}

void getMinMax(float salaries[], int *min, int *max)
{
    for (int i = 0; i < SIZE; i++)
    {
        if(salaries[i] != INPUT_ERROR)
        {
            if(salaries[*max] < salaries[i])
                *max = i;
        
            if(salaries[*min] > salaries[i])
                *min = i;

            if(salaries[*min] == INPUT_ERROR) // Safeguard
                *min = *max;
        }
    }
    return;
}

// ---- average ----

void handle_getAverage(float salaries[])
{
    int iCount = 0;
    int iSum = 0;

    printf("\n-------- Average Of Salaries --------\n\n");

    float fAverage = getAverage(salaries, &iCount, &iSum);

    printf("Using %i valid salaries.\n", iCount);
    printf("The total sum of salaries: %i\n", iSum);
    printf("The average salary is: $ %.2f\n\n", fAverage);

    pauseContinueProgram();
    return;
}

float getAverage(float salaries[], int *count, int *sum)
{
    for (int i = 0; i < SIZE; i++)
    {
        if(salaries[i] != INPUT_ERROR)
        {
            *count += 1;
            *sum += salaries[i];
        }
    }

    float average = (float) *sum / *count;
    return average;
}

// ---- search ----

void handle_linearSearch(float salaries[])
{
    float fSearchVal = 0;

    printf("\n-------- Search Salaries --------\n\n");
    printf("Enter a salary value to find all employee salaries below it.\n");
    printf("Enter any non-numerical or non-positive value to quit salary search.\n\n");
    printf("Enter a search value: ");

    do {
        fSearchVal =  getUserFloat(); // get search value
        if(fSearchVal != INPUT_ERROR) {
            printf("\nSearching for employee salaries below: $%.2f\n", fSearchVal);

            int iCount = linearSearch(salaries, fSearchVal);

            printf("\nNumber of salaries below $%.2f : %d \n", fSearchVal, iCount);
            printf("\nEnter next search value: ");
        }
        else {
            printf("User entered a value to stop search.\n\n");
        }

    } while (fSearchVal != INPUT_ERROR);
    
    return;
}

int linearSearch(float salaries[], float searchVal)
{
    int count = 0;
    for(int i = 0; i < SIZE; i++) {

        if (salaries[i] == INPUT_ERROR) { // Skip invalid
             continue;
        }
           
        if(salaries[i] < searchVal) {
            printf("Employee [%d] salary: $%.2f\n", i + 1, salaries[i]);
            count++;
        }
    }
    return count;
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