#include <stdio.h>
#include <stdbool.h>
#include "../LAB_7_LIB.h"

#ifndef _EX1_FUNC_
#define _EX1_FUNC_

// ---- Constants ----
#define MAX_LINE_LENGTH 512
#define MAX_ENTRY_NUMBER 64 // 64 * (4 + 256 + 4 + 4)
#define MAX_NAME_LENGTH 256

// ---- Structs ----

/*
    Structs and typedef has been a real game changer
    https://www.w3schools.com/c/c_structs.php
    https://www.w3schools.com/c/c_typedef.php 

*/

typedef struct {
    unsigned int id;            // 4
    char name[MAX_NAME_LENGTH]; // 256
    unsigned int age;           // 4
    float wage;                 // 4
} file_data_entries;

// ---- Functions ----

// Create file
void handle_createCSVFile(int line_count, file_data_entries *user_data);

// Read file
int handle_readUserFile(const char *file_argument, file_data_entries *user_data);
int read_userFile(FILE *source_file, file_data_entries *user_data);

// Display file data
void display_userFileData(int line_count, file_data_entries *user_data);

// Search data by name value
void handle_searchDataByName(int line_count, file_data_entries *user_data);
void search_dataByName(int line_count, file_data_entries *user_data, const char *search_value);
bool compare_stringsCaseInsensitive(const char *string1, const char *string2);

#endif




