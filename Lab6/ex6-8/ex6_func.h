#ifndef EX6_FUNC_H
#define EX6_FUNC_H

#include <stdbool.h>

enum DISPLAY_STRING{
    ORIGINAL,
    LOWER_CASE_ONLY,
    VOWEL_ONLY
};


// Constants
#define STRING_LENGTH_MAX 100



// Module handles the read of a user input of type int
// Process will loop until a valid number has been entered (between 1-100)
int handle_readStringLength(void);
bool read_stringLength(int *out_value);

// Module reads the user's string input
void handle_readUserString(char *user_string, int string_length);

// Module converts the user string's capital letters to lowercase: ABCDEFGHIJKLMNOPQRSTUVWXYZ -> abcdefghijklmnopqrstuvwxyz
void handle_convertToLower(char *user_string);

// Module counts the vowels of the user string which determines the vowel_string's length
int handle_countVowels(const char *user_string);

// Module inserts vowels into vowel_string and a null terminator 
void handle_insertVowels(const char *user_string, char *vowel_string);

// Displays the user string dependant on condition
void handle_displayStrings(const char *user_string, enum DISPLAY_STRING condition);

// ---- Search the string modules ----
// Modules control if the user wants to quit searching -> if non alphabetic value then quit
void handle_searchUserString(const char *user_string);
char read_searchValue();
void search_countAndOccurence(const char *user_string, const char search_value, int *first_occurence, int *letter_count);



#endif