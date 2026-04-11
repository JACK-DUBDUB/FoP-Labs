#include <stdio.h>
#include "a1_coins_const.h"

///////////////////
/// DEFINITIONS ///
///////////////////

// ---- Coin Arrays ---- //
// Always biggest to smallest
const int coinsUS[] = {50, 25, 10, 1};    
const int coinsAU[] = {50, 20, 10, 5};
const int coinsEU[] = {20, 10 , 5, 1};

// Array of pointers to arrays - essentially can act as a 2D array -> currencyArray[currencyType][coinValue];
const int *currencyArray[] = {coinsUS, coinsAU, coinsEU};

// ---- Array Sizes ---- //
// Store size of pointer coins Array
// Have to calculate here as the compiler does not know the size when using sizeof due to it being extern (can only be done where it is defined)
const int currencyArrayNum = sizeof(currencyArray) / sizeof(currencyArray[0]); 

// Store the size of each array -> Not exactly dynamic but solves the problem... 
const int coinsArraySizes[] = {
    sizeof(coinsUS) / sizeof(coinsUS[0]),
    sizeof(coinsAU) / sizeof(coinsAU[0]),
    sizeof(coinsEU) / sizeof(coinsEU[0]),
};

// ---- Strings ---- //
// Array of pointers to "strings"
const char *CURRENCY_TYPE_S[] = {
    "$ USD", 
    "$ AUD", 
    "$ EUR"
};

const char *CURRENT_STEP_S[] = {
    "Please select a currency type ", 
    "Please enter change amount ", 
    "Please enter a selection "
};