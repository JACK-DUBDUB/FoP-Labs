#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../LAB_7_LIB.h"
#include "ex1_func.h"

// ---- CREATE ----
// Exercise 4 - create csv file
// Tutorial i used: https://www.w3schools.com/c/c_files.php
void handle_createCSVFile(int line_count, file_data_entries *user_data)
{
    char *filename = "output.csv";
    FILE *output_file;

    // Open file 
    int error_code = fopen_s(&output_file, filename, "w");

    if (!!error_code){
        printf("Error code: %i \n", error_code);
        return;
    }

    for (int i = 0; i < line_count; i++)
    {
        fprintf(output_file, "%s,%u,%.2f\n", user_data[i].name, user_data[i].age, user_data[i].wage);
    }

    // Close file
    fclose(output_file);
    printf("\nFile was succesfully saved as %s\n", filename);
    return;
}


// ---- READ ----

/*
 Apparently fopen() is outdated/deprecated -> so fopen_s() is the current go to for file i/o
 Tutorial i used here: https://www.educative.io/answers/what-is-fopens-in-c
*/

int handle_readUserFile(const char *file_argument, file_data_entries *user_data)
{
    FILE *source_file;
    // Open file
    int error_code = fopen_s(&source_file, file_argument , "r"); 

    if (!!error_code){
        printf("Error code: %i \n", error_code);
        return -1;
    }

    // Count number of line's successfully read.
    int line_count = read_userFile(source_file, user_data);

    // Close file
    fclose(source_file);

    return line_count;
}

int read_userFile(FILE *source_file, file_data_entries *user_data)
{
    char line_buffer[MAX_LINE_LENGTH];
    unsigned int line_count = 0;

    while (fgets(line_buffer, MAX_LINE_LENGTH, source_file) != NULL)
    {
        char _name[MAX_NAME_LENGTH];
        int _age;
        float _wage;

        // Read line -> parse values
        if(sscanf_s(line_buffer, "%s" "%i" "%f", _name, sizeof(_name), &_age, &_wage) == 3){
            user_data[line_count].id = line_count + 1;
            strcpy_s(user_data[line_count].name, sizeof(user_data->name), _name); // sizeof(*user_data).name also works
            user_data[line_count].age = _age;
            user_data[line_count].wage = _wage;
        } 
        else {
            printf("Line '%i' - failed to parse.\n", line_count);
            line_count--; // We might read 11 lines total, but if 1 of them is unsuccessful, then we must not increment it...
        }

        line_count++;
    }
    return line_count;
}


// ---- DISPLAY ----
// Exercise 3 - display the values and the number of lines processed 
void display_userFileData(int line_count, file_data_entries *user_data)
{
    printf("\nNumber of lines parsed read from file: %i", line_count);
    printf("\n\nFile was successfully read.\n\n");
    printf("---- Data Entries ----\n\n");

    for (int i = 0; i < line_count; i++)
    {
        printf("NAME: %s AGE: %u WAGE: %.2f \n", user_data[i].name, user_data[i].age, user_data[i].wage);
    }

    return;
}

// ---- SEARCH ---- 
// Exercise 5 - linear name search
void handle_searchDataByName(int line_count, file_data_entries *user_data)
{
    char search_value[MAX_NAME_LENGTH];
    
    do 
    {
        printf("\n\n---- Search by Name ----\n\n");
        printf("To quit enter value: 'q' \n");
        printf("Enter a name to search: ");

        read_string(search_value, MAX_NAME_LENGTH);

        if (compare_stringsCaseInsensitive("q", search_value))
            break;

        printf("Entries found: \n");
        search_dataByName(line_count, user_data, search_value);

    } while (1);
    
    return;
}

void search_dataByName(int line_count, file_data_entries *user_data, const char *search_value)
{
    int entries_found = 0;
    for (int i = 0; i < line_count; i++)
    {
        // Why not strcmp? -> its a case sensitive comparison which is not user friendly
        bool name_found = compare_stringsCaseInsensitive(user_data[i].name, search_value);

        if (name_found) {
            printf("NAME: %s AGE: %u WAGE: %.2f \n", user_data[i].name, user_data[i].age, user_data[i].wage);
            entries_found++;
        }
    }

    if (!entries_found) {
        printf("Name not found in data.\n");
    }

    return;
}

bool compare_stringsCaseInsensitive(const char *string1, const char *string2)
{
    // Compare lengths first so we dont go out of bounds...
    if (get_string_length(string1) != get_string_length(string2)) {
        return false;
    }
        
    // Compare each char together, to see if its a mismatch
    for (int i = 0; string1[i] != '\0'; i++)
    {   
            char c1 = tolower(string1[i]);
            char c2 = tolower(string2[i]);

            if (c1 != c2)
                return false;
    }

    return true;
}