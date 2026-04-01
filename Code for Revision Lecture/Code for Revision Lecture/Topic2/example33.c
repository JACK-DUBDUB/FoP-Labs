#include <stdio.h>

float checkIfEven(int n)
{
    int r = n % 2;
	return (1 - r);
}

int main()
{
    int n;

	printf("Enter the number.\n");
	scanf("%d", &n);

	int isEven = checkIfEven(n);

	if (isEven == 1)
	{
		printf("The number is even.\n");
	}
	else
	{
		printf("The number is odd.\n");
	}

    return 0;
}
