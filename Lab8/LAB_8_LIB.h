
#ifndef LAB_5_MY_LIBRARY_H
#define LAB_5_MY_LIBRARY_H


#include <stddef.h>

enum PROGRAM_STATUS {
    CONTINUE,
    QUIT
};

///////////////////////////////
// ---- Getters / Query ---- //
///////////////////////////////

//  GET LENGTH OF STRING - 19/08/2026
//  @foreword
//  - First of all - I'm well aware strlen() already exists -> in fact I checked out the source code for it!
//  - BUT this doesn't mean I can't design my own basic version of it!
//  @Brief: 
//  - This is a simple linear search "0(n)" that looks for a value of 0 or '\0' null term
//  @Func: 
//  - If the string is of size 0 -> return 0 
//  - Using a while loop, we increment the pointer till a value of '0' is found
//  - returns a value using a pointer subtraction 
//  - I provide a more thorough explanation in the code itself
//  @param: 
//  - string: of type const char array -> your string...
//  @returns: 
//  - size_t unsigned long long int value -> normalizes depending on the integer type "i think," though some folks say type casting before returning is better.
size_t get_string_length(const char *string);


/////////////////////////////////////////
// ---- Setters / Read CLI input  ---- //
/////////////////////////////////////////


//  READ STRING FUNCTION - 19/04/2026
//  @Brief: 
//  - Reads a user input to insert values into a string.
//  @Func: 
//  - Reads a user cli input using stdin to enter values into a string up to a specified size
//  - Checks if the amount of values entered is below the buffer limit, find the '\n' and replace it with '\0'
//  @param: 
//  - buffer: of type char array (string)
//  - size: of type unsigned long long 
//  @returns: 
//  - The user's char values they inserted into the buffer
void read_string(char *buffer, size_t size);

//  READ CHAR FUNCTION - 19/04/2026
//  @Brief: 
//  - Reads a user input value of type char 
//  @Func: 
//  - Reads a user cli input using stdin to enter a char value
//  - clears the input buffer once completed 
//  @param: 
//  - out_value: of type char -> must have a return address if the char value regardless of validity
//  @returns: 
//  - out_value: the char value they inserted into the input buffer
//  - int: the user input's validity 
int read_char(char *out_value);

//  READ INT FUNCTION - 19/04/2026
//  @Brief: 
//  - Reads a user input value of type integer 
//
//  @Func: 
//  - Reads a user cli input using stdin to enter an int value
//  - clears the input buffer if the user entered a non-integer value
//
//  @param: 
//  - out_value: of type int -> must have a return address for the int value regardless of validity
//
//  @returns: 
//  - out_value: the int value they inserted into the input buffer
//  - int: the user input's validity 
int read_int(int *out_value);

//  READ FLOAT FUNCTION - 19/04/2026
//  @Brief: 
//  - Reads a user input value of type float
//
//  @Func: 
//  - Reads a user cli input using stdin to enter an int value
//  - clears the input buffer if the user entered a non-float/numeric value
//
//  @param: 
//  - out_value: of type float -> must have a return address for the float value regardless of validity
//
//  @returns: 
//  - out_value: the float value they inserted into the input buffer
//  - int: the user input's validity 
int read_float(float *out_value);


//  CLEAR INPUT BUFFER - 19/04/2026
//  @Brief: 
//  - Void function that clears the input buffer of left over values
//  @Func: 
//  - while loop that clears the remaining char values using the getchar() function until it finds '\n' and EOF
//  @param: - (void)
//  @returns: - (void)
void clear_input_buffer(void);


//////////////////////////////
// ---- Display Status ---- //
//////////////////////////////

// STATUS OPTIONS: CONTINUE, QUIT
//  @Brief: 
//  - Displays a cli message to the user prompting them to press enter to continue
//  @Func: 
//  - Displays a function based on the status inserted into the enum parameter
//  - Pauses the program with a getchar function, continuing once the user presses enter
//  @param: 
//  - enum status: CONTINUE, QUIT
//  @returns: - (void)
void program_status_pause(enum PROGRAM_STATUS status);

#endif /* LAB_8_MY_LIBRARY_H */
