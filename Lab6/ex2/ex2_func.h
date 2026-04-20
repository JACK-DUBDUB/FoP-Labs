#ifndef EX2_FUNC_H
#define EX2_FUNC_H

#include<stdbool.h>

// ---- Functions ----

// reads the number of salaries the user wants to enter
int handle_readSalaryNumber();
bool read_salaryNumber(int *out_value);

// 
void handle_readSalaries(float salaries[], const int salary_count);
bool read_userFloat(float *out_value);

// Get and display the lowest and highest salaries
void handle_getSalaryMinMax(float salaries[], const int salary_count);
void get_salaryMinMax(float salaries[], const int salary_count, int *min, int *max);

// Get and display the average of valid salaries
void handle_getSalaryAverage(float salaries[], const int salary_count);
float get_salaryAverage(float salaries[], const int salary_count, float *salary_sum);

#endif