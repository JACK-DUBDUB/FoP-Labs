#include "../program/a2_program.h"


#ifndef A2_CREATE_H
#define A2_CREATE_H

// ======== CREATE ======== 

// Creates an output file, throws an error if it cannot be created,  closes file, returns an out_value
int create_handleDataOut(const Customer *customers, const Currency *currencies, const char *file_name, const int rows, int *out_value);

// Writes to file, writes non-null customer values in ".csv" format (if you can call it that...), returns the number of entries printed to the file
int create_customerDataOut(FILE *file_name, const Customer *customers, const Currency *currencies, const int rows);

#endif /* A2_CREATE_ */