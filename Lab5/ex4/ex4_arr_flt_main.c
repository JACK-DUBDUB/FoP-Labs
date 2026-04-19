/**
 * /// DATE ///
 * 17/04/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 4
 * "Non-modular" program single function - BUT stdio is used
 * Program can receive up to 10 salary values by the user
 * Validates salaries through a filter
 * If any salaries are valid then apply a +20% pay rise to each valid salary
 *
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\ex4_arr_flt_main.c' -o ex4
 * To run: .\ex4
*/

#include <stdio.h>

// Constants
#define SIZE                10
#define PAY_RISE            1.2
#define USER_INPUT_ERROR    -1.0

int main()
{
    float salaries[SIZE];
    int validCounter = 0;
    float salaryInput;

    // Get float inputs of salaries
    printf("-------- Get Salaries --------");
    for (int i = 0; i < SIZE; i++) 
    {
        salaryInput = 0.0;

        // Prompt user
        printf("\nSalary [%d] amount: ", i + 1);

        // Get salary
        if (scanf_s("%f", &salaryInput) != 1)
        {
            printf("User entered a non-numeric value.\n");
            // clear input buffer
            if(getchar() != '\n')
                while (getchar() != '\n' && getchar() != EOF);
            
            salaries[i] = USER_INPUT_ERROR;        
            continue;
        }

        if(salaryInput <= 0.0 ){
            printf("User did not enter a positive value.\n");
            
            salaries[i] = USER_INPUT_ERROR;        
            continue;
        }

        // Valid
        salaries[i] = salaryInput;
        validCounter++;
    }

    if(!validCounter) {
        printf("\nUser did not enter any valid salary values.\n");
    } 
    else {
        // Display salaires before and after pay rise
        printf("\n-------- Display salaries after pay rise --------");
        for(int i = 0; i < SIZE; i++) {
            if(salaries[i] !=  USER_INPUT_ERROR) {
                
                printf("\n\nSalary: [%i]", i+1);
                printf("\nSalary before 20%% pay rise: $ %.2f",  salaries[i]);
                printf("\nSalary after  20%% pay rise: $ %.2f",  (salaries[i] * PAY_RISE));
            }
        }
    }

    // Pause exit program
    printf("\n\nPress enter to quit program...");
    getchar();
    return 0;
}