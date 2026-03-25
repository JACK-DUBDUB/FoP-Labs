#include <stdio.h>
#include <math.h>
#include "ex6_interest_func.h"
#include "ex6_interest_msgs.h"

double getDoubleValue(double currentValue)
{
    double inputVal = 0.0;
    if(scanf("%lf", &inputVal) != 1)
        inputVal = USER_INPUT_ERROR;
    if(getchar() != '\n')
    {
        clearInputBuffer();
        inputVal = USER_INPUT_ERROR;
    }
    if(inputVal <= 0)
    {
        printf("\nUser did not enter a valid value.\n");  // User cannot use negative values for a loan
        returnToMenu();
        return currentValue; // Return the default value so it remains "unchanged"
    }
    returnToMenu();
    return inputVal;
}

char getMenuKey()
{
    char inputVal = 0;
    if(scanf("%c", &inputVal) != 1)
        return 0;
    if(inputVal < 0)
        return 0;
    if(getchar() != '\n')
        clearInputBuffer();
    if(inputVal >= 'a' && inputVal <= 'z')  // force to upper
        inputVal -= 32;
    
    return inputVal;
}

int validateValues(double downPayment, double assetValue, double interest, double duration)
{
    if (downPayment < 0)
        printf("ERROR: down payment value is invalid. (use positive value)\n");
    else if (assetValue <= 0)
        printf("ERROR: asset value is invalid. (use positive value)\n");
    else if (assetValue <= downPayment)
        printf("ERROR: asset value is invalid. (Asset Value must be more than down payment)\n");
    else if (interest <= 0)
        printf("ERROR: interest value is invalid. (use positive value)\n");
    else if (duration <= 0)
        printf("ERROR: duration value is invalid. (use positive value)\n");
    else
        return 1; // Success
    returnToMenu();
    return 0;
}


void calculateMonthlyLoanPayments(double downPayment, double assetValue, double annualInterest, double duration)
{
    /** Compound interest
     * The tricky part
     *                      P     p x r x (1 + r)^n               m x p 
     * Monthly payments  = --- = -------------------   or   ------------------
     *                      Q     (1 + r)^n - 1               1 - (1 + m)^-n 
     * 
     * Key: 
     *      p     = Principal (loan value)
     *      r / m = Rate (interest rate)
     *      n     = Number of payments 
     * 
     * *** Initially I had a for loop do my exponents multiplication: ***
     * 
     * double totalInterest = (1 + monthlyRate_r);
     * double temp = totalInterest; 
     * for (int i = 1; i < months_n; i++)
     * {
     *      totalInterest = totalInterest * temp;
     * }
     * 
     * Which should calculate the exponent value.
     * But math.pow is much easier to read.
     */

    // ---- Components of Compound Interest ---- //
    double  loanValue_p      = (assetValue - downPayment);                  // (p)       
    int     months_n         = (int) (duration * MONTHS_PER_YEAR + 0.5);    // (n)          +0.5 rounding to nearest month
    double  monthlyRate_r    = (annualInterest / 100) / MONTHS_PER_YEAR;    // (r)
    double  totalInterest    = pow((1 + monthlyRate_r), months_n);          // ((1 + r)^n)

    // --- Numerator and Denominator ---- //
    double P = loanValue_p * monthlyRate_r * totalInterest;  
    double Q = (totalInterest - 1);                          

    // ---- Results ---- //
    double monthlyPayment = (P / Q);
    double fullLoanPayment = monthlyPayment * months_n;
    double fullTotalPayment = downPayment + fullLoanPayment;

    // Display calculations
    displayLoanPayments(loanValue_p, monthlyRate_r, months_n, fullLoanPayment, fullTotalPayment, monthlyPayment);
    returnToMenu();
    return;
}