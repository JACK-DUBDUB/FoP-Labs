#include <stdio.h>
#include "a1_coins_const.h"

///////////////////
/// DEFINITIONS ///
///////////////////

/** What could be changed here? -> 12/04/2026
 * I could have used a 2D array for the currencyArray[] 
 * I did not do this however as I enjoy seeing the defined semantic clarity of each individual array rather than this:
 * 
 * const int *currencyArray[] = {
 * {50, 25, 10, 1}, // USD
 * {50, 20, 10, 5}, // AUD
 * {20, 10,  5, 1}  // EUR
 * };
 * 
 * Wait, never mind, my version IS architecturally better than a 2D array...
 * */ 

// ---- Coin Arrays ---- //
// Always largest value to smallest 
const int coinsUS[] = {50, 25, 10, 1};  // This is actually a more flexible design than using a 2D array.
const int coinsAU[] = {50, 20, 10, 5};  // This is because we can add or subtract values from the array without having to worry about the 2D array constraints [n][limit]    
const int coinsEU[] = {20, 10,  5, 1};

// Array of pointers to arrays - essentially acts as a 2D array -> currencyArray[selectedCurrencyType][selectedCoinValue];
const int *currencyArray[] = {coinsUS, coinsAU, coinsEU};

// ---- Array Sizes ---- //

// Store the size of each array -> Not exactly dynamic but solves the problem... 
const int coinsArraySizes[] = {
    sizeof(coinsUS) / sizeof(coinsUS[0]),
    sizeof(coinsAU) / sizeof(coinsAU[0]),
    sizeof(coinsEU) / sizeof(coinsEU[0]),
};

// Store size of pointer coins Array
// Have to calculate here as the compiler does not know the size when using sizeof due to it being extern (can only be done where it is defined/contained with the initializer) -> https://stackoverflow.com/a/23230216
// As the compiler will only know of the pointer to the array... annoying
const int currencyArrayNum = sizeof(currencyArray) / sizeof(currencyArray[0]); 

// ---- Strings ---- //

// Array of pointers to "strings"
const char *CURRENCY_TYPE_S[] = {
    "$ USD", 
    "$ AUD", 
    "$ EUR"
};

// Used for prompting the user for the getUserInt() function 
const char *CURRENT_STEP_S[] = {
    "Please select a currency type ", 
    "Please enter change amount ", 
    "Please enter a selection "
};