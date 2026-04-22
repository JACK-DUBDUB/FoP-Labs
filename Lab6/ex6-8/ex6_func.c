


#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include "ex6_func.h"
#include "..\LAB_6_LIB.h"


int handle_readStringLength()
{
    int string_length = 0;
    bool valid = false;
    printf("\n-------- Enter length for a string --------\n");
    do
    {
        printf("\nPlease enter a numerical value to determine string length (1-100): ");
        valid  = read_stringLength(&string_length);

    } while(!valid);

    clear_input_buffer();
    return string_length;
}


bool read_stringLength(int *out_value)
{
    if((read_int(out_value) != true)) {
        printf("\nUser did not enter a numerical value.\n");
        return false;
    }
    if(*out_value > 0 && *out_value <= STRING_LENGTH_MAX) {
        return true;
    }
    else {
        printf("\nUser did not enter a positive integer.\n");
        return false;
    }
}


void handle_readUserString(char *user_string, const int string_length)
{
    printf("Please enter a string: ");
    read_string(user_string, string_length);

    return;
}

void handle_convertToLower(char *user_string)
{
    for (int i = 0; user_string[i] != '\0'; i++)
    {
        user_string[i] = tolower(user_string[i]);
    }
    return;
}

int handle_countVowels(const char *user_string)
{
    int  vowel_count = 0;
    for (int i = 0; user_string[i] != '\0'; i++)
    {
        switch (user_string[i])
        {
            case 'a': case 'e': case 'i': case 'o': case 'u': // Fall-through
            vowel_count++; break;
            default: break;
        }
    }
    return vowel_count;
}

void handle_insertVowels(const char *user_string, char *vowel_string)
{
    int vowel_index = 0;

    for (int i = 0; user_string[i] != '\0'; i++)
    {
        switch (user_string[i])
        {
            case 'a': case 'e': case 'i': case 'o': case 'u': // Fall-through
            vowel_string[vowel_index] = user_string[i]; vowel_index++; break;
            default: break;
        }

    }
    vowel_string[vowel_index] = '\0';
    return;
}


void handle_displayStrings(const char *user_string, enum DISPLAY_STRING condition)
{
    switch (condition) 
    {
        case ORIGINAL: printf("\nOriginal string: "); break;
        case LOWER_CASE_ONLY: printf("\nLower case string: "); break;
        case VOWEL_ONLY: printf("\nVowel only string: "); break;
        default: break;
    }
    printf("%s\n", user_string);
    return;
}

void handle_searchUserString(const char *user_string)
{
    if(!user_string)
        return;

    do 
    {
        char search_value = read_searchValue();
        
        if(!isalpha(search_value))
            break;

        int first_occurence = -1, letter_count = 0;
        search_countAndOccurence(user_string, search_value, &first_occurence, &letter_count);

        if(letter_count)
            printf("\nFirst occurence: %i\nNumber of '%c':  %i\n", first_occurence, search_value, letter_count);
        else
            printf("\nString did not contain any values of '%c'\n", search_value);

        display_eachOccurence(user_string, search_value); // ***Not needed
        program_status_pause(CONTINUE);
    }while (1);

    program_status_pause(QUIT);
    return;
}


char read_searchValue()
{
    printf("\n-------- Search for a character in the string--------");
    printf("\n To search - enter any alphabetical character to search the string.");
    printf("\n To quit   - enter any non-alphabetical character.");
    printf("\n\nEnter a character: ");

    char selector;
    read_char(&selector);
    clear_input_buffer();

    return tolower(selector);
}

void search_countAndOccurence(const char *user_string, const char search_value, int *first_occurence, int *letter_count)
{
    for (int i = 0; user_string[i] != '\0'; i++)
    {
        if (*first_occurence >= 0 && user_string[i] == search_value) {
            (*letter_count)++;
            continue;
        }

        if (*first_occurence < 0 && user_string[i] == search_value) {
            *first_occurence = i;
            (*letter_count)++;
        }
    }
    return;
}

void display_eachOccurence(const char *user_string, const char search_value) // ***Not needed
{
    printf("Each occurence of '%c': ", search_value);
    for (int i = 0; user_string[i] != '\0'; i++)
    {
        if (user_string[i] == search_value)
            printf("[%c]", user_string[i]);
        else
            printf("%c", user_string[i]);
    }
}


