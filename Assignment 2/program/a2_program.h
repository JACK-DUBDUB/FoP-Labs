#ifndef A2_PROGRAM_H
#define A2_PROGRAM_H

// ======= ENUMS ========

enum PROGRAM_STATUS { CONTINUE, QUIT };
enum ERROR_MESSAGES 
{
    // Program
    ERR_PRGM_NO_ARG     = 0, // No arguments
    ERR_PRGM_NO_OUT     = 1, // Missing one argument
    ERR_PRGM_MANY_ARG   = 2, // Included too many args
    // Read
    ERR_FILE_BAD_READ   = 3, // Couldn't read from file
    ERR_FILE_BAD_FIRST  = 4, // Couldn't read value OR value was <= 0
    ERR_FILE_NO_READ    = 5, // No lines read from file
    // Create
    ERR_FILE_BAD_CREATE = 6, // Couldn't create file
    ERR_FILE_NO_WRITE   = 7, // Did not write any lines to file
};

// File strings
#define DEFAULT_IN_FILE     "./_data/in_data/coins_g.txt"
#define DEFAULT_OUT_FILE    "./_data/out_data/change.csv"


// ======== FUNCTIONS ======== //

// ---- Program flow ---- //

// Checks if the user included any args when they launched program
void program_handleArgs(const int arg_count, const char *arg_values[], char **infile, char **outfile);

// Post file process value is checked if(val < 1), errors indicate what can go wrong for each read/write process
// If number calls displayErrors()
bool program_fileProcessResult(const int value, const char *file_name, const int error1, const int error2);

// Displays the exact error of what went wrong
void program_displayErrors(const enum ERROR_MESSAGES error, const char *file_name);

// Displays all the program values received from each major process of the program
void program_displayPipelineValues(const int expected_l, const int counted_l, const int uniq_c, const int valid_c, const int printed_c);


// ---- Helpers ---- //

// Clears the input buffer
void program_clearInputBuffer(void);

// Pauses the program with a getchar()
void program_pauseStatus(enum PROGRAM_STATUS status);


#endif