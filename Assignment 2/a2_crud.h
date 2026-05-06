#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a2_func.h"

#ifndef _A2_CRUD_
#define _A2_CRUD_

enum OPTIONS {
    READ_ROWS = 0,
    READ_DATA = 1,
    CREATE_CSV = 2
};

int handle_fileCustomerData(const char *file_name, Customer *customer_data, const char *mode, enum OPTIONS option);
int read_customerRowsNumber(FILE *source_file);

void read_customerData(FILE *source_file, Customer *customer_data);
int read_spacesCount(const char *line_buffer);


int compare_existingNames(int line_count, Customer *customer_data, const char *_name);
int compare_currencyTypes(const char *_currency_type);

#endif