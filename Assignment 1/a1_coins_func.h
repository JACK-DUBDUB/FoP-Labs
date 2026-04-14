/* a1_coins_func.h
 * Header file for the functions called in main
 * Author: Jack du Boulay   
 * Student ID: 32712899
 */

#ifndef COIN_SORT_FUNC_H
#define COIN_SORT_FUNC_H

// ---- Numeric constants ---- 
// Step 1: Currency selection 
#define CURR_SELECTION_MIN  1
#define CURR_SELECTION_MAX  3

// Step 2: Change range
#define CHANGE_RANGE_MAX    95
#define LOWEST_MULTIPLE     1

// Steps 3 and 4:
#define COIN_LAST_INDEX     3
#define COIN_VARIANT_MAX    4

// Step 5: Cont/Exit program
#define PROG_REPEAT         1
#define PROG_EXIT           2

// ---- Declared functions ---- 

// Get a user input of type integer
int getUserInt(int rangeMin, int rangeMax);

// Validates the user input - displays error messages of what went wrong
int validateUserInput(int valid, int userInput, int rangeMin, int rangeMax);

// Clear input buffer -> user error issue
void clearInputBuffer();                   

// Calculates the number of coins from largest to smallest required, inserting coins into the sortedCoins array
void calculateCoins(int userChange, const int currencyCoins[], int sortedCoins[]);

// Display user's input currency selection and change values
void displayUserValues(const char *currency_str, int userChange); 

// Displays the number of coins from largest to smallest that matches the user's change value
void displayCoins(int sortedCoins[], const int currencyCoins[]);

// Prompts
void promptUserCurrency();                                      // Prompt user for currency choice .
void promptUserChange(int rangeMin, int rangeMax);              // Prompt user for change amount and range.
void promptUserExit();                                          // Prompt user to retry/exit.
void pauseExitProgram();                                        // Prompt user to hit enter to quit
#endif