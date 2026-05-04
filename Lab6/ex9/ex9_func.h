#ifndef EX9_FUNC_H
#define EX9_FUNC_H

// Constants
#define STRING_LENGTH_MAX 100
#define VOWEL_AMOUNT 5

enum STRING_VOWELS {
    VOWEL_A = 0,
    VOWEL_E = 1,
    VOWEL_I = 2,
    VOWEL_O = 3,
    VOWEL_U = 4
};

enum DISPLAY_STRING {
    ORIGINAL_STRING,
    VOWEL_STRING
};

// Reads the user value for the expected string length (between 1 - 100 inclusive) - verfied by read_stringLength
int handle_readStringLength();
bool read_stringLength(int *out_value);

// Read the user string so that its within the string_length limit
void handle_readUserString(char *user_string, int string_length);

// Count the total number of vowels and the total number of each vowel
int handle_countVowels(const char *user_string, int total_vowels[]);

// Inserts the vowels into  the vowel string - verified its a vowel using check_isVowel()
void handle_insertVowels(const char *user_string, char vowel_string[]);
bool check_isVowel(char c);

// Display the string
void handle_displayStrings(const char *user_string, enum DISPLAY_STRING condition);

// Displays the vowels: totals and first index
void handle_displayVowels(const char *vowel_string, const char *vowels, int total_vowels[]);
void display_vowelTotals(const char *vowels, int total_vowels[]);
void display_vowelFirstIndex(const char *user_string, const char *vowels, int total_vowels[]);

#endif