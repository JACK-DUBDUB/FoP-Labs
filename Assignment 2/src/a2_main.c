#include "program/a2_program.h"

/* ASSIGNMENT 2 - FILE I/O CUSTOMER CHANGE & COIN PROCESSING
* NAME:     JACK DU BOULAY
* ID:       32712899
* DATE:     09/05/2026 - 13/05/2026

========= AUTHOR NOTE ========
Yeah... -um, OOPS!? 

Sorry, went overboard for this assignment.
My programming knowledge is somewhat returning to me, so i got a wee-bit carried away.
Program goes well beyond the assigment scope, but, thats all part of the fun, innit? 

All the data files are in the data dir
I recommend using test_case1.txt to confirm my test cases

Anyways - enjoy testing!
Cheers 
    - Jack

========= ABOUT PROGRAM ========
* OS: Windows 
* CLI program

* Program expects the user to include argument values {program name} {file in} {file out}
*       - If user does not include a {file in} and/or {file out} 
*               -> Program displays the "missing" error 
*                       -> Program continues with default files instead
* The program reads the {file in} making 2 tests before fully committing to reading the data:
*       - [1] The first line value, parsing the value as an integer (assumed line count of file)
*       - [2] The number of lines of the whole file (the actual line count of file) (better indicator for number of customer entries)

* Allocate memory for the number of customer entries (line count of file)

* If both tests pass then we read {file in} parsing each line of customer data
*       - Displays errors for each line that does not parse
*       - Displays the number of errors (if any)
*
* Program then filters the parsed data further
*       - Filter AUD values that are not divisible by 5
*       - NULL each customer with a name that has all change values at 0
* Move null customer towards end of array, shifting valid customers towards start of array
*       - Example: {-A, -B, -C} = NULL, {X} = VALID 
*           (-A <-> X) -> (X <-> -A), 
*           [-A], [-B], [-C], [X]
*           [x], [-B], [-C], [-A]
* Count the number of valid customers 
* Assort the correct number of coins for each customer (largest to smallest)

* Prompt the user with a menu with the following options:
*       - [1] Search by name                
*               -> ignoring case, search for customer with matching name
*       - [2] Display customer names
*               -> Displays all non-null customer names
*       - [3] Display all customer data
*               -> Displays all customer data: {name, change value, currency, coin variants}
*       - [4] Quit program

* Program writes to file {file out} returning the number of lines printed

* Free customer memory

* Displays the values of each major process
*       - Program feedback {First value of file, Line count of file, Unique Customers count of file, Valid customers count, printed line count to file}

* Prompt user to hit enter before exit

======== Example Input File Format =========
3
Tango 86 cents in $USD
Alpha 85 cents in $AUD
Bravo 36 cents in $EUR

======== Example Output File Format ========
Tango, the change for 86 cents in $USD is 1,1,1,1   // Coins: 50, 25, 10, 1
Alpha, the change for 85 cents in $AUD is 1,1,1,1   // Coins: 50, 20, 10, 5
Bravo, the change for 36 cents in $EUR is 1,1,1,1   // Coins: 20, 10,  5, 1

======== Compile and run ========
* Compile: 
*   gcc .\a2_main.c .\program\a2_program.c .\general\a2_general.c .\customer\a2_customer.c .\currency\a2_currency.c .\crud\a2_create.c .\crud\a2_read.c -o ..\bin\ass2.exe
* 
* Run:
*   ..\bin\ass2.exe                                                                 // DEFAULT DATA-IN  +  DEFAULT DATA-OUT
*   ..\bin\ass2.exe ..\data\in_data\test_case1.txt                                  // TEST CASE DATA 1 +  DEFAULT DATA-OUT
*   ..\bin\ass2.exe ""..\your_data_read.file" "..\your_data_out.file"               
*         
*/

int main(const int argument_count, const char *argument_values[])
{
    // Stack
    const Currency currency_data[MAX_CURRENCY_TYPES] = {USD_DATA, AUD_DATA, EUR_DATA};

    // Heap 
    // Customers allocated in main with calloc()
    // Customer.name is allocated in program_loadData() with calloc() 
    // Memory for customer is freed in customer_freeMemory()
    Customer *customer_data;
    
    // Stream values
    char *infile = NULL, *outfile = NULL;

    // Process result values
    int expected_lines, line_count, unique_customers, customer_count, printed_customers;

    // Attempt to read the file
    if(!program_fileRead(argument_count, argument_values, &infile, &outfile, &expected_lines, &line_count))
    {
        program_pause(MSG_QUIT);
        return ERR_FILE_READ;
    }

    // Allocate memory for customers then initialize pointer array for each customer
    customer_data = (Customer*) calloc(line_count, sizeof(Customer));
    customer_initPointers(customer_data, line_count);

    // Reads customer data file, assigns values for customers, filters/validates customers
    if(!program_loadData(customer_data, currency_data, line_count, infile, &unique_customers, &customer_count))
    {
        customer_freeMemory(customer_data, line_count);
        program_pause(MSG_QUIT);
        return ERR_DATA_LOAD;
    }

    // CLI Menu
    customer_handleMenu(customer_data, currency_data, customer_count);

    // Writes to file, counts number of customer entries printed
    program_fileWrite(customer_data, currency_data, customer_count, outfile, &printed_customers);

    // Free customer memory
    customer_freeMemory(customer_data,  line_count);

    // Display program results
    program_displayResults(expected_lines, line_count, unique_customers, customer_count, printed_customers);

    // Press enter to quit -> getchar() pause
    program_pause(MSG_QUIT);
    return PRGRM_SUCCESS;
}