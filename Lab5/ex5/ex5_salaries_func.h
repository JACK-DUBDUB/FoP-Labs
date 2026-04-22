#ifndef EX5_FUNC_H
#define EX5_FUNC_H

#include <stdbool.h>

enum SEARCH_OPTIONS{
    SEARCH_RETRY = 'R',
    SEARCH_QUIT = 'Q'
};

// ---- constants ----
// Array limit
#define SIZE            10




// ---- Functions ----
// Gets salary values + salary saerch value
bool read_userFloat(float *out_value);

// Gets salaries, returns True or False.
void handle_readSalaries(float salaries[], const int salary_count);


// Get and display the lowest and highest salaries
void handle_getSalaryMinMax(float salaries[], const int salary_count);
void get_salaryMinMax(float salaries[], const int salary_count, int *min, int *max);

// Get and display the average of valid salaries
void handle_getSalaryAverage(float salaries[], const int salary_count);
float get_salaryAverage(float salaries[], const int salary_count, float *salary_sum);

// Get and display all salaries found below the searched salary value 
void handle_getEmployeeSalaries(float salaries[], const int salary_count);
void get_employeeSalaries(float salaries[], const int salary_count);

bool read_quitSearch();

// Program process
void pauseContinueProgram();
void pauseExitProgram();
#endif