/**
 * /// DATE ///
 * 20/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 6
 * User is displayed a menu key selection to choose what to do with the program
 *      User can insert new values for the four major variables {downPayment, assetValue, interestRate, duration}
 *      User can choose to view the variables current values
 *      User can choose to display the calculations of interest 
 *      User can choose to quit the program
 * 
 * /// HIGH LEVEL ALGORITHM ///
 * 1. Display menu instructions 
 * 2. LOOP START
 *      3. Prompt user for menu key
 *      4. Validate menu key and pick option
 *          a. Can insert values for variables: {downPayment, assetValue, interestRate, duration}
 *          b. Can view variable values
 *          c. Can calculate and display interest payments
 *          d. Can quit the program
 * 5. LOOP UNTIL "QUIT"
 * 6. Close program
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename.c' -o 'filename'
 * To run: .\filename
*/
#include <stdio.h>
#include "ex6_interest_msgs.h"
#include "ex6_interest_func.h"

int main()
{   
    // User variables
    double downPayment = 500.0;     // Default brokie's deposit amount 
    double assetValue = 5000.0;     // Default asset value 
    double annualInterest = 5.0;    // Default annual interest value 
    double duration = 5;            // Default duration in years
    char menuKey = 00;              

    // Display the default values first before the user sees the menu
    displayCurrentVariables(downPayment, assetValue, annualInterest, duration);
    returnToMenu();
    do
    {
        ///  MENU ///
        printf("%s", MENU);
        menuKey = getMenuKey();

        switch (menuKey)
        {
            case 'V':   // View values
                displayOptionSelected(0, MENUSELECTION_S);  // Option 0
                displayCurrentVariables(downPayment, assetValue, annualInterest, duration);
                returnToMenu();
                break;
            case 'A':   // Insert new asset value
                displayOptionSelected(1, MENUSELECTION_S);
                assetValue = getDoubleValue(assetValue);
                break;
            case 'S':   // Insert new annual interest value
                displayOptionSelected(2, MENUSELECTION_S);
                annualInterest = getDoubleValue(annualInterest);
                break;
            case 'D':   // Insert new duration value
                displayOptionSelected(3, MENUSELECTION_S);
                duration = getDoubleValue(duration);
                break;
            case 'F':   // Insert new down payment value
                displayOptionSelected(4, MENUSELECTION_S);
                downPayment = getDoubleValue(downPayment);
                break;
            case 'G':   // Calculate interest
                displayOptionSelected(5, MENUSELECTION_S);
                displayCurrentVariables(downPayment, assetValue, annualInterest, duration);
                calculateInterestPayments(downPayment, assetValue, annualInterest, duration);
                break;
            case 'Q':   // Quit
                displayOptionSelected(6, MENUSELECTION_S);
                break;
            default:    // User entered invalid value
                displayOptionSelected(7, MENUSELECTION_S);
                printf("Press enter to retry: ");
                clearInputBuffer();
                printf("\n\n");
                break;
        }
    } while (menuKey != 'Q'); 
    
    pauseExitProgram();
    return 0;
}