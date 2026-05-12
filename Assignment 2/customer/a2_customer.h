#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef A2_CUSTOMER_H
#define A2_CUSTOMER_H

enum CUSTOMER_OPTIONS {C_SEARCH = 1, C_DISP_NAMES = 2, C_DISP_ALL = 3, C_QUIT = 4};
enum CURRENCY_TYPES {USD_ID = 0, AUD_ID = 1, EUR_ID = 2};

// ---- Change limits ----
#define MAX_CHANGE_LIMIT    95  
#define MIN_CHANGE_LIMIT    1   
#define MIN_AUD_LIMIT       5   // AUD values must be divisible by 5

// ---- Currency Values ----
#define MAX_CURRENCY_TYPES  3   // USD, AUD, EUR
#define MAX_COIN_VARIANTS   4   // C1, C2, C3, C4
#define MAX_CODE_LENGTH     5   // "$USD"

// ---- Strings ----
#define USD_S               "$USD"
#define AUD_S               "$AUD"
#define EUR_S               "$EUR"

// ---- Currency intializers ----
#define USD_DATA    {USD_S, 0, {50, 25, 10, 1}}
#define AUD_DATA    {AUD_S, 1, {50, 20, 10, 5}}
#define EUR_DATA    {EUR_S, 2, {20, 10,  5, 1}}

// ======== STRUCTS ========

typedef struct {
    char    code[MAX_CODE_LENGTH];      // Currency code ex: "$USD"
    int     id;                         // 0 = USD, 1 = AUD, 2 = EUR
    int     coins[MAX_COIN_VARIANTS];   // C1, C2, C3, C4
} Currency;


// Memory allocated in program_pipeline()
// Memory freed in customer_freeMemory()
// Calloc preferred -> change_values need to be zeroed
typedef struct { 
    char *name;
    int  change_values[MAX_CURRENCY_TYPES];
    int  coins_usd[MAX_COIN_VARIANTS];
    int  coins_aud[MAX_COIN_VARIANTS];
    int  coins_eur[MAX_COIN_VARIANTS];
    int *coins_ptr[MAX_CURRENCY_TYPES]; // Pointer array pointing to the 3 currency types _usd, _aud, _eur
} Customer;

// ======== Customer functions ========

//  @Brief: Intialize the pointer array of each customer 
//  @Func: Iterates through all customers, intializing the pointer array, points to the customer's coins_(usd, aud, eur) arrays
//  @param: customers, rows
//  @returns: -
void customer_initPointers(Customer *customers, const int rows);

void customer_filterData(Customer *customers, const int rows);

//  @Brief: Shifts null value customers towards the right side of the customer array
//  @Func: Check if a customer is named but no values exist, if they do, shift them towards the right (basically bubble sort)
//  @param: customers, rows
//  @returns: -
void customer_sortNull(Customer *customers, const int rows);

//  @Brief: Handles all customers for inserting coins based on 
//  @Func: Check if a customer is named but no values exist, if they do, shift them towards the right 
//  @param: customers, rows
//  @returns: -
void customer_handleInsertCoins(Customer *customers, const Currency *currencies, const int rows);

void customer_insertCoins(const int customer_change, int customer_coins[], const Currency currencies);

//  @Brief: Counts the number of non-null customers 
//  @Func: For loop, count till customer found with null, then return count value;
//  @param: customers, rows
//  @returns: count
int  customer_count(Customer *customers, const int rows);

void customer_menu(const Customer *customers, const Currency *currencies, const int rows);
int customer_handleDisplayOptions(const Customer *customers, const Currency *currencies, const int rows, const char *search, const int option);

void customer_displayOptions(const Customer *customer_data, const Currency *currencies, const int rows, const int option);

void customer_displayData(const Customer customer, const Currency *currencies);

void customer_freeMemory(Customer *customer_data, const int table_rows);

#endif /* A2_CUSTOMER_H */