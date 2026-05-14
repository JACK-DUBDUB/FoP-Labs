#include "customer/a2_customer.h"
#include "currency/a2_currency.h"
#include "general/a2_general.h"
#include "program/a2_program.h"
#include "crud/a2_create.h"
#include "crud/a2_read.h"


/* ASSIGNMENT 2 - FILE I/O CUSTOMER CHANGE & COIN PROCESSING
* NAME:     JACK DU BOULAY
* ID:       32712899
* DATE:     09/05/2026 - 13/05/2026

 ========= About Program ========
* CLI program
* Program expects the user to include argument values {program name} {file in} {file out}
*       - If user does not include a {file in} and/or {file out} 
*               -> Program displays the "missing" error 
*                       -> Program continues with default files instead
*
* The program reads the {file in} making 2 tests before fully committing to reading the data:
*       - [1] The first line value, parsing the value as an integer (assumed line count of file)
*       - [2] The number of lines of the whole file (the actual line count of file) (better indicator for number of customer entries)
*
* Allocate memory for the number of customer entries (line count of file)
* If both tests pass then we read {file in} parsing each line of customer data
*       - Displays errors for each line that does not parse
*       - Displays the number of errors (if any)
*
* Program then filters the parsed data further
*       - Filter AUD values that are not divisible by 5
*       - NULL each customer with a name that has all change values at 0
* Move null customer towards end of array, shifting valid customers towards start of array
*       - Example: -A = NULL, X = VALID 
*       - (-A <-> X) -> (X <-> -A), 
*       - {[-A], [-B], [-C], [X]}
*       - {[x], [-B], [-C], [-A]}
*
* Count the number of valid customers 
* Assort the correct number of coins for each customer (largest to smallest)
*
* Prompt the user with a menu with the following options:
*       - [1] Search by name                
*               -> ignoring case, searches for a customer with a matching name
*       - [2] Display customer names
*               -> Displays all non-null customer names
*       - [3] Display all customer data
*               -> Displays all customer data: {name, change value, currency, coin variants}
*       - [4] Quit program
*
* Program writes to file {file out} returning the number of lines printed
*
* Displays the values of each major process
*       - Program feedback {First value of file, Line count of file, Unique Customers count of file, Valid customers count, printed line count to file}
*
* Prompt user to hit enter before exit

======== Example Input File =========
3
Tango 86 cents in $USD
Alpha 85 cents in $AUD
Bravo 36 cents in $EUR

======== Example Output File ========
Tango, the change for 86 cents in $USD is 1,1,1,1   // Coins: 50, 25, 10, 1
Alpha, the change for 85 cents in $AUD is 1,1,1,1   // Coins: 50, 20, 10, 5
Bravo, the change for 85 cents in $EUR is 1,1,1,1   // Coins: 20, 10,  5, 1

 ======== Compile and run ========
* Compile: 
*   gcc .\a2_main.c .\program\a2_program.c .\general\a2_general.c .\customer\a2_customer.c .\currency\a2_currency.c .\crud\a2_create.c .\crud\a2_read.c -o a2.exe
* 
* Run:
*   .\a2.exe
*   .\a2.exe .\_data\in_data\coins_g.txt .\_data\out_data\change.csv
*   .\a2.exe .\_data\in_data\coins_b.txt .\_data\out_data\change.csv
* 
*/

int program_pipeline(const int argc, const char *argv[])
{
    const Currency currency_data[MAX_CURRENCY_TYPES] = {USD_DATA, AUD_DATA, EUR_DATA};
    Customer *customer_data;
    char *infile = NULL, *outfile = NULL;

    // Check user argument count first - if one or more values are missing, use defaults
    program_handleArgs(argc, argv, &infile, &outfile);
        
    // We assume that we can read the file, read first line as an integer value
    const int expected_lines = read_handleDataIn(infile, NULL, R_FIRST_LINE);
    if (!program_fileIOResult(expected_lines, infile, ERR_FILE_BAD_READ, ERR_FILE_BAD_FIRST)) 
    {
        program_pauseStatus(QUIT);
        return 1;
    }

    // We assume that the expected entry value may be wrong so we count the actual number of lines
    const int line_count = read_handleDataIn(infile, NULL, R_LINE_COUNT);
    if (!program_fileIOResult(line_count, infile, ERR_FILE_BAD_READ, ERR_FILE_NO_READ)) 
    {
        program_pauseStatus(QUIT);
        return 2;
    }

    // Allocate memory for customers then initialize pointer array for each customer
    customer_data = (Customer*) calloc(line_count, sizeof(Customer));
    customer_initPointers(customer_data, line_count);

    // Read customer data values from file
    const int unique_customers = read_handleDataIn(infile, customer_data, R_CUST_DATA);
    if (!program_fileIOResult(unique_customers, infile, ERR_FILE_BAD_READ, ERR_FILE_NO_READ)) 
    {
        customer_freeMemory(customer_data,  line_count);
        program_pauseStatus(QUIT);
        return 3;
    }
    program_pauseStatus(CONTINUE);


    // Filter customers with illegitimate values
    customer_filterData(customer_data, line_count);

    // Filter customers with null values (shifting all null customers to the right)
    customer_sortNull(customer_data, line_count);

    // Count number of valid customers after sorting
    const int valid_customers = customer_count(customer_data, line_count);

    // Insert coins based on customer's currency values
    customer_handleInsertCoins(customer_data, currency_data, valid_customers);
    program_pauseStatus(CONTINUE);

    // Prompt customer menu -> [1]search, [2]display names, [3]display all, [4]quit
    customer_handleMenu(customer_data, currency_data, valid_customers);

    // Write valid customers to file
    const int printed_customers = create_handleDataOut(customer_data, currency_data, outfile, line_count);
    program_fileIOResult(line_count, infile, ERR_FILE_BAD_CREATE, ERR_FILE_NO_WRITE);

    // Free customers
    customer_freeMemory(customer_data,  line_count);

    // Display pipeline results:
    program_displayPipelineValues(expected_lines, line_count, unique_customers, valid_customers, printed_customers);

    // Press enter to quit (getchar())
    program_pauseStatus(QUIT);
    return 0;
}

int main(const int argument_count, const char *argument_values[])
{
    return program_pipeline(argument_count, argument_values);
}