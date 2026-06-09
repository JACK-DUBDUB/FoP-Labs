

#include <stdlib.h>
#include <stdio.h>

int string_length(char *string);
int concat_string(char* string1, char *string2);
void copy_string(char *string, char *copy, int index, int max);

int main()
{
    char *string1 = "1234";
    char *string2 = "56789";
    int number = atoi(string1);

    printf("String version: %s\n", string1);
    printf("Integer version: %i\n\n\n", number);

    int str_len = concat_string(string1, string2); // A test
    printf("Total length (no null term): %i\n", str_len);

    return 0;
}


int concat_string(char* string1, char *string2)
{
    if (string1 == NULL || string2 == NULL)
    {
        return 0;
    }

    char *copy = string1;

    int str1_len = string_length(string1);
    int str2_len = string_length(string2);


    int total_len = str1_len + str2_len + 1;
    printf("string1 length: %i\n", str1_len);
    printf("String2 length: %i\n", str2_len);
    printf("Total length: %i\n", total_len);

    string1 = calloc(total_len, sizeof(char));
    if (string1 == NULL)
    {
        return 0;
    }

    copy_string(string1, copy, 0, str1_len);
    copy_string(string1, string2, str1_len, total_len);

    printf("Original String: %s\n", copy);
    printf("Second string: %s\n", string2);
    printf("Concat string: %s\n", string1);

    int str_len = string_length(string1);

    free(string1);
    return str_len;
}

void copy_string(char *string, char *copy, int index, int max)
{
    for(int i = 0; i < max; i++)
    {
        string[index] = copy[i];
        index++;
    }
}

int string_length(char *string)
{
    if (string == NULL)
    {
        return 0;
    }

    int length = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        length++;
    }

    return length;
}



/*
// What are structure charts used for?
Structure charts are used for providing a top down view that maps a programs's modular design heirarchy/
The structure chart contains modules and its sub-modules, with arrows (both bi-directional and single directional), that explain the relationships between each other, with receiving and sending (input / ouput) variable values.
The reason structure charts  are used in program development is so that we have a blueprint for how these modules should be implemented for a smooth development process.

An example is of s structure chart is a simple calculate sum program
                [ MAIN ]
{user_int}^      ^                               |
              |         |                               |
              v         v{num1, num2}       v
    [read_int]  [calc_sum]              [print_sum]     








Question 3 Structure chart for Calculating Age in Years and months


Code:

User enters YEARS as a 4 digit integer
User enters MONTHS as an integer between 1 and 12
Calculate the old they will be in May 2024:

// main.c
#include "functions.h"

int main ()
{
    const int currentYear = 2024;
    const int currentMonth = 5;
    
    int uYear = 1;
    while (uYear > 0)
    {
        uYear = read_userYear(currentYear);
        if (uYear < 1)
        {
            break;
        }
        
        int uMonth = 0;
        if (uYear == 2024)
        {
           uMonth = read_userMonth(1, currentMonth);
        }
        else
        {
            uMonth = read_userMonth(1, 12);
        }
        
        int ageInMonths = calc_ageInMonths(currentYear, currentMonth, uYear, uMonth);
        
        displayAge(ageInMonths);
    }   
   
    return 0;
}

// functions.c
#include <stdio.h>

int read_userYear(int max)
{
    user_int =  0;
    do {
        printf("Please enter a number");
         if (scanf("%i", &user_int))
         {
             if (user_int < min || user_int > max)
             {
                 printf("User entered a value outside of range!\n");
                 user_int = 0;
             }
         }
         else
         {
             printf("User entered an invalid value!\n");
             getchar();
         }
    } while (user_int == 0);
    
    return user_int;
}

int read_userMonth(int min, int max)
{
    user_int =  0;
    do {
        printf("Please enter a number");
         if (scanf("%i", &user_int))
         {
             if (user_int < min || user_int > max)
             {
                 printf("User entered a value outside of range!\n");
                 user_int = 0;
             }
         }
         else
         {
             printf("User entered an invalid value!\n");
             getchar();
         }
    } while (user_int == 0);
    
    return user_int;
}

int calc_ageInMonths(int cYear, int cMonth, int uYear, int uMonth)
{
    int result = ((cYear * 12) + cMonth) - ((uYear * 12) + uMonth);
    return result;
}

void displayAge(int ageInMonths)
{
    printf("The person is %i years(s) and %i month(s) old.\n\n", (ageInMonths / 12), (ageInMonths % 12));
    return;
}
*/






