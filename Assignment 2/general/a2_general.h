#include <stdbool.h>

#ifndef A2_GENERAL_H
#define A2_GENERAL_H

#define READ_INT_ERROR      -1


// reads an integer input from stdin
int read_intInRange(const int min, const int max);

//
int filter_intInRange(const int input, const int min, const int max, const int valid);

//
void read_string(char *buffer, int size);


//
int compare_caseInsensitive(const char *string1, const char *string2);

//
int calculate_intDiv(const int dividend, const int divisor);

//
int calculate_intMod(const int dividend, const int divisor);


#endif
