/**
 * Lecture 5 - Modular Programming (convertBase.c)
 * Algorithm 5.1.1
 */
 
 #include <stdio.h>
 
 // Declaring the function prototypes 
 /**
  * Represent an integer number N in a given base B
  * Input: N and B of type integer
  * Output: representation of N in base B
  */
 int convert2base(int N, int B);
 
 // Defining (implementing) the functions 
 int main()
 {
     int N, B;
          
     printf("Enter the number:");
     scanf("%d", &N);
     
     printf("Enter the base:");
     scanf("%d", &B);
     
     int A = convert2base(N, B);
          
     printf("The conversion of %d into Base %d is %d\n", N, B, A);
     
     return 0;
 }

 int convert2base(int N, int B)
 {
     int A = 0;
     int b = 1;
     
     while (N != 0)
     {         
         int res = N % B;
         N = N / B;
         A = A + res * b;
         b = b * 10;
     }
     
     return A;
 }
 
 
 
 
 
 
