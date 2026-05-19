#ifndef EX1_FUNC_H
#define EX1_FUNC_H

#include <stdbool.h>
#include "..\LAB_8_LIB.h"

enum SEARCH_OPTIONS{
    SEARCH_RETRY = 'R',
    SEARCH_QUIT = 'Q'
};

// ---- constants ----
#define ARRAY_SIZE            10

typedef struct
{
    float *data;
    int count;
} SalaryArray;


// ---- Functions ----
// Gets salary values + salary saerch value
bool read_userFloat(float *out_value);

// Gets salaries, returns True or False.
void handle_readSalaries(SalaryArray salaries);


// Get and display the lowest and highest salaries
void handle_getSalaryMinMax(SalaryArray salaries);
void get_salaryMinMax(SalaryArray salaries, int *min, int *max);

// Get and display the average of valid salaries
void handle_getSalaryAverage(SalaryArray salaries);
float get_salaryAverage(SalaryArray salaries, float *salary_sum);

// Get and display all salaries found below the searched salary value 
void handle_getEmployeeSalaries(SalaryArray salaries);
void get_employeeSalaries(SalaryArray salaries);

bool read_quitSearch();

// Program process
void pauseContinueProgram();
void pauseExitProgram();
#endif