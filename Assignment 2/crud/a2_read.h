#include "../program/a2_program.h"

#ifndef A2_READ_H
#define A2_READ_H


enum READ_OPTIONS {R_FIRST_LINE, R_LINE_COUNT, R_CUST_DATA};

// ---- Read line limit ---- 
#define MAX_BUFFER_LENGTH   256


// ======== READ ======== 

// ---- Read File Handler
int read_handleDataIn(const char *file_name, Customer *customer_data, const enum READ_OPTIONS option); // Hmmm, could use void* instead of customer specific???

// Read first line of file, parse value as integer, return value
int read_firstLine(FILE *source_file);

// Read through file, count each line till EOF, returns count
int read_lineCount(FILE *source_file);

// Read through file, handle's the custome data till EOF, returns number of unique customers
int read_customerData(FILE *source_file, Customer *customer_data);

// Reads the buffer line of the file being read, parse the customer data, returns the string token should parsing fail
int extract_customerTokens(char *buffer, char **t_name, char **t_code, char **t_change);

// Compares the string token with any of the existing customers, returns uniq_cust or returns index (i)
int compare_existingNames(const int unique_customers, const Customer *customers, const char *token);

// Compares the string token to existing currency codes
int compare_currencyCode(const char *token);

// Filters parsed customer values
int filter_customerValues(const Customer customer, const char *t_name,  const char *t_change, const char *t_code);

// Inserts the filtered customer values  
void insert_customerValues(Customer *customer, const char *name, const int change, const int code);

#endif /* A2_READ_H */