#ifndef EX5_FUNC_H
#define EX5_FUNC_H

// ---- constants ----
// Array limit
#define SIZE            10

// Input error
#define INPUT_ERROR    -1.0

// Boolean T/F
#define TRUE            1
#define FALSE           0

// ---- Functions ----
// Gets salary values + salary saerch value
float getUserFloat();

// Gets salaries, returns True or False.
int handle_getSalaries(float salaries[]);

// Get and display the lowest and highest salaries
void handle_getMinMax(float salaries[]) ;
void getMinMax(float salaries[], int *min, int *max);

// Get and display the average of valid salaries
void handle_getAverage(float salaries[]);
float getAverage(float salaries[], int *count, int *sum);

// Get and display all salaries found below the searched salary value 
void handle_linearSearch(float salaries[]);
int linearSearch(float salaries[], float searchVal); // Search from 0 -> 10 salaries

// Program process
void pauseContinueProgram();
void pauseExitProgram();
#endif