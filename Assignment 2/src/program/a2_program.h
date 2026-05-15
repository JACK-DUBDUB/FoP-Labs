#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../customer/a2_customer.h"
#include "../currency/a2_currency.h"
#include "../general/a2_general.h"

#ifndef A2_PROGRAM_H
#define A2_PROGRAM_H

// ======= ENUMS ========

enum PROGRAM_PAUSE  {MSG_CONTINUE, MSG_QUIT};
enum PROGRAM_STATUS {PRGRM_SUCCESS, ERR_FILE_READ, ERR_DATA_LOAD};

// File strings
#define DEFAULT_IN_FILE     "../data/in_data/coins.txt"
#define DEFAULT_OUT_FILE    "../data/out_data/change.csv"


// ======== PROGRAM FLOW FUNCTIONS ======== //

// Checks user args -> both empty? -> use defaults for IO files
// Reads first line of file -> did not parse int value? -> Exit
//      -> continue
// Reads number of lines of file -> did not read any lines? -> Exit
//      -> continue
int program_fileRead(const int argc, const char **argv, char **infile, char **outfile, int *expected_lines, int *line_count);

// Reads each customer entry and validates -> no read or no customers? -> Exit
//      -> continue
// Customer values are filtered further, customers with no values are nullified 
//      -> continue
// Shuffle customers from left (non-null customers) to right (null customers) -> no valid customers? -> Exit
// Inserts customer coins
int program_loadData(Customer *customers, const Currency *currencies, const int rows, const char *infile, int *unique_customers, int *valid_customers);

// Writes customer data to file
// Records each line printed -> no write or no lines printed? -> thats okay, continue                        
int program_fileWrite(const Customer *customers, const Currency *currencies, const int rows, const char *outfile, int *printed_customers);

// ---- PROCESSES ----

// Checks if the user included any args when they launched program
void program_handleArgs(const int arg_count, const char **arg_values, char **infile, char **outfile);

// Displays all the program results received from each major process of the program
void program_displayResults(const int expected_l, const int counted_l, const int uniq_c, const int valid_c, const int printed_c);

// Clears the input buffer
void program_clearInputBuffer(void);

// Pauses the program with a getchar()
void program_pause(enum PROGRAM_PAUSE msg);


#endif