#ifndef A2_CUSTOMER_H
#define A2_CUSTOMER_H
#include "../currency/a2_currency.h"

// ======== CONSTANTS ========

// ---- Change limits ----
#define MAX_CHANGE_LIMIT    95  
#define MIN_CHANGE_LIMIT    1   
#define MIN_AUD_LIMIT       5 
#define MAX_CUSTOMER_SEARCH_BUFFER   128


// ======== STRUCTS ========

// ---- CUSTOMER INFO ----
// Memory allocated in main/program_process()
// Memory freed with customer_freeMemory()
// Calloc preferred -> change_values need to be zeroed

// Customer
typedef struct 
{ 
    char *name;                                         
    int values[MAX_CURRENCY_TYPES];                     
    int coins[MAX_CURRENCY_TYPES][MAX_COIN_VARIANTS];   
} Customer;

// Customer wrapper
typedef struct 
{
    Customer *data;     // Customer data pointer
    int count;          // Number of valid customers
    int max;            // Maximum Customer entries possible
} CustomerArray;


// -------- FILTER CUSTOMER VALUES --------------------------------------------------------------------------------------------

// Iterates through all customers, nulls customer names that have all change values set at 0
void customer_filterValues(CustomerArray *customers, const CurrencyArray currencies);


// -------- INSERT CUSTOMER COINS ---------------------------------------------------------------------------------------------

// Iterates through all customers, checks each customer for a positive change value of each currency type, then insert coins 
void customer_insertCoins(CustomerArray *customers, const CurrencyArray currencies);


// -------- HANDLE CUSTOMER SEARCH --------------------------------------------------------------------------------------------

// Handles the name search, receives a string input, searches through the available customers for a matching name
void customer_nameSearch(const CustomerArray customers, const CurrencyArray currencies);


// -------- DISPLAY CUSTOMER DATA VALUES --------------------------------------------------------------------------------------

// Displays all valid customer names
void customer_displayNames(const CustomerArray customers);

// Displays specified customer's data: Name, per currency: change values, coin amounts
void customer_displayData(const Customer customer, const CurrencyArray currencies);


// -------- FREE CUSTOMER MEMORY ----------------------------------------------------------------------------------------------

// Frees the allocated memory for customer data: frees name memory first, then memory allocated for N customers
void customer_freeMemory(CustomerArray *customers);


#endif /* A2_CUSTOMER_H */