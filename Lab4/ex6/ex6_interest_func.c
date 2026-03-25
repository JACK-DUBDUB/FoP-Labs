#include <stdio.h>
#include <math.h>
#include "ex6_interest_func.h"

double getDoubleValue(double currentValue)
{
    double inputVal = 0.0;
    if(scanf("%lf", &inputVal) != 1)
        inputVal = -1;
    
    if(getchar() != '\n')
    {
        clearInputBuffer();
        inputVal = -1;
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
    printf("Enter a menu key: ");
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


void calculateInterestPayments(double downPayment, double assetValue, double interest, double duration)
{
    if (downPayment <= 0 || assetValue <= 0 || interest <= 0 || duration <= 0 || assetValue < downPayment)
    {
        printf("ERROR: Current values are invalid.\nCannot perform calculations.\n");
        returnToMenu();
        return;
    }

    /**
     * Took a lot longer than expected but I got there in the end.
     * Had to use math.h for pow()
     * 
     * r <=> M
     * 
     *                      P x r x (1 + r)^n               M x P 
     * Monthly payments  =  -------------------   or   ------------------
     *                         (1 + r)^n - 1            1 - (1 + M)^-n 
     */

    // P principle - The loan
    double loanValue_p = (assetValue - downPayment); 

    // n Nth  - Number of total payments               Expected duration:  (36, 48, 60) = (3.0y, 4.0y, 5.0y)
    int months_n = ((int) (duration * MONTHS) + 0.5);  // + 0.5 rounds to nearest month

    // R rate - Mnthly interest rate     
    double monthlyRate_r = (interest / 100) / MONTHS;    

    // (1 + m)^n - Total interest factor
    double totalInterest = pow((1 + monthlyRate_r), months_n);
    
    // P x r x (1 + M)^n
    double p = loanValue_p * monthlyRate_r * totalInterest; 

    // (1 + M)^n - 1
    double q = (totalInterest - 1);

    // Monthly payments
    double monthlyPayment = (p / q);

    // Display messages
    printf("\n--------  Calculations  --------\n");
    printf("P Principle loan value  = $ %.2lf\n", (assetValue - downPayment));
    printf("M Monthly interest rate =   %lf %%\n", monthlyRate_r * 100);
    printf("N Number of payments    =   %d (months) \n\n", months_n);
    printf("Total interest payment  = $ %.2lf\n", (monthlyPayment * months_n) - loanValue_p);
    printf("Total loan payment      = $ %.2lf\n", monthlyPayment * months_n);
    printf("Total payment           = $ %.2lf\n\n", downPayment + monthlyPayment * months_n);
    printf("Monthly payments        = $ %.2lf\n", monthlyPayment);
    returnToMenu();
    return;
}