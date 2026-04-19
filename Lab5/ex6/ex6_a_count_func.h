#ifndef EX6_FUNC_H
#define EX6_FUNC_H

// ---- Defined Constant ----
// String limit + null term
#define MAX_MSG_LEN 101

// Case difference
#define CONVERT_CAP 32 // 'a' - 'A'

// Case type
#define CASE_SENSITIVE 1
#define CASE_INSENSITIVE 2

// ---- Functions ----

// get string used for comparison logic
void read_userString(char buffer[], int size);

// Search modules
void handle_searchModules(char userString[], int strlen);
char read_searchChar();
void count_caseSensitive(char userString[], int strlen, char cSearch);
void count_caseInsensitive(char userString[], int strlen, char cSearch);

#endif