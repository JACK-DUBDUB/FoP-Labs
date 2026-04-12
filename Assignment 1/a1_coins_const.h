#ifndef COIN_SORT_CONST_H
#define COIN_SORT_CONST_H

// ---- numeric constants ---- 
// Step 1: Currency selection 
#define CURR_SELECTION_MIN  1
#define LOWEST_MULTIPLE     1 // For getUserInt() -> Steps 1 and 3

// Step 2: Change value amount
#define USER_CHANGE_MAX     95
#define USER_CHANGE_MIN     1

// Step 3: Cont/Exit program
#define PROG_REPEAT         1
#define PROG_EXIT           0

// ---- Arrays ---- 
extern const int coinsUS[];
extern const int coinsAU[];
extern const int coinsEU[];
extern const int coinsArraySizes[];
extern const int *currencyArray[];

// --- Int ----
extern const int currencyArrayNum; // size of *coinsArray

// ---- List of strings ---- //
extern const char *CURRENCY_TYPE_S[];
extern const char *CURRENT_STEP_S[];


#endif