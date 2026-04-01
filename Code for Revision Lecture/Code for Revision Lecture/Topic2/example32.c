#include <stdio.h>

float ComputeAverage(float a, float b)
{
    float avg;
    avg = (a + b) / 2;
    return avg;
}

int main()
{
    float mark1, mark2, avgMark;

    // Read the grade of the first student from the user input.
    printf("Enter the grade of the first student.\n");
    scanf("%f", &mark1);

    // Read the grade of the second student from the user input.
    printf("Enter the grade of the second student.\n");
    scanf("%f", &mark2);

    avgMark = ComputeAverage(mark1, mark2);

    printf("The average mark is: %f\n", avgMark);

    return 0;
}