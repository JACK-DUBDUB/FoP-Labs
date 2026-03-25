#include <stdio.h>
#include "a1_coins_const.h"

// CONSTANTS
// ---- Arrays ---- //
// Always biggest to smallest
const int coinsUS[] = {50, 25, 10, 1};    
const int coinsAU[] = {50, 20, 10, 5};
const int coinsEU[] = {20, 10 , 5, 1};

// Array of pointers to arrays
const int *coinsArray[] = {coinsUS, coinsAU, coinsEU};

// Store the size of each array -> Not exactly dynamic but solves the problem... 
const int coinsArraySizes[] = {
    sizeof(coinsUS) / sizeof(int),
    sizeof(coinsAU) / sizeof(int),
    sizeof(coinsEU) / sizeof(int)
};

// ---- Strings ---- //
// Pointer to string
const char* MENUSELECTION_S = {"\nCurrency Selection menu: \n"
    "[1] $ USD coins: 50, 25, 10, 1 \n"
    "[2] $ AUD coins: 50, 20, 10, 5 \n"
    "[3] $ EUR coins: 20, 10,  5, 1 \n"
};

// Array of pointers to strings
const char *CURRENCYTYPE_S[] = {"$ USD", "$ AUD", "$ EUR"};
