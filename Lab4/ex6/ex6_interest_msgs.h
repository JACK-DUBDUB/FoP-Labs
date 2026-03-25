#ifndef EX6_MSGS_H
#define EX6_MSGS_H

// Array of pointers to multiple "strings"
extern const char  *MENUSELECTION_S[];

// One big menu "string"
extern const char* MENU;

// Declare functions
void returnToMenu();
void clearInputBuffer();
void pauseExitProgram();
void displayOptionSelected(int option, const char *MENUSELECTION_S[]);
void displayCurrentVariables(double downPayment, double assetValue, double interest, double duration);


#endif