/**
 * 4/03/2026 
 * Jack du boulay - 32712899 
 * Exercise 6 -> Program Testing
 * Input comparison algorithm, values must be a signed int (min = 32768, max = 32768) -> Can't i use a short for this? 
 * Program reads two integer numbers: X, Y
 * Compare values if they are == or !=
 * Compare values again and report which one is larger
 * 
 * to compile -> gcc 'filename.c' -o 'filename'
 * to run -> .\filename
**/

// Libraries
#include <stdio.h> 

// Define
#define months 12

// Functions
float calcPayments(int loan, float interest, int years);

#pragma region MAIN 
int main () 
{
    /// Variables ///
    float interest, monthlyPayments;
    int loan, years;

    printf("Loan value: ");
    scanf("%d", &loan);

    printf("Interest per annum: ");
    scanf("%f", &interest);

    printf("Loan duration: ");
    scanf("%d*c", &years);

    monthlyPayments = calcPayments(loan, interest, years);

    // Exits program safely
    return 0;
}
#pragma endregion


float calcPayments(int loan, float interest, int years)
{
    
    float x;
    // simple interest
    x = loan * (interest/100) * years; // P x R x T 
    printf("simple Interest: %f\n\n", x);
    x = x / (months * years);
    printf("Monthly payments: %f\n\n", x);

    float 
    // this is compound interest me thinks
    for (int i = 0; i < years; i++)
    {
        loan * (interest/100);
    }
    printf("compound interest: %")
    x = (loan / (years * months));
    printf("compound Interest monthly payments: %f\n\n", x);

    return x;
}