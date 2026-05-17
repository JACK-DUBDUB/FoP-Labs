#include "./program/a2_program.h"
#include "./crud/a2_crud.h"

/* ASSIGNMENT 2 - FILE I/O CUSTOMER CHANGE & COIN PROCESSING
* NAME:     JACK DU BOULAY
* ID:       32712899
* DATE:     09/05/2026 - 17/05/2026

========= ABOUT PROGRAM ========
* OS: Windows 
* CLI program

* Program expects the user to include argument values {program name} {file in} {file out}
*       - If user does not include a {file in} and/or {file out} 
*               -> Program displays the "missing" error 
*               -> Quit program
*                   
* The program reads the {file in} making a single test ofparsing the first row value 
*       - [1] The first line value, parsing the value as an integer (assumed line count of file)
*               -> If the data fails to parse or is a negative value, Quit program

* Allocate memory for the number of customer entries (line count of file)
*       -> customers is null? quit program

* If both tests pass then we read {file in} parsing each line of customer data
*       - Displays errors for each line that does not parse
*       - Displays the number of errors (if any)
*
* Program then filters the parsed data further
*       - Filter AUD values that are not divisible by 5
*       - NULL each customer with a name that has all change values at 0

* Prompt the user with a menu with the following options:
*       - [1] Search by name                
*               -> ignoring case, search for customer with matching name
*       - [2] Quit program

* Program writes to file {file out} returning the number of lines printed

* Free customer memory

* Prompt user to hit enter before exit

======== Example Input File Format =========
3
Alpha 86 cents in $USD
Bravo 85 cents in $AUD
Charlie 36 cents in $EUR

======== Example Output File Format ========

Alpha, the change for 86 cents in $USD is 1,1,1,1           // c: 50, 25, 10, 1
Bravo, the change for 85 cents in $AUD is 1,1,1,1           // c: 50, 20, 10, 5
Charlie, the change for 36 cents in $EUR is 1,1,1,1         // c: 20, 10,  5, 1

======== Compile and run ========
* Compile: 
*   gcc .\a2_main.c .\program\a2_program.c .\customer\a2_customer.c .\currency\a2_currency.c .\crud\a2_crud.c -o ass2.exe
* 
* Run:
*   .\ass2.exe .\_data\coins.txt change.csv                         // DEFAULT DATA-IN  +  DEFAULT DATA-OUT
*   .\ass2.exe .\_data\test_case1.txt change.csv                    // TEST CASE DATA 1 +  DEFAULT DATA-OUT
*   .\ass2.exe ".\your_data_read.file" "..\your_data_out.file"               
*         
*/


int program_process(char *argument_values[], const int expected_entries)
{
    // Currency data
    Currency currencies[] = {USD_DATA, AUD_DATA, EUR_DATA}; // <- USEFUL!
    CurrencyArray currency_data = {currencies, (sizeof(currencies) / sizeof(Currency))}; 

    // Customer data
    Customer *customers = calloc(expected_entries, sizeof(Customer));
    if (customers == NULL)
    {
        printf("ERROR - Failed to allocate memory for customers with value: %i\n", expected_entries);
        return 3;
    }

    CustomerArray customer_data = {customers, 0, expected_entries};
    customer_initPointers(&customer_data);
    
    if (file_readCustomerData(&customer_data, &currency_data, argument_values[1]))
    {
        customer_freeMemory(&customer_data);
        program_pause(MSG_QUIT);
        return 4;
    }

    program_pause(MSG_CONTINUE); // Pause to show read errors

    customer_filterValues(&customer_data, currency_data);
   
    customer_insertCoins(&customer_data, currency_data);

    program_handleSearchMenu(customer_data, currency_data);

    file_write(customer_data, currency_data, argument_values[2]);


    customer_freeMemory(&customer_data);
    program_pause(MSG_QUIT);

    return 0;
}



int main(int argument_count, char *argument_values[])
{
    if(program_checkArgs(argument_count, argument_values))
    {
        program_pause(MSG_QUIT);
        return 1;
    }

    // Test if file is readable first
    int expected_entries = 0;
    if (file_readFirstLine(argument_values[1], &expected_entries))
    {
        program_pause(MSG_QUIT);
        return 2;
    }

    return program_process(argument_values, expected_entries);
}






