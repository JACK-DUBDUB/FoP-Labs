
/** Assignment 1 -  Coin sorting program
 * ---- Author ----
 * Name:    Jack du Boulay
 * ID:      32712899
 * Date:    12/04/2026
 * 
 * ---- About Program ----
 * CLI program that prompts the user to pick from 3 types of currencies.
 * Then prompts the user to insert their change amount that they want to sort into correct coin amounts/values.
 * Then displays the optimal/appropriate number of coin values.
 * Then prompts the user to try again or quit program.  
 *  
 * ---- Program Flow ----
 *  [START]
 *  [Step 1] Get 1 input for choosing the currency type (US/AU/EU)
 *      -> [Step 2] Get the 4 values of coin values according to the currency type selected
 *  [Step 3] Get 1 input for the change value (1-95) 
 *      -> [Step 4] Program displays the user's values they've entered
 *      -> [Step 5] Program calculates the appropriate number of coins
 *      -> [Step 6] Program displays the number of coins per coin value
 *  [Step 7] Get 1 input to continue/quit program (1-2)
 *       -> If user continues: Repeat 3 input process again -> Back to [Step 1]
 *       -> Else quit program 
 *  [END]
 * 
 * Takes in 3 user inputs using the CLI
 * If user inserts an invalid value for any inputs, CLI will display error message type then re-prompted to try again.
 * 
 * ---- Compile and Run ----
 * Compiled: gcc .\a2_main.c .\a2_func.c .\a2_crud.c -o a2.exe
 * gcc -Wall -Wextra -Wpedantic -std=c17 ".\a1_coins_main.c" ".\a1_coins_func.c" -o a1_coins.exe && .\a1_coins.exe
 * 
 * Run: .\a2.exe
 */

#include "a2_func.h"
#include "a2_crud.h"
#include "a2_general.h"
#include <stdbool.h>
#include <stdio.h>

void sort_coinVariants(int customer_change, int customer_currency[], const Currency currency_type);
void handle_sortCoinVariants(Customer *customer_data, const Currency *currencies, const int table_rows);
void handle_searchCustomerData(const Customer *customer_data, const Currency *currencies,  const enum DISPLAY_MODES option, const int table_rows);
void display_customerData(const Customer customer, const Currency *currencies);
void free_customerData(Customer *customer_data, const int table_rows);


bool handle_mainArgCount(const int arg_count, const char *arg_values[]);
bool handle_readFileResult(const int number, const char *file_name);
bool handle_createFileResult(const int number, const char *file_name);
void display_errorMessage(const enum ERROR_MESSAGES error, const char *value);

int main(const int argument_count, const char *argument_values[])
{
    // Heap
    Customer *customer_data; //   , Freed by free_customerData() 

    // Stack
    Currency currencies[MAX_CURRENCY_TYPES] = { USD_DATA, AUD_DATA,EUR_DATA };

    // Default strings
    char *default_input = "coins.txt", *default_output = "changes.csv"; // ***************************

    if (!handle_mainArgCount(argument_count, argument_values))
        return 1;

    // Read table rows from file
    const int table_rows = handle_readFileCustomerData(argument_values[1], customer_data, FILE_READ_ROW);

    if (!handle_readFileResult(table_rows, argument_values[1])) 
        return 2;

    // Based on the number provided in the text file create table_rows number of customers
    // Calloc intializes all bytes to zero (- which is a good thing!) 
    customer_data = (Customer*) calloc(table_rows, sizeof(Customer)); // (Cast operator*)




    // Display initial line count
    printf("Line count: %i\n\n", table_rows );

    // Read values from customers
    const int total_customers = handle_readFileCustomerData(argument_values[1], customer_data, FILE_READ_DATA);

    if (!handle_readFileResult(total_customers, argument_values[1])) 
        return 3; 

    printf("Total unique customers: %i\n", total_customers);


    // Insert the correct number of coins for each customer
    handle_sortCoinVariants(customer_data, currencies, table_rows);

    // Search tests
    handle_searchCustomerData(customer_data, currencies, DISPLAY_ALL, table_rows);
    handle_searchCustomerData(customer_data, currencies, DISPLAY_NAMES, table_rows);



    // Write to file
    const int total_rows_printed = handle_createCustomerDataCSV(customer_data, currencies, default_output, table_rows);

    if (!handle_createFileResult(total_rows_printed, default_output)) { return 3; }

    printf("Total rows printed: %i\n", total_rows_printed);
    

    // Free customer_data
    free_customerData(customer_data,  table_rows);

    // Exit
    pauseExitProgram();
    return 0;
}

bool handle_mainArgCount(const int arg_count, const char *arg_values[])
{   
    if (arg_count < 2) {
        display_errorMessage(ERR_PRGM_NO_ARG, NULL);
        return false;
    }
    else if (arg_count > 2) {
        display_errorMessage(ERR_PRGM_MANY_ARG, NULL);
        return false;
    }
    printf("\nThe argument value provided is '%s'\n", arg_values[1]); 
    return true;
}

bool handle_readFileResult(const int number, const char *file_name)
{
    if (number < 0) {
        display_errorMessage(ERR_FILE_BAD_READ, file_name);
        return false;
    }
    else if (!number){
        display_errorMessage(ERR_FILE_NO_READ, file_name);
        return false;
    }
    printf("Number read from file: %i\n", number); 
    return true;
}

bool handle_createFileResult(const int number, const char *file_name)
{
    if (number < 0) {
        display_errorMessage(ERR_FILE_BAD_CREATE, file_name);
        return false;
    }
    else if (!number){
        display_errorMessage(ERR_FILE_NO_WRITE, file_name);
        return false;
    }
    printf("Lines printed to file '%s': %i\n", file_name, number);
    return true;
}

void display_errorMessage(const enum ERROR_MESSAGES error, const char *value)
{
    switch (error) 
    {   // -- Program args --
        case ERR_PRGM_NO_ARG:   printf("ERROR - One additional argument was expected \n"); break;
        case ERR_PRGM_MANY_ARG: printf("ERROR = Too many arguments provided \n"); break;

        // -- Read file --
        case ERR_FILE_BAD_READ: printf("ERROR - Failed to open file in 'r' mode. Make sure its a .txt file \n"); break;
        case ERR_FILE_NO_READ:  printf("ERROR - Could not read lines of file '%s' in 'r' mode \n", value);

        // -- Create file --
        case ERR_FILE_BAD_CREATE: printf("ERROR - Failed to create file '%s' in 'w' mode. \nFile may still be open and/or missing permissions.\n", value); break;
        case ERR_FILE_NO_WRITE: printf("ERROR - Program did not write any lines to output file '%s' \n", value); break;

        default: break;
    }

    return;
}

/*
int handle_userSelection(const int option)
{
    switch (option)
    {
        case


    }


    return 0;
}*/




// ---- HEAP ----

void handle_sortCoinVariants(Customer *customer_data, const Currency *currencies, const int table_rows)
{
    for (int i = 0; i < table_rows; i++)
    {
        for (int j = 0; j < MAX_CURRENCY_TYPES; j++)
        {
            if (!customer_data[i].change_values[j])
                continue;

            sort_coinVariants(customer_data[i].change_values[j], customer_data[i].coins_ptr[j], currencies[j]);
        }
    }
    return;
}

void sort_coinVariants(const int customer_change, int customer_coins[], const Currency currencies)
{
    // Insert number of coins based on customer change
    int change = customer_change;
    for (int i = 0; i < MAX_COIN_VARIANTS; i++)
    {
        customer_coins[i] =  calculate_intDiv(change, currencies.coins[i]);
        change = calculate_intMod(change, currencies.coins[i]);
    }

    return;
}






void handle_searchCustomerData(const Customer *customer_data, const Currency *currencies,  const enum DISPLAY_MODES option, const int table_rows)
{
    switch (option) 
    {
        case DISPLAY_SEARCH: printf("\n---- Search Customer By Name ----\n"); break;
        case DISPLAY_ALL: printf("\n---- All Customer Data ----\n"); break;
        case DISPLAY_NAMES: printf("\n---- All Customer names ----\n"); break;
        default: return;
    }   

    const char *name;

    for (int i = 0; i < table_rows; i++)
    {
        if (customer_data[i].name == NULL)
            break;

        if (option == DISPLAY_SEARCH) {

            if (compare_caseInsensitive(customer_data[i].name, name))
                display_customerData(customer_data[i], currencies); 
            else
                printf("Name: %s\nNot found\n", name);
        }

        if (option == DISPLAY_ALL)
            display_customerData(customer_data[i], currencies);

        if (option == DISPLAY_NAMES)
            printf("- %s  \t[%i]\n", customer_data[i].name, i);
    }

    printf("\n\n");
    return;
}

void display_customerData(const Customer customer, const Currency *currencies)
{
    printf("\nCustomer: %s\n", customer.name);

    for (int i = 0; i < MAX_CURRENCY_TYPES; i++)
    {
        if (customer.change_values[i]) // If customer has any non 0 valid USD/AUD/EUR
        {
            printf("Change in cents %s: %i\n", currencies[i].code, customer.change_values[i]);

            for (int j = 0; j < MAX_COIN_VARIANTS; j++)
            {
                if(customer.coins_ptr[i][j])
                    printf("Cents %i: \t%i\n", currencies[i].coins[j], customer.coins_ptr[i][j]);
            }

            printf("\n");
        }
    }

    return;
}

void free_customerData(Customer *customer_data, const int table_rows)
{
    if (!customer_data) return;

    for (int i = 0; i < table_rows; i++)
        free(customer_data[i].name);

    free(customer_data); 

    return;
}