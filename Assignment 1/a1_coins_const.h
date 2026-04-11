#ifndef COIN_SORT_CONST_H
#define COIN_SORT_CONST_H

// ---- defined constants ---- 
// Could use ENUM potentially, will look into it later...
#define USER_INPUT_ERROR   -1
#define USER_CHANGE_MAX     95
#define USER_CHANGE_MIN     1
#define CURR_SELECTION_MIN  1   // 
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