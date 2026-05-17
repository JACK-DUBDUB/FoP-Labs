#include "../currency/a2_currency.h"
#include "../customer/a2_customer.h"
#include <stdio.h>

#define READ_FILE_BUFFER_LIMIT 256


// -------- READ FROM FILE ----------------------------------------------------------------------------------------------------

// Read first line from file, parse first line value as integer, return the value and {0 success/ 1 fail}
int file_readFirstLine(const char *infile, int *first_value);


// -------- READ CUSTOMER VALUES FROM FILE ------------------------------------------------------------------------------------

// Reads by line from file till customer count reached or EOF
int file_readCustomerData(CustomerArray *customers, const CurrencyArray *currencies, const char *infile);

// -------- CUSTOMER LINE PROCESSING  -----------------------------------------------------------------------------------------

// Handles the customer line tokenization for filtering and parsing for the customer
int process_customerLine(CustomerArray *customers, const CurrencyArray *currencies, char *buffer, const int line_count);

// Reads the buffer line of the file being read, collects each token if it meets criteria
void extract_customerTokens(const CurrencyArray *currencies, char *buffer, char **t_name, char **t_change, char **t_code);

// Filters the customer tokens before parsing it as valid customer values
int filter_customerTokens(const char *t_name,  const char *t_change, const char *t_code);

// Parses the filtered customer tokens, and inserts the corresponding values for each customer  
void insert_customerValues(Customer *customer, const char *name, const int change, const int code);


// -------- WRITE TO FILE -----------------------------------------------------------------------------------------------------

// Creates an outfile, throws an error if it cannot be created,  closes file.
int file_write(const CustomerArray customers, const CurrencyArray currencies, const char *outfile);

// Writes to file, writes the non-null customer values in ".csv" format
void file_writeCustomerData(FILE *f_stream, const CustomerArray customers, const CurrencyArray currencies);
