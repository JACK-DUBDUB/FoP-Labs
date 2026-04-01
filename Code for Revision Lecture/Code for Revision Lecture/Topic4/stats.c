#include <stdio.h>

#include "statistics.h"

int main(){
    
    // Input the three numbers
    float A, B, C;
    
    printf("Enter the 1st number: ");
    scanf("%d", &A);
    
    printf("Enter the 2nd number: ");
    scanf("%d", &B);
    
    printf("Enter the 3rd number: ");
    scanf("%d", &C);
    
    // Compute the difference between the max and mean
    floar res = ComputeDiffMaxMean(A, B, C);
    
    // Display the result
    printf("The result is: %f\n", res);    
    
    return 0;
}

float ComputeDiffMaxMean(float A, float B, float C);
float ComputeMax(float A, float B, float C);
float ComputeMean(float A, float B, float C);
float ComputeDiff(float A, float B);


#include "statistics.h"

float ComputeDiffMaxMean(float A, float B, float C){
    
    float res;
    
    // write the code here
    
    return res;
}

float ComputeMax(float A, float B, float C){
        
    float res;
    
    // write the code here
    
    return res;
}

float ComputeMean(float A, float B, float C){
        
    float res;
    
    // write the code here
    
    return res;
}

float ComputeDiff(float A, float B){
        
    float res;
    
    // write the code here
    
    return res;
}




