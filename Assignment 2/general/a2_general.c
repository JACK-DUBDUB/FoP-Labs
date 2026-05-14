#include "../program/a2_program.h"

// ---- READ INT ----

int read_intInRange(const int min, const int max) 
{
    int input;
    do 
    {
        input = 0;

        printf("\nEnter a valid integer value: ");

        input = filter_intInRange(input, min, max, scanf_s("%i", &input));

    } while (!input);

    return input;
}

int filter_intInRange(const int input, const int min, const int max, const int valid)
{
    if (!valid) 
    {
        printf("\nUser did not enter an integer value.\n");
        program_clearInputBuffer();
        return 0;
    }

    if (valid  && getchar() != '\n') 
    {
        printf("\nUser entered an integer value with a non-integer value.\n");
        program_clearInputBuffer();
        return 0;
    }

    if (input < min || input > max) 
    {
        printf("\nUser entered a value outside of range.\n" );
        return 0;
    }

    return input;
}

// ---- READ STRING ---- 

void read_string(char *buffer, const int size)
{
    if (size <= 0)
    {
        return;
    }

    // Empty string check
    if (fgets(buffer, size, stdin) == NULL) 
    { 
        buffer[0] = '\0'; // Cut it short
    }

    int length = strlen(buffer);

    // If the chars inserted don't reach buffer limit
    if(length < size && buffer[length - 1] == '\n') 
    {
        buffer[length - 1] = '\0'; // Replace '\n'
    } 
    else 
    {  // Exceeded buffer limit (probably)
        program_clearInputBuffer();
    }
    return;
}

// ---- CASE INSENSITIVE COMPARISON ----

int compare_caseInsensitive(const char *string1, const char *string2)
{
    if ((string1 == NULL || string2 == NULL) || (strlen(string1) != strlen(string2))) 
    {
         return 0;
    }

    while (*string1 && *string2)
    {
        if (toupper(*string1) != toupper(*string2)) 
        {
             return 0;
        }
        string1++, string2++;
    }
    return 1;
}

// ---- ARITHMETIC ----

int calculate_intDiv(const int dividend, const int divisor)
{
    if (divisor) 
    {
        int quotient = dividend / divisor;
        return quotient;
    }
    else 
    {
        printf("Cannot divide by 0\n");
        return 0;
    }
}

int calculate_intMod(const int dividend, const int divisor)
{
    if (divisor) 
    {
        int remainder = dividend % divisor;
        return remainder;
    }
    else {
        printf("Cannot modulus by 0\n");
        return 0;
    }
}
