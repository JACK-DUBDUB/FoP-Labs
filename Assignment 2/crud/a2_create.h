#include "../customer/a2_customer.h"

#ifndef A2_CREATE_H
#define A2_CREATE_H

// ======== CREATE ======== 

// Creates an output file, throws an error if it cannot be created,  closes file, returns an out_value
int create_handleDataOut(const Customer *customer_data, const Currency *currencies, const char *file_name, const int table_rows);

// Writes to file, writes non-null customer values in ".csv" format (if you can call it that...), returns the number of entries printed to the file
int create_customerDataOut(FILE *output_file, const Customer *customer_data, const Currency *currencies, const int table_rows);

#endif /* A2_CREATE_ */