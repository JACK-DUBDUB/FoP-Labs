#include <stdio.h>

void SortInDescendingOrder(float a, float b)
{
	if (a > b)
	{
		printf("%f\n", a);
		printf("%f\n", b);
	}
	else
	{
		printf("%f\n", b);
		printf("%f\n", a);
	}
}

int main()
{
	float a, b;

	// Read the first number from the user input.
    printf("Enter the first number.\n");
    scanf("%f", &a);

    // Read the second number from the user input.
    printf("Enter the second number.\n");
    scanf("%f", &b);

	SortInDescendingOrder(a, b);

	return 0;
}
