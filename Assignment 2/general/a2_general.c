#include <ctype.h>
#include "a2_general.h"
#include "../program/a2_program.h"
#include <stdio.h>
#include <string.h>



// ---- get user input functions ----
int read_intInRange(const int min, const int max) 
{
    int input = -1;
    do 
    {
        printf("\nEnter a valid integer value: ");
        scanf_s("%i", &input);
        input = filter_intInRange(input, min, max);

    } while (input == -1);
    return input;
}

int filter_intInRange(const int input, const int min, const int max)
{
    if (input == READ_INT_ERROR ) {
        printf("\nUser did not enter an integer value.\n");
        program_clearInputBuffer();
        return READ_INT_ERROR ;
    }

    if (input == READ_INT_ERROR  && getchar() != '\n') {
        printf("\nUser entered an integer value with a non-integer value.\n");
        program_clearInputBuffer();
        return READ_INT_ERROR;
    }

    if (input < min || input > max) {
        printf("\nUser entered a value outside of range.\n" );
        return READ_INT_ERROR;
    }

    return input;
}

void read_string(char *buffer, const int size)
{
    if (size <= 0){
        return;
    }
    
    program_clearInputBuffer();

    // Empty string check
    if (fgets(buffer, size, stdin) == NULL) { 
        buffer[0] = '\0'; // Cut it short
    }

    int length = strlen(buffer);

    // If the chars inserted don't reach buffer limit
    if(length < size && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0'; // Replace '\n'
    } else {
        // Probably exceeded buffer limit so clear all
        program_clearInputBuffer();
    }
    return;
}


// Assumption -> what if names are same but not same case
bool compare_caseInsensitive(const char *string1, const char *string2)
{
    // Filter
    if ((string1 == NULL || string2 == NULL) || (strlen(string1) != strlen(string2))) {
         return false;
    }
       
    // Compare each val
    while (*string1 && *string2)
    {
        if (toupper(*string1) != toupper(*string2)) 
            return false;

        string1++, string2++;
    }
    return true;
}

int calculate_intDiv(const int dividend, const int divisor)
{
    int quotient = dividend / divisor;
    return quotient;
}

int calculate_intMod(const int dividend, const int divisor)
{
    int remainder = dividend % divisor;
    return remainder; 
}
