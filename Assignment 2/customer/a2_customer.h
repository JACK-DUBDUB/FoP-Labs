#include "../currency/a2_currency.h"

#ifndef A2_CUSTOMER_H
#define A2_CUSTOMER_H

enum CUSTOMER_OPTIONS {C_SEARCH = 1, C_DISP_NAMES = 2, C_DISP_ALL = 3, C_QUIT = 4};

// ---- Change limits ----
#define MAX_CHANGE_LIMIT    95  
#define MIN_CHANGE_LIMIT    1   
#define MIN_AUD_LIMIT       5 
#define MAX_SEARCH_BUFFER   128


// ======== STRUCT ========

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

// ---- Processes ----

// Iterates through all customers, intializing the pointer array, points to the customer's coins_(usd, aud, eur) arrays
void customer_initPointers(Customer *customers, const int rows);

// Iterates through all customers, nulls customer names that have invalid/null values.
void customer_filterData(Customer *customers, const int rows);

// Iterates through all customers, check if name is null (invalid customer), if null, swap null customer with next non-null customer, returns number of non-null customers
int customer_sortNull(Customer *customers, const int rows);

// Iterates through all customers, check for each customer change value (valid), then insert coins
void customer_handleInsertCoins(Customer *customers, const Currency *currencies, const int rows);

// If the customer has a positive change amount, calculate number of coins from largest to smallest
void customer_insertCoins(const int customer_change, int customer_coins[], const Currency currencies);

// ---- Menu ----

// Prompts the user with a display menu, reads an int input from user that selects an option/s till user eneters [4] to quit program
void customer_handleMenu(const Customer *customers, const Currency *currencies, const int rows);

// Displays the option menu: [1] search by name, [2] display customer names, [3] display all customer data, [4] quit program
void customer_displayMenu(void);

// Searches the customers to find matching name (case insensitive), returns {index if found} or {-1 if not found}
int customer_nameSearch(const Customer *customers, const Currency *currencies, const int rows, const int selection);

// Picks which result to display based on the option selected
int customer_handleDisplayOptions(const Customer *customers, const Currency *currencies, const int rows, const char *search, const int option);

// Displays the specific customer's data values: name, currency type values: change value and coins (if any)
void customer_displayData(const Customer customer, const Currency *currencies);

// ---- Memory ----

// Frees the allocated memory for customer data, frees name, then values
void customer_freeMemory(Customer *customers, const int rows);

#endif /* A2_CUSTOMER_H */