/* a1_coins_func.h
 * Header file for the functions called in main
 * Author: Jack du Boulay   
 * Student ID: 32712899
 */

#include "a2_crud.h"

#ifndef _A2_FUNCTIONS_
#define _A2_FUNCTIONS_

// ======= ENUMERATOR ========

enum DISPLAY_MODES {
    DISPLAY_SEARCH = 0,
    DISPLAY_ALL = 1,
    DISPLAY_NAMES = 2
};

// ======== CONSTANTS =========
#define READ_INT_ERROR      -1

// Exit/cont 
#define PROG_CONT           1
#define PROG_EXIT           2

// ======== FUNCTIONS ========

// reads an integer input from stdin
int read_intInRange(const int min, const int max);

// Validates the user input - displays known errors
int filter_intInRange(const int input, const int min, const int max);


// ---- Customer functions ----
void init_customerPointers(Customer *customer_data, const int table_rows);
void shift_nullCustomerData(Customer *customer_data, const int table_rows);

// Clear input buffer -> user error issue
void clearInputBuffer();                   

void promptUserExit();                                                  // Prompt user to retry/exit.
void pauseExitProgram();                                                // Prompt user to hit enter to quit.


#endif