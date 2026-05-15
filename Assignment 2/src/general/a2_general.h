#ifndef A2_GENERAL_H
#define A2_GENERAL_H

// ======== General Functions ========

// Reads an integer input from stdin
int read_intInRange(const int min, const int max);

// Filters the integer input
int filter_intInRange(const int input, const int min, const int max, const int valid);

// Reads a string from stdin, (removes '\n') 
void read_string(char *buffer, const int size);

// Compares each char value of each string to check if they are equal (toupper)
int compare_caseInsensitive(const char *string1, const char *string2);

#endif
