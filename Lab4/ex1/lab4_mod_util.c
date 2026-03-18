#include <stdio.h>
#include "lab4_mod_util.h"

int ReadNumber (int nth)
{
    int n;
    printf("Please enter number %d: ", nth);
    scanf("%d*c", &n);
    return n;
}

int CalculateSum(int n1, int n2, int n3)
{
    return n1 + n2 + n3;
}

void DisplayResult(int sum)
{
    printf("The sum is %d\n", sum);
    return;
}