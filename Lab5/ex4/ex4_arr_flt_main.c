#include <stdio.h>
#include "ex4_arr_flt_func.h"

int main()
{
    // Declaration of arrays (values at elements unassigned)
    float salaries[SIZE];

    printf("-------- Get Salaries --------");
    handle_GetSalaries(salaries);
  
    printf("\n-------- After Pay Rise --------");
    handle_PayRise(salaries);

    return 0;
}
