/**
 * 10/03/2026 
 * Jack du boulay - 32712899 
 * Exercise 7 -> Interest
 * This program calculates the montly payments for interest loans, to do so, calculate total interest, then divide by (months * years)
 * Program requires 3 inputs: Loan amount, Interest PA, Loan duration
 * 
 * to compile -> gcc 'filename.c' -o 'filename'
 * to run -> .\filename
**/

// Libraries
#include <stdio.h> 

// Define
#define months 12

// Functions
float calcPayments(int loan, float interest, int duration);

#pragma region MAIN 
int main () 
{
    /// Variables ///
    float interest, monthlyPayments;
    int loan,duration;

    printf("Loan value: ");
    scanf("%d", &loan);        

    printf("Interest per annum: ");
    scanf("%f", &interest);

    printf("Loan duration: ");
    scanf("%d*c", &duration);

    monthlyPayments = calcPayments(loan, interest,duration);
    printf("Monthly payments: %f\n\n", monthlyPayments);

    // Exits program safely
    return 0;
}
#pragma endregion


float calcPayments(int loan, float interest, int duration)
{
    interest = interest / 100;    // actual decimal value
    // simple interest
    float x = loan * interest *duration; // P x R x T 
    printf("\nTotal interest: %f\n", x);
    printf("Total amount due: %f\n", x + loan );
    x = (x + loan) / (months * duration);
   

    /* /// COMPOUND INTEREST ///
    float total = loan;
    // this is compound interest me thinks
    for (int i = 0; i <duration; i++)
    {
        total = total * interest;
    }
    printf("compound interest: %f", total);

    x = (loan / duration * months);
    printf("compound Interest monthly payments: %f\n\n", x);
    */
    return x;
}