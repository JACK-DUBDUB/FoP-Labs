#include "../program/a2_program.h"

#ifndef A2_READ_H
#define A2_READ_H


enum READ_OPTIONS {R_FIRST_LINE, R_LINE_COUNT, R_CUST_DATA};

// ---- Read line limit ---- 
#define MAX_BUFFER_LENGTH   256


// ======== READ ======== 

// Handles three significant options for reading: [1] read first value, [2] read total lines, [3] read then load customer values -> returns out_value or error val
int read_handleDataIn(const char *infile, Customer *customers, const enum READ_OPTIONS option, int *out_value); // Hmmm, could use void* instead of customer specific???

// ---- Options ----

// Read first line of file, parse value as integer, return value
int read_firstLine(FILE *source_file);

// Read through file, count each line till EOF, returns count
int read_lineCount(FILE *source_file);

// Read through file, handle's the custome data till EOF, returns number of unique customers
int read_customerData(FILE *source_file, Customer *customes);

// ---- Filter functions for parsing customer data ----

// Reads the buffer line of the file being read, parse the customer data, returns the string token should parsing fail
void extract_customerTokens(char *buffer, char **t_name, char **t_code, char **t_change);

// Compares the string token with any of the existing customers, returns uniq_cust or returns index (i)
int compare_existingNames(const int unique_customers, const Customer *customers, const char *token);

// Compares the string token to existing currency codes
int compare_currencyCode(const char *t_code);

// Filters parsed customer values
int filter_customerValues(const Customer customer, const char *t_name,  const char *t_change, const char *t_code);

// Inserts the filtered customer values  
void insert_customerValues(Customer *customer, const char *name, const int change, const int code);

#endif /* A2_READ_H */