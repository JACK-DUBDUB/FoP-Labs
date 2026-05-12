#include "customer/a2_customer.h"
#include "general/a2_general.h"
#include "program/a2_program.h"
#include "crud/a2_create.h"
#include "crud/a2_read.h"

/*
* 
* 
* -- Compile and run --
* Compile: 
*   gcc .\a2_main.c .\program\a2_program.c .\general\a2_general.c .\customer\a2_customer.c .\crud\a2_create.c .\crud\a2_read.c -o a2.exe
* 
* Run: 
*   .\a2.exe .\_data\in_data\coins_g.txt .\_data\out_data\change.csv
*   .\a2.exe .\_data\in_data\coins_b.txt .\_data\out_data\change.csv
*
*
*/

int program_pipeline(const int argc, const char *argv[])
{
    const Currency currency_data[MAX_CURRENCY_TYPES] = { USD_DATA, AUD_DATA, EUR_DATA };
    Customer *customer_data;
    char *infile = NULL, *outfile = NULL;

    // Check user arguments first - if none/one is provided then use defaults
    program_handleArgs(argc, argv, &infile, &outfile);
        
    // We assume that we can read the file, read first line as an integer value
    const int expected_lines = read_handleCustomerDataIn(infile, NULL, R_FIRST_ROW);
    if (!program_fileProcessResult(expected_lines, infile, ERR_FILE_BAD_READ, ERR_FILE_BAD_FIRST)) {
        program_pauseStatus(QUIT);
        return 2;
    }

    // We assume that the expected entry value may be wrong so we count the actual number of lines
    const int line_count = read_handleCustomerDataIn(infile, NULL, R_LINE_COUNT);
    if (!program_fileProcessResult(line_count, infile, ERR_FILE_BAD_READ, ERR_FILE_NO_READ)) {
        program_pauseStatus(QUIT);
        return 3;
    }

    // Allocate memory for customers then initialize pointer array for each customer
    customer_data = (Customer*) calloc(line_count, sizeof(Customer));
    customer_initPointers(customer_data, line_count);

    // Read customer data values from file
    const int unique_customers = read_handleCustomerDataIn(infile, customer_data, R_CUST_DATA);
    if (!program_fileProcessResult(line_count, infile, ERR_FILE_BAD_READ, ERR_FILE_NO_READ)) {
        customer_freeMemory(customer_data,  line_count);
        program_pauseStatus(QUIT);
        return 4;
    }

    // Filter customers with illegitimate values
    customer_filterData(customer_data, line_count);

    // Filter customers with null values (shifting all null customers to the right)
    customer_sortNull(customer_data, line_count);

    // Count number of valid customers after sorting
    const int valid_customers = customer_count(customer_data, line_count);

    // Insert coins based on customer's currency values
    customer_handleInsertCoins(customer_data, currency_data, valid_customers);

    // Prompt user menu -> [1]search, [2]display names, [3]display all, [4]quit
    customer_menu(customer_data, currency_data, valid_customers);

    // Write valid customers to file
    const int printed_customers = create_handleCustomerDataOut(customer_data, currency_data, outfile, line_count);
    program_fileProcessResult(line_count, infile, ERR_FILE_BAD_CREATE, ERR_FILE_NO_WRITE);

    // Free customers
    customer_freeMemory(customer_data,  line_count);

    // Display results:
    program_displayPipelineValues(expected_lines, line_count, unique_customers, valid_customers, printed_customers);

    // Press enter to quit
    program_pauseStatus(QUIT);
    return 0;
}

int main(const int argument_count, const char *argument_values[])
{
    return program_pipeline(argument_count, argument_values);
}