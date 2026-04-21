#ifndef EX2_SEARCH_H
#define EX2_SEARCH_H

enum CONTROL_SEARCH {
    BELOW_SEARCH = 'A',
    EXACT_SEARCH = 'S',
    QUIT_SEARCH  = 'Q'
};


void handle_controlSalariesSearch(float salaries[], const int salary_count);
char control_salariesSearch();

void handle_countSalariesBelow(float salaries[], const int salary_count);
int count_salariesBelowSearch(float salaries[], const int salary_count, float search_value);

void handle_searchExactSalary(float salaries[], const int salary_count);
int search_exactSalary(float salaries[], const int salary_count, float search_value);

#endif