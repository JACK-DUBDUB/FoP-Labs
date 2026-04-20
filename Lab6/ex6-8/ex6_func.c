


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
        printf("\nPlease enter a numerical length for a string between 1-100 ");
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


void handle_readUserString(char user_string[], const int string_length)
{
    printf("Please enter a string: ");
    read_string(user_string, string_length);

    return;
}

void handle_convertToLower(char user_string[])
{
    if (!user_string){
        return;
    }

    for (int i = 0; user_string[i] != '\0'; i++)
    {
        user_string[i] = tolower(user_string[i]);
    }

    return;
}

int handle_countVowels(const char user_string[])
{
    int  vowel_count = 0;

    for (int i = 0; user_string[i] != '\0'; i++)
    {
        if(check_isVowel(user_string[i])) {
            vowel_count++;
        }
    }

    return vowel_count;
}

void handle_insertVowels(const char *user_string, char vowel_string[])
{
    if(!vowel_string){
        return;
    }

    int vowel_index = 0;

    while(*user_string)
    {
        if(check_isVowel(*user_string)) {
            vowel_string[vowel_index] = *user_string;
            vowel_index++;
        }

        user_string++;
        
        if(!*user_string)
            vowel_string[vowel_index] = '\0';
    }
    return;
}

bool check_isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

void handle_displayStrings(const char *user_string)
{
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
        

        if(isalpha(search_value)) {
            int count = 0;
            int first_occurence = -1;
            search_userString(user_string, search_value, &first_occurence, &count);
            if(count){
                printf("\nFirst occurence: %i", first_occurence);
                printf("\nNumber of '%c':  %i\n", search_value, count);
            }
            else{
                printf("\nString did not contain any values of '%c\n", search_value);
            }
        }
        else {
            printf("\nUser chose to quit program.");
            break;
        }
    }while (1);

    program_status_pause(QUIT);
    return;
}

char read_searchValue()
{
    printf("\n-------- Search for a character in the string--------");
    printf("\n To search - Please enter a alphabetical character to search the string.");
    printf("\n To quit   - Please enter any non alphabetical character.");
    printf("\n\nEnter a character: ");

    char selector;
    read_char(&selector);
    clear_input_buffer();

    return tolower(selector);
}


void search_userString(const char *user_string, char search_value, int *first_occurence, int *count)
{
    for(int i = 0; user_string[i] != '\0'; i++)
    {
        if(user_string[i] == search_value)
            (*count)++;

        if(*first_occurence < 0 && user_string[i] == search_value)
            *first_occurence = i;
    }

    return;
}


