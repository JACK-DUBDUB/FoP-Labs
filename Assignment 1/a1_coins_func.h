#ifndef COIN_SORT_FUNC_H
#define COIN_SORT_FUNC_H

// ---- Numeric constants ---- 
// Step 1: Currency selection 
#define CURR_SELECTION_MIN  1
#define LOWEST_MULTIPLE     1

// Step 2: Change range
#define CHANGE_RANGE_MAX     95

// Step 3: Cont/Exit program
#define PROG_REPEAT         1
#define PROG_EXIT           2

// ---- Declared functions ---- 

// Get a user input of type integer
// range min / range max
int getUserInt(int rangeMin, int rangeMax);

// Calculates the number of coins from largest to smallest required, inserting coins into the sortedCoins array
// user change amount / currency type array chosen  / post calculation sorted coins / size of selected array
void calculateCoins(int userChange, const int currencyType[], int sortedCoins[], int arraySize);

// Displays the number of coins from largest to smallest that matches the user's change value
// user change amount / sorted coins array / currency type the user chose / size of currency type 
void displayCoins(int sortedCoins[], const int currency[], int arraySize);

// Prompt menu to user
void promptUserCurrency();
void promptUserChange(int min, int max);
void promptUserExit();

// Press enter to exit the program
void pauseExitProgram();

// Clears input buffer incase the user entered too many values or incorrect characters/values
void clearInputBuffer();

#endif