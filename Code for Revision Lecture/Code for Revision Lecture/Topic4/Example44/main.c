#include <stdio.h>

#include "statistics.h"

int main()
{
    // Input the three numbers
    float A, B, C;
    
    printf("Enter the 1st number: ");
    scanf("%f", &A);
    
    printf("Enter the 2nd number: ");
    scanf("%f", &B);
    
    printf("Enter the 3rd number: ");
    scanf("%f", &C);
    
    // Compute the difference between the max and mean
    float res = ComputeDiffMaxMean(A, B, C);
    
    // Display the result
    printf("The result is: %f\n", res);
    
    return 0;
}
