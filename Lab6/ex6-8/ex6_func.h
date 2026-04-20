#ifndef EX6_FUNC_H
#define EX6_FUNC_H

// Constants
#define STRING_LENGTH_MAX 100

int handle_readStringLength();
bool read_stringLength(int *out_value);

void handle_readUserString(char user_string[], int string_length);

void handle_convertToLower(char user_string[]);
int handle_countVowels(const char user_string[]);
int count_vowels(const char user_string[]);

void handle_insertVowels(const char *user_string, char vowel_string[]);
bool check_isVowel(char c);


void handle_displayStrings(const char *user_string);


void handle_searchUserString(const char *user_string);
char read_searchValue();
void search_userString(const char *user_string, char search_value, int *first_occurence, int *count);



#endif