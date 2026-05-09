#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a2_func.h"
#include <stdbool.h>

#ifndef _A2_CRUD_
#define _A2_CRUD_

enum OPTIONS {
    READ_ROWS = 0,
    READ_DATA = 1,
    CREATE_CSV = 2
};

enum CURRENCY_TYPES {
    CURRENCY_USD = 0,
    CURRENCY_AUD = 1,
    CURRENCY_EUR = 2
};

enum DISPLAY_MODE {
    DISPLAY_ONLY = 0,
    DISPLAY_ALL = 1
};

#define MAX_CURRENCY_TYPES 3
#define MAX_COIN_VARIANTS  4
#define USD {"$USD", 0, 50, 25, 10, 1}
#define AUD {"$AUD", 1, 50, 20, 10, 5}
#define EUR {"$EUR", 2, 20, 10,  5, 1}

typedef struct {
    char    currency_code[5];
    int     position;
    int     coins[MAX_COIN_VARIANTS];
} Currency;

typedef struct {
    char *name; // Calloc/Malloc
    int change_values[CURRENCY_MAX], 
    coins_usd[MAX_COIN_VARIANTS], 
    coins_aud[MAX_COIN_VARIANTS], 
    coins_eur[MAX_COIN_VARIANTS];
} Customer;






int handle_fileCustomerData(const char *file_name, Customer *customer_data, const char *mode, const enum OPTIONS option, int *table_rows);
int read_customerRowsNumber(FILE *source_file);

void read_customerData(FILE *source_file, Customer *customer_data);
int read_spacesCount(const char *line_buffer);


void shift_NextToken(char **token, char *_string, const char *delimiter, char **_next_token);


int compare_existingNames(const int current_data_row, const Customer *customer_data, const char *_name);
bool compare_nameCaseInsensitive(const char *ptr_exist, const char *ptr_compr);
int compare_currencyTypes(const char *_currency_type);


void create_customerDataCSV(FILE *source_file, const Customer *customer_data, const int *table_rows);
void write_customerData(FILE *output_file, const char *customer_name, const int change, const char *currency, const int coin_variants[]);
#endif