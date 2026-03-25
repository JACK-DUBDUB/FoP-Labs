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
void calcPayments(int loan, float interest, int duration);
void displayResults(float totalPayments, int loan, float monthlyPayments);

#pragma region MAIN 
int main () 
{
    /// Variables ///
    float interest, monthlyPayments;
    int loan, duration;

    printf("Loan value: ");
    scanf("%d", &loan);        

    printf("Interest per annum: ");
    scanf("%f", &interest);

    printf("Loan duration (years): ");
    scanf("%d", &duration);

    calcPayments(loan, interest,duration);

    // Exits program safely
    return 0;
}
#pragma endregion

// Simple interest
#pragma region Functions
void calcPayments(int loan, float interest, int duration)
{
    // P x R x T  
    interest = interest / 100;    // actual decimal value
    float totalpayments = loan * interest * duration; 
    float monthlyPayments = (totalpayments + loan) / (months * duration);
    
    displayResults(totalpayments, loan, monthlyPayments);
    return;
}

void displayResults(float totalPayments, int loan, float monthlyPayments)
{
    printf("\nTotal interest: %f\n", totalPayments);
    printf("Total amount due: %f\n", totalPayments + loan );
    printf("Monthly payments: %f\n\n", monthlyPayments);
}
#pragma endregion
