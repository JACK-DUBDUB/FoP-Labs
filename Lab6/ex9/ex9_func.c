


#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include "ex9_func.h"
#include "..\LAB_6_LIB.h"


int handle_readStringLength()
{
    int string_length = 0;
    bool valid = false;
    printf("\n-------- Enter length for a string --------\n");
    do
    {
        printf("\nPlease enter a numerical length for a string between 1-%i: ", STRING_LENGTH_MAX);
        valid  = read_stringLength(&string_length);

    } while(!valid);

    clear_input_buffer();
    return string_length + 1; // for the null term
}

bool read_stringLength(int *out_value)
{
    if ((read_int(out_value) != true)) {
        printf("\nUser did not enter a numerical value.\n");
        return false;
    }
    if (*out_value > 0 && *out_value <= STRING_LENGTH_MAX) {
        return true;
    }
    else {
        printf("\nUser did not enter a positive integer.\n");
        return false;
    }
}


// ---- Read string from user ----

void handle_readUserString(char *user_string, const int string_length)
{
    printf("Please enter a string: ");
    read_string(user_string, string_length);
    return;
}


// ---- Count the vowels of the string ----

int handle_countVowels(const char *user_string, int total_vowels[])
{
    int vowel_count = 0;
    for (int i = 0; user_string[i] != '\0'; i++) 
    {
        switch(tolower(user_string[i])) {
            case 'a': total_vowels[VOWEL_A]++; vowel_count++; break; 
            case 'e': total_vowels[VOWEL_E]++; vowel_count++; break; 
            case 'i': total_vowels[VOWEL_I]++; vowel_count++; break; 
            case 'o': total_vowels[VOWEL_O]++; vowel_count++; break; 
            case 'u': total_vowels[VOWEL_U]++; vowel_count++; break;
            default: break; 
        }
    }
    return vowel_count;
}

void handle_insertVowels(const char *user_string, char *vowel_string)
{
    int vowel_index = 0;
    while (*user_string)
    {
        switch (tolower(*user_string)) { // Fall-through if vowel:
            case 'a': case 'e': case 'i': case 'o': case 'u': 
            vowel_string[vowel_index] = *user_string; vowel_index++; break;
            default: break;
        }
        user_string++;
    }

    vowel_string[vowel_index] = '\0'; // Final index element must be null
    return;
}


void handle_displayStrings(const char *user_string, enum DISPLAY_STRING condition)
{
    switch (condition) 
    {
        case ORIGINAL_STRING: printf("\nOriginal string: "); break;
        case VOWEL_STRING: printf("\nVowel string: "); break;
        default: break;
    }
    printf("%s\n", user_string);
    return;
}

void handle_displayVowels(const char *user_string, const char *vowels, int total_vowels[])
{
    program_status_pause(CONTINUE);

    display_vowelTotals(vowels, total_vowels);
    program_status_pause(CONTINUE);

    display_vowelFirstIndex(user_string, vowels, total_vowels);
    program_status_pause(QUIT);
    return; 
}

void display_vowelTotals(const char *vowels, int total_vowels[])
{
    printf("\n-------- Display Vowel Totals --------\n\n");
    for (int i = 0; vowels[i] != '\0'; i++)
    {
        if (total_vowels[i])
            printf("Total amount of '%c': %i\n", vowels[i], total_vowels[i]);
        else
            printf("String does not contain vowel '%c'\n", vowels[i]);
    }
    return;
}

void display_vowelFirstIndex(const char *user_string, const char *vowels, int total_vowels[])
{
    printf("\n-------- Display First Index Of Vowels --------\n\n");

    for (int i = 0; vowels[i] != '\0'; i++) // {A, E, I, O, U, \0}
    {
        // If total is equal to 0
        if (!total_vowels[i]) {
            printf("String does not contain vowel '%c'\n", vowels[i]);
            continue;
        }

        // Else we find the first index
        for(int j = 0; user_string[i] != '\0'; j++)
        {
            if (tolower(user_string[j]) == vowels[i]) {
                printf("First index of vowel '%c': Index [%i]\n", vowels[i], j);
                break;
            }
        }
    }
    
    return;
}