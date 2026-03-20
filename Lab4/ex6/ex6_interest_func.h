#ifndef EX6_FUNC_H
#define EX6_FUNC_H

// Defined constants
#define MONTHS 12

// Declared functions
void displayOptionSelected(int option, const char *MENUSELECTION_S[]);
void displayCurrentVariables(double downPayment, double assetValue, double interest, double duration);
void calculateInterestPayments(double downPayment, double assetValue, double interest, double duration);
char getMenuKey();
double getDoubleValue(double currentValue);
void returnToMenu();
void clearInputBuffer();
void pauseExitProgram();


#endif
