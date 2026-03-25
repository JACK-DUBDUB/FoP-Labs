#ifndef EX6_FUNC_H
#define EX6_FUNC_H

// Defined constants
#define MONTHS_PER_YEAR 12
#define USER_INPUT_ERROR -1

// Declared functions
void calculateMonthlyLoanPayments(double downPayment, double assetValue, double interest, double duration);
int validateValues(double downPayment, double assetValue, double annualInterest, double duration);
char getMenuKey();
double getDoubleValue(double currentValue);

#endif
