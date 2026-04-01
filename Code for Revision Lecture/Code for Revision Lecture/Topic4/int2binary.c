/**
 * Lecture 5 - Modular Programming
 * Algorithm 5.1.1
 */
 #include <stdio.h>
 
 int main(){
     int N;
          
     printf("Enter the number:");
     scanf("%d", &N);
        
     int A = 0;
     int b = 1;
     
     while (N != 0){         
         int res = N % 2;
         N = N / 2;
         A = A + res * b;
         b = b * 10;
     }
     
     printf("The binary representation of %d is %d\n", N, A);
     
     return 0;
 }