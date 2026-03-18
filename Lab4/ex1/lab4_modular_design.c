#include <stdio.h>

int ReadNumber (int nth);
int CalculateSum(int n1, int n2, int n3);
void DisplayResult(int sum);

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