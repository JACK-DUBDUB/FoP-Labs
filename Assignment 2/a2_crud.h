#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef _A2_CRUD_
#define _A2_CRUD_



enum READ_OPTIONS 
{
    FILE_READ_ROW = 0,
    FILE_READ_DATA = 1,
};

enum CURRENCY_TYPES 
{
    USD_ID = 0,
    AUD_ID = 1,
    EUR_ID = 2
};

enum ERROR_MESSAGES 
{
    // Program
    ERR_PRGM_NO_ARG     = 0, // Missing additional arg
    ERR_PRGM_MANY_ARG   = 1, // Included too many args
    // Read
    ERR_FILE_BAD_READ   = 2, // Couldn't read from file
    ERR_FILE_NO_READ    = 3, // No lines read from file
    // Create
    ERR_FILE_BAD_CREATE = 4, // Couldn't create file
    ERR_FILE_NO_WRITE   = 5, // Did not write any lines to file
};



/*
#define DISPLAY_ERROR(error) printf("Error: %s (Code: %i)\n", #error, error);

#define PGRM_ERROR_LIST \
    x(1, 2)  \
    x(-1, 0) \
    x(-1, 0)

typedef enum 
{
    #define x(err1, err2)
    PGRM_ERROR_LIST
    #undef x
} Error_code;*/

// ======== CONSTANTS =========

// ---- Read line limit ---- 
#define MAX_BUFFER_LENGTH   256

// ---- Change limits ----
#define MAX_CHANGE_LIMIT    95
#define MIN_CHANGE_LIMIT    1
#define MIN_AUD_LIMIT       5

// ---- Currency Values ----
#define MAX_CURRENCY_TYPES  3
#define MAX_COIN_VARIANTS   4
#define MAX_CODE_LENGTH     5

// ---- Strings ----
#define USD_S   "$USD"
#define AUD_S   "$AUD"
#define EUR_S   "$EUR"

// ---- Struct Intializer ----
#define USD_DATA    {USD_S, 0, {50, 25, 10, 1}}
#define AUD_DATA    {AUD_S, 1, {50, 20, 10, 5}}
#define EUR_DATA    {EUR_S, 2, {20, 10,  5, 1}}

// ======== STRUCTS ========

typedef struct {
    char    code[MAX_CODE_LENGTH];      // Currency code ex: "$USD"
    int     id;                         // 0 = USD, 1 = AUD, 2 = EUR
    int     coins[MAX_COIN_VARIANTS];   // C1, C2, C3, C4
} Currency;

typedef struct {  // Calloc preferred -> change_values need to be zeroed
    char *name;
    int  change_values[MAX_CURRENCY_TYPES];
    int  coins_usd[MAX_COIN_VARIANTS];
    int  coins_aud[MAX_COIN_VARIANTS];
    int  coins_eur[MAX_COIN_VARIANTS];
    int *coins_ptr[MAX_CURRENCY_TYPES]; // Pointer array pointing to the 3 currency types _usd, _aud, _eur
} Customer;


// ======== CRUD FUNCTIONS ======== 
// -------- CREATE --------

int handle_createCustomerDataCSV(const Customer *customer_data, const Currency *currencies, const char *file_name, const int table_rows);
int create_customerDataCSV(FILE *output_file, const Customer *customer_data, const Currency *currencies, const int table_rows);


// -------- READ --------

int handle_readFileCustomerData(const char *file_name, Customer *customer_data, const enum READ_OPTIONS option);
int read_firstRowEntry(FILE *source_file);

int read_customerData(FILE *source_file, Customer *customer_data);
void shift_toNextToken(char **token, char *_string, const char *delimiter, char **_next_token);
int compare_existingNames(const int unique_customer_c, const Customer *customer_data, const char *_name);
int compare_currencyCode(const char *_code);
bool filter_customerErrorLine(const int line_count, const int _change, const int _code, const int customer_change);


// -------- UPDATE -------- 
// -------- DELETE --------

#endif /* _A2_CRUD_ */