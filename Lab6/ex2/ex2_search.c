#include <ctype.h>
#include <stdio.h>
#include "ex2_search.h"
#include "ex2_func.h"
#include "..\LAB_6_LIB.h"


// -------- Menu for salary search --------

void handle_controlSalariesSearch(float salaries[], const int salary_count)
{
    char selection;
    do
    {
        selection = control_salariesSearch();
        switch (selection) {
            case BELOW_SEARCH:  handle_countSalariesBelow(salaries,  salary_count); break;
            case EXACT_SEARCH:  handle_searchExactSalary(salaries, salary_count); break;
            case QUIT_SEARCH:   printf("\nUser chose to quit search"); break;
            default:            printf("\nUser did not enter a valid menu character\n"); break;
        }
    } while (selection != QUIT_SEARCH);

    program_status_pause(QUIT);
    return;
}

char control_salariesSearch()
{
    printf("\n-------- Search Menu --------");
    printf("\n Please enter a single menu character.");
    printf("\n '%c' - Search and count the salaries below a value", BELOW_SEARCH);
    printf("\n '%c' - Search for exact value", EXACT_SEARCH);
    printf("\n '%c' - Quit search", QUIT_SEARCH);
    printf("\n\nEnter a menu character: ");

    char selector;
    read_char(&selector);
    clear_input_buffer();

   return toupper(selector);
}


// -------- COUNT SALARIES BELOW --------

void handle_countSalariesBelow(float salaries[], const int salary_count)
{
    printf("\n-------- Count salaries below a value --------\n\n");
    printf("Count salaries that earn less than the specified salary search value. \n");
    printf("Enter a search value: ");

    float search_value;

    // read search value
    if (read_userFloat(&search_value)) {
        clear_input_buffer();

        // Count salaries
        int count = count_salariesBelowSearch(salaries, salary_count, search_value);
        
        printf("\nSalary search value of: $ %.2f", search_value);
        printf("\nNumber of employee salaries below $ %.2f : %d", search_value, count);
        printf("\nNumber of employee salaries out of total: %i / %i", count, salary_count);
    }
    else {
        printf("\nUser did not enter a valid value.");
    }

    printf("\n\nReturning to menu.");
    program_status_pause(CONTINUE);
    return;
}

int count_salariesBelowSearch(float salaries[], const int salary_count, float search_value)
{
    int count = 0;
    for(int i = 0; i < salary_count; i++) 
    {
        if(salaries[i] < search_value) {
            count++;
        }
    }
    return count;
}


// -------- EXACT SEARCH --------

void handle_searchExactSalary(float salaries[], const int salary_count)
{
    printf("\n-------- Search for employee with exact salary --------\n\n");
    printf("Enter a salary search value to find employee/s with exact salary.\n");
    printf("Enter a search value: ");

    float search_value;
    if (read_userFloat(&search_value)) {
        clear_input_buffer();
        int count = search_exactSalary(salaries, salary_count, search_value);
        printf("\nExactly %i / %i employees have a salary of: $ %.2f", count, salary_count, search_value);
    }
    else {
        printf("\nUser did not enter a valid value.");
    }

    printf("\n\nReturning to menu.");
    program_status_pause(CONTINUE);
    return;
}

// REGARDING: Exercise 3
// Why would i want to return -1?
// Why would i only want to return a single index?
// What if theres more than one employee with the same salary value?

int search_exactSalary(float salaries[], const int salary_count, float search_value)
{
    int count = 0;
    for (int i = 0; i < salary_count; i++)
    {
        if (salaries[i] == search_value) {
            printf("\nEmployee [%i] has an exact salary of $ %.2f", i + 1, salaries[i]);
            count++;
        }
    }
    return count;
}




