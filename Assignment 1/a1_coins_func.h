/* a1_coins_func.h
 * Header file for the functions called in main
 * Author: Jack du Boulay   
 * Student ID: 32712899
 */

#ifndef COIN_SORT_FUNC_H
#define COIN_SORT_FUNC_H

// ---- Numeric constants ---- 
// Currency
#define CURRENCY_USD        1
#define CURRENCY_AUD        2
#define CURRENCY_EUR        3

// Coins
#define COIN_VAL_50         50
#define COIN_VAL_25         25
#define COIN_VAL_20         20
#define COIN_VAL_10         10
#define COIN_VAL_5          5
#define COIN_VAL_1          1

// Change
#define CHANGE_RANGE_MAX    95

// Exit/cont 
#define PROG_CONT           1
#define PROG_EXIT           2

// ---- Declared functions ---- 

// Get a user input of type integer
int getUserInt(int rangeMin, int rangeMax);

// Validates the user input - displays error messages of what went wrong
int validateUserInput(int valid, int userInput, int rangeMin, int rangeMax);

// Clear input buffer -> user error issue
void clearInputBuffer();                   

// Get values
int getCoinValue(int currencyType, int coinValue_1, int coinValue_2, int coinValue_3);  // Get the appropriate value based on currency type
int getCoinAmount(int coinValue, int userChange);                                       // perform arithmetic to get number of coins
int getChangeRemaining(int coinValue, int coinAmount, int userChange);                  // Reduce the user's change amount after calculation

// Display user's input currency selection and change values
void displayUserValues(int currencyType, int userChange);
void displayCoinResults(int coinValue, int coinAmount);

// Prompts
void promptUserCurrency();                                              // Prompt user for  acurrency choice.
void promptUserChange(int rangeMin, int rangeMax, int currencyType);    // Prompt user for a change value, displaying the min/max range.
void promptUserExit();                                                  // Prompt user to retry/exit.
void pauseExitProgram();                                                // Prompt user to hit enter to quit.
#endif