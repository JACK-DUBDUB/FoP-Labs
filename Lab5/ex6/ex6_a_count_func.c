#include <ctype.h>
#include <stdio.h>
#include "ex6_a_count_func.h"
#include "..\LAB_5_LIB.h"

void read_userString(char buffer[], int size )
{
    printf("Character limit: %i\n", size - 1);
    printf("Please enter a string: ");
    read_string(buffer, size);
    return;
}

char read_searchChar()
{
    char cSearch = 0;
    do {
        // Prompt user
        printf("\nEnter an alphabetical value to search the string (case-insensitive): ");

        // Read value
        read_char(&cSearch);

        printf("Char entered: %c \n", cSearch);

        // isUpper
        if(isalpha((cSearch))){
            cSearch = toupper(cSearch);
            break;
        }

        printf("\nUser did not enter an alphabetical letter.\n");

    } while (1);

    return cSearch;
}

void handle_searchModules(char userString[], int strlen)
{
    // Part A: Case-sensitive count 'a'
    char cSearch = 'a';
    count_caseSensitive(userString, strlen, cSearch);
    program_status_pause(CONTINUE);

    // Part B: Case-insensitive count of 'A'
    cSearch = 'A';
    count_caseInsensitive(userString, strlen, cSearch); // Expects uppercase input
    program_status_pause(CONTINUE);

    // Part C: Case-insensitive specified user char search.
    cSearch = read_searchChar();
    count_caseInsensitive(userString, strlen, cSearch);

    clear_input_buffer();
    return;
}

// Case sensitive letter count
void count_caseSensitive(char userString[], int strlen, char cSearch)
{
    int count = 0;

    printf("\n---- Case sensitive search ----\n");
    printf("\nFind number of '%c'", cSearch);

    for (int i = 0; i < strlen; i++) {
        if (userString[i] == cSearch) {
            count++;
        }
    }

    printf("\nTotal: %i\n", count);
    return;
}

// Case insensitive letter count
void count_caseInsensitive(char userString[], int strlen, char cSearch)
{
    int count = 0;

    printf("\n---- Case insensitive search ----\n");
    printf("Find number of '%c' and '%c'", cSearch, tolower(cSearch));

    // Get the number of values
    for (int i = 0; i < strlen; i++)  {
        if (toupper(userString[i]) == cSearch) {
            count++;
        }
    }

    printf("\nTotal: %i\n", count);
    return;
}