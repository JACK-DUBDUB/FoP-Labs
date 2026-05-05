#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "LAB_7_LIB.h"
#include <stdbool.h>

size_t get_string_length(const char *string)
{
    // Invalid/empty string
    if (!string) {
        return 0;
    }

    // This works as well:
    // size_t count = 0;
    // while(string[count] != '\0') {count++;} 
    // return count;

    const char *ptrSearch = string;
    while (*ptrSearch) { // while not '\0' 
        ptrSearch++;
    }

    // Return a pointer subtraction 
    // *** This will only work IF they point to the exact same array***
    // In essence it is essentially: [4] - [0] = 4
    // But in actuallity:
    // Where: 
    //      - [f] [a] [f] [o] ['\0']
    //      -  ^   ^   ^   ^    ^
    //      -  0   1   2   3    4
    //      - address0 = 0x1000
    //      - address1 = 0x1001    
    //      - address2 = 0x1002
    //      - address3 = 0x1003    
    //      - address4 = 0x1004  
    //  
    // Subtraction:
    //      - address4  - address0  = 4
    //      - 0x1004    - 0x1000    = 4
    //
    // Therefore we return a value of 4.
    return ptrSearch - string;
}

void read_string(char *buffer, size_t size)
{
    if (size <= 0){
        return;
    }

    // Empty string check
    if (fgets(buffer, size, stdin) == NULL) { 
        buffer[0] = '\0';
        return;
    }

    // Find null term to get length -> O(n) approach
    size_t len = get_string_length(buffer);

    // If the chars inserted don't reach buffer limit
    if(len < size && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        clear_input_buffer();
    }
    return;
}

bool read_float(float *out_value)
{
    if (scanf_s("%f", out_value) != 1) {
        clear_input_buffer();
        return false;
    } else {
        return true;
    }
}

bool read_int(int *out_value)
{
    if (scanf_s("%i", out_value) != 1) {
        clear_input_buffer();
        return false;
    } else {
        return true;
    }
}

bool read_char(char *out_value)
{
    if (scanf_s("%c", out_value) != 1) {
        clear_input_buffer();
        return false;
    } else {
        //clear_input_buffer();
        return true;
    }
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return;
}

// Status options: CONTINUE, QUIT
void program_status_pause(enum PROGRAM_STATUS status)
{
    char *prmpt;
    switch (status) 
    {
        case CONTINUE: prmpt = "continue"; break; 
        case QUIT: prmpt = "quit"; break;
    }
    printf("\nPress enter to %s program...", prmpt);
    getchar();
    printf("\n");
    return;
}