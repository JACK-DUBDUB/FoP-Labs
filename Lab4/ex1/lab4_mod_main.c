/**
 * How to compile
 * 
 * gcc ".\filename1.c" ".\filename2.c" -o program
 * 
 */

#include <stdio.h>
#include "lab4_mod_util.h"

int main()
{
    int n1, n2, n3;
    int sum;

    n1 = ReadNumber(1);
    n2 = ReadNumber(2);
    n3 = ReadNumber(3);

    sum = CalculateSum(n1, n2, n3);
    DisplayResult(sum);

    return 0;
}