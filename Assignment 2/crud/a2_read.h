#include <stdbool.h>
#include "../customer/a2_customer.h"

#ifndef A2_READ_H
#define A2_READ_H



enum READ_OPTIONS {R_FIRST_ROW, R_LINE_COUNT, R_CUST_DATA};

// ---- Read line limit ---- 
#define MAX_BUFFER_LENGTH   256


// ======== READ ======== 

int read_handleCustomerDataIn(const char *file_name, Customer *customer_data, const enum READ_OPTIONS option);
int read_expectedLines(FILE *source_file);
int read_lineCount(FILE *source_file);

int read_customerData(FILE *source_file, Customer *customer_data);
char* parse_customerLine(char *buffer, const Customer *customers, const int uniq_cust, char **name, int *pos, int *change, int *code);

int compare_existingNames(const int uniq_cust, const Customer *customer_data, const char *token);
int compare_currencyCode(const char *code);
bool filter_customerValues(const char *token, const char *name, const int cust_change, const int change, const int code);
void insert_customerValues(Customer *customer, const char *name, const int change, const int code);

#endif /* _A2_READ_ */