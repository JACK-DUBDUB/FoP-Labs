/**
 * Lecture 5 - Modular Programming (convertBase.c)
 * Algorithm 5.1.1
 */
 
#include <stdio.h>
 
 // Declaring the function prototypes 
 /**
  * min value of x and y
  */
float minValue(float x, float y);
 
 // Defining (implementing) the functions 
 int main()
{
     float A, B;
          
     printf("Enter the first number:");
     scanf("%f", &A);
     
     printf("Enter the second number:");
     scanf("%f", &B);
     
     float C = minValue(A, B);
          
     printf("The min is %f\n", C);
     
     return 0;
 }

float minValue(float x, float y)
{
    float z;
    
    if (x < y)
    {
        z = x;
    }
    else
    {
        z = y;
    }
     
     return z;
}
 
 
 
 
 
 
