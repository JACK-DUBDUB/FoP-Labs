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



int handle_readStringLength();
bool read_stringLength(int *out_value);

void handle_readUserString(char user_string[], int string_length);


int handle_countVowels(const char user_string[], int total_vowels[]);


void handle_insertVowels(const char *user_string, char vowel_string[]);
bool check_isVowel(char c);


void handle_displayString(const char *user_string);

void handle_displayVowels(const char *vowel_string, int total_vowels[]);
void display_vowelTotals(const int vowels[], int total_vowels[]);
void display_vowelFirstIndex(const char *vowel_string, const int vowels[], int total_vowels[]);

#endif