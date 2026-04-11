#ifndef COIN_SORT_FUNC_H
#define COIN_SORT_FUNC_H

// ---- Declared functions ---- //

// Get a user input of type integer
// range min / range max  / lowest multiple / current step (string)
int getUserInt(int rangeMin, int rangeMax, int lowestMultiple, const char *currentStep);

// Displays the available currency types and their coin variants
// available currencies / number of currencies / size per currency type / currency type (string)
void displayMenu(const int *currencyArray[], const int coinsArrayNum, const int coinsArraySizes[], const char *CURRENCY_TYPE_S[]);

// Calculates the number of coins from largest to smallest to return to the customer  
// initial change amount / currency type chosen (int array) / size of int array chosen / currency type chosen (string) / for the post calculation sorted coins
int calculateChange(int change, const int currency[], int arraySize, const char *currencyType, int sortedCoins[]);

// Displays the intial change amount and the number of coins from largest to smallest to return to the customer
// initial change amount / change amount post calc / sorted coins array post calc / currency type chosen (int array) / size of currency type / currency type (string)
void displayChange(int change, int changeFinal, int sortedCoins[], const int currency[], int arraySize, const char*currencyType);

// Press enter to exit the program
void pauseExitProgram();

// Clears input buffer incase the user entered too many values or incorrect characters
void clearInputBuffer();
#endif