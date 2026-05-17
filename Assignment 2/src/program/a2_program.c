#include "../program/a2_program.h"
#include "../crud/a2_read.h"
#include "../crud/a2_create.h"



// ---- PIPELINE PHASES ---- //

int program_fileRead(const int argc, const char **argv, char **infile, char **outfile, int *expected_lines, int *line_count)
{
    // Check user argument count first - if one or more values are missing, use defaults
    program_handleArgs(argc, argv, infile, outfile);

    // We assume that we can read the file, read first line as an integer value
    read_handleDataIn(*infile, NULL, R_FIRST_LINE, expected_lines);

    // We assume that the expected entry value may be wrong so we count the actual number of lines before allocating any memory
    read_handleDataIn(*infile, NULL, R_LINE_COUNT, line_count);

    return 1;
}


int program_loadData(Customer *customers, const Currency *currencies, const int rows, const char *infile, int *unique_customers, int *valid_customers)
{
    // Read customer data values from file
    if(!read_handleDataIn(infile, customers, R_CUST_DATA, unique_customers))
    {
        if (!*unique_customers)
        {
            printf("\nPROGRAM ERROR - Could not parse any lines of file '%s' in 'r' mode \n\n", infile); 
        }
         return 0;
    }

    // Filter customers with illegitimate values
    customer_filterData(customers, rows);

    // Sort the customers, returning the number of non-null customers
    *valid_customers = customer_sortNull(customers, rows);

    if(!*valid_customers)
    {
        printf("No valid customers remaining\n");
        return 0;
    }

    // Insert coins based on customer's currency values
    customer_insertCoins(customers, currencies, *valid_customers);

    return 1;
}


int program_fileWrite(const Customer *customers, const Currency *currencies, const int rows, const char *outfile, int *printed_customers)
{
    if(!create_handleDataOut(customers,currencies, outfile, rows, printed_customers))
    {
        if (!*printed_customers)
        { 
            printf("\nPROGRAM ERROR - Program did not write any lines to output file '%s' \n\n", outfile);
            return 0;
        }
    }
    return 1;
}


// ---- PROCESSES ---- //

void program_handleArgs(const int argc, const char **argv, char **infile, char **outfile)
{   
    if (argc <= 1) 
    {
        printf("\nPROGRAM ERROR - Missing two argument values\n\n-> Using default input/output files: '%s', '%s'\n\n", DEFAULT_IN_FILE, DEFAULT_OUT_FILE); 
        *infile = DEFAULT_IN_FILE;
        *outfile = DEFAULT_OUT_FILE;
        
        return;
    }
    else if (argc == 2) 
    {
        printf("\nPROGRAM ERROR - Missing argument output value\n\n-> Using default output file: '%s' \n\n", DEFAULT_OUT_FILE); 
        *infile = (char*)argv[1];
        *outfile = DEFAULT_OUT_FILE;
        return;
    }
    else if (argc > 3) 
    {
        printf("\nERROR - Provided too many arguments\n-> Using first two arguments provided\n\n"); 
    }

    // Using user provided values
    *infile = (char*)  argv[1]; 
    *outfile = (char*) argv[2];
    return;
}


void program_displayResults(const int expected_l, const int counted_l, const int uniq_c, const int valid_c, const int printed_c)
{
    printf("\n\n---- Program Feedback ----\n");
    printf("Expected lines:  \t%i\n", expected_l);
    printf("Counted lines:   \t%i\n", counted_l);
    printf("Unique customer: \t%i\n", uniq_c);
    printf("Valid customers: \t%i\n", valid_c);
    printf("Printed entries: \t%i\n", printed_c);
    return;
}

// ---- CONTROL---- //

void program_clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return;
}

void program_pause(const enum PROGRAM_PAUSE msg)
{
    switch (msg) 
    {
        case MSG_CONTINUE:
            printf("\nPress enter to continue program...");
            break; 
        case MSG_QUIT: 
            printf("\nPress enter to quit program..."); 
            break;
    }
    getchar();
    printf("\n");
    return;
}
