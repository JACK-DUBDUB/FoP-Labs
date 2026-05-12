#include <stdio.h>
#include <stdbool.h>
#include "../program/a2_program.h"
#include "../general/a2_general.h"


void program_handleArgs(const int arg_count, const char *arg_values[], char **infile, char **outfile)
{   
    if (arg_count <= 1) {
        program_displayErrors(ERR_PRGM_NO_ARG, NULL);
        *infile = DEFAULT_IN_FILE;
        *outfile = DEFAULT_OUT_FILE;
        return;
    }
    else if (arg_count == 2) {
        program_displayErrors(ERR_PRGM_NO_OUT, NULL);
        *infile = (char*)arg_values[1];
        *outfile = DEFAULT_OUT_FILE;
        return;
    }
    else if (arg_count > 3) {
        program_displayErrors(ERR_PRGM_MANY_ARG, NULL);
    }
    *infile = (char*)  arg_values[1]; 
    *outfile = (char*) arg_values[2]; 
    return;
}

bool program_fileProcessResult(const int value, const char *file_name, const int error1, const int error2)
{
    if (value < 0) {
        program_displayErrors(error1, file_name);
        return false;
    }
    else if (!value){
        program_displayErrors(error2, file_name);
        return false;
    }
    return true;
}

void program_displayErrors(const enum ERROR_MESSAGES error, const char *file_name)
{
    switch (error) 
    {   // -- Program args --
        case ERR_PRGM_NO_ARG:       
            printf("\nERROR - Missing two argument values\n\n-> Using default input/output files: '%s', '%s'\n\n", DEFAULT_IN_FILE, DEFAULT_OUT_FILE); 
            break;
        case ERR_PRGM_NO_OUT:       
            printf("\nERROR - Missing argument output value\n\n-> Using default output file: '%s' \n\n", DEFAULT_OUT_FILE); 
            break;
        case ERR_PRGM_MANY_ARG:     
            printf("\nERROR - Provided too many arguments\n-> Using first two arguments provided\n\n"); 
            break;

        // -- Read file --
        case ERR_FILE_BAD_READ:     
            printf("\nERROR - Failed to open file '%s' in 'r' mode\n\n", file_name); 
            break;
         case ERR_FILE_BAD_FIRST:      
            printf("\nERROR - First row value of file '%s'could not be read as a valid positive integer \n\n", file_name); 
            break;
        case ERR_FILE_NO_READ:      
            printf("\nERROR - Could not read lines of file '%s' in 'r' mode \n\n", file_name); 
            break;

        // -- Create file --
        case ERR_FILE_BAD_CREATE:   
            printf("\nERROR - Failed to create file '%s' in 'w' mode. \nFile may still be open and/or missing permissions.\n\n", file_name); 
            break;
        case ERR_FILE_NO_WRITE:     
            printf("\nERROR - Program did not write any lines to output file '%s' \n\n", file_name); 
            break;
        default: 
            break;
    }
    return;
}

void program_displayPipelineValues(const int expected_l, const int counted_l, const int uniq_c, const int valid_c, const int printed_c)
{
    printf("\n\n---- Program Feedback ----\n");
    printf("Expected lines:  \t%i\n", expected_l);
    printf("Counted lines:   \t%i\n", counted_l);
    printf("Unique customer: \t%i\n", uniq_c);
    printf("Valid customers: \t%i\n", valid_c);
    printf("Printed entries: \t%i\n", printed_c);
    return;
}

void program_clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return;
}

void program_pauseStatus(const enum PROGRAM_STATUS status)
{
    char *prompt;
    switch (status) 
    {
        case CONTINUE: prompt = "continue"; break; 
        case QUIT: prompt = "quit"; break;
    }
    printf("\nPress enter to %s program...", prompt);
    getchar();
    printf("\n");
    return;
}
