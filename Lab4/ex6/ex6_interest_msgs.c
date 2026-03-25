#include <stdio.h>
#include "ex6_interest_msgs.h"

// Array of pointers to multiple strings
const char *MENUSELECTION_S[] = {
    "\nChose to view current variable values.\n",                                     // 0
    "\nChose to insert new asset value.\nEnter new asset value: ",                    // 1
    "\nChose to insert new annual interest.\nEnter new annual interest rate: ",       // 2
    "\nChose to insert new duration.\nEnter new loan duration (years): ",             // 3
    "\nChose to insert new down payment amount.\nEnter new down payment amount: ",    // 4
    "\nChose to perform interest calculation.\n",                                     // 5
    "\nChose to quit program.\n",                                                     // 6
    "\nDid not enter a valid menu key.\n"                                             // 7
};

// One big menu "string"
const char* MENU =
"-------- /// MENU /// --------\n Menu keys:\n"
" 'V' - To view current variable values\n"
" 'A' - To insert new asset value\n"
" 'S' - To insert new annual interest rate\n"
" 'D' - To insert new duration\n"
" 'F' - To insert new down payment amount\n"
" 'G' - To perform interest calculation\n"
" 'Q' - To quit program\n\n";


void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF); //EOF -> end of file (macro)
    return;
}

void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    return;
}

void displayOptionSelected(int option, const char *MENUSELECTION_S[])
{
    printf("%s", MENUSELECTION_S[option]);
    return;
}

void displayCurrentVariables(double downPayment, double loan, double interest, double duration)
{
    printf("-------- Current Values --------\n");
    printf("Down payment value      = $ %.2lf\n", downPayment);
    printf("Asset value             = $ %.2lf\n", loan);           
    printf("Interest rate (p.a)     =   %.2lf %%\n", interest);  // Print the actial % sign using %% or use ()"%c", 37)
    printf("Duration (years)        =   %.1lf\n", duration);
    return;
}

void returnToMenu()
{
    printf("\nPress enter to go to menu...");
    getchar();
    printf("\n\n");
    return;
}

void displayLoanPayments(double loanValue_p, double monthlyRate_r, int months_n, double fullLoanPayment, double fullTotalPayment, double monthlyPayment)
{
    printf("\n--------  Loan Payments --------\n");
    printf("P Principal loan value  = $ %.2lf\n", loanValue_p);
    printf("M Monthly interest rate =   %lf %%\n", monthlyRate_r * 100);
    printf("N Number of payments    =   %d (months) \n\n", months_n);
    printf("Total Loan payment      = $ %.2lf\n", fullLoanPayment);
    printf("Full Total payment      = $ %.2lf\n\n", fullTotalPayment);
    printf("Monthly payments        = $ %.2lf\n", monthlyPayment);
    return;
}