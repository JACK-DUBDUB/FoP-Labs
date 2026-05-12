#include "../customer/a2_customer.h"

#ifndef A2_CREATE_H
#define A2_CREATE_H



// ======== CREATE ======== 
int create_handleCustomerDataOut(const Customer *customer_data, const Currency *currencies, const char *file_name, const int table_rows);
int create_customerDataOut(FILE *output_file, const Customer *customer_data, const Currency *currencies, const int table_rows);

#endif /* _A2_CREATE_ */