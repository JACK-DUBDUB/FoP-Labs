#include "../currency/a2_currency.h"
#include "../customer/a2_customer.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef A2_PROGRAM_H
#define A2_PROGRAM_H


enum PROGRAM_PAUSE  {MSG_CONTINUE, MSG_QUIT};

#define DEFAULT_IN_FILE     "../_data/coins.txt"
#define DEFAULT_OUT_FILE    "../change.csv"

// -------- CHECK ARGUMENTS ---------------------------------------------------------------------------------------------------

// Checks if user included 2 additional arguments : ass2.exe {filein} {fileout} , else use defaults
int program_checkArgs(const int argument_count, char *argument_values[]);


// -------- COMPARE TO --------------------------------------------------------------------------------------------------------

// Compares the two string lengths then compares each char value of each string to check if they are equal (toupper)
int compare_caseInsensitive(const char *string1, const char *string2);

// Compares each customer's name to the temp name provided, returns the index if found a name matches
int compare_existingNames(const CustomerArray customers, const char *t_name);

// Compares the the temp code provided, returns an id value if the code matches {-1, 0, 1, 2}
int compare_currencyCode(const CurrencyArray *currencies, const char *t_code);


// -------- SEARCH MENU HANDLER -----------------------------------------------------------------------------------------------

// Handles and displays the program options menu: [1] search by name, [2] quit program, 
void program_handleSearchMenu(const CustomerArray customers, const CurrencyArray currencies);


// -------- READ VALUE FROM STDIN ---------------------------------------------------------------------------------------------

// Reads an integer input from stdin
int read_intInRange(const int min, const int max);

// Filters the integer input
int filter_intInRange(const int input, const int min, const int max, const int valid);

// Reads a string from stdin, (removes '\n') 
void read_string(char *buffer, const int size);


// -------- PROGRAM HELPERS ---------------------------------------------------------------------------------------------------

// Clears the input buffer
void program_clearInputBuffer(void);

// Pauses the program with a getchar()
void program_pause(enum PROGRAM_PAUSE msg);

#endif /* A2_PROGRAM_H */