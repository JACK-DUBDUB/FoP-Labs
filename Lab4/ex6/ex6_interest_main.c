



/**
 * BROKIE DECIDES TO GET A CAR LOAN INSTEAD OF SAVING HIS PITIFUL $500 LIQUID CASH
 * This is exactly why people are poor.
 * 
 * 
 * 
 */


#include <stdio.h>
#include <math.h>
#include "ex6_interest_func.h"
#include "ex6_interest_msgs.h"

#define MONTHS 12

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
            case 'V':
                displayOptionSelected(0, MENUSELECTION_S);  // Option 0
                displayCurrentVariables(downPayment, assetValue, annualInterest, duration);
                returnToMenu();
                break;
            case 'A':
                displayOptionSelected(1, MENUSELECTION_S);
                assetValue = getDoubleValue(assetValue);
                break;
            case 'S':
                displayOptionSelected(2, MENUSELECTION_S);
                annualInterest = getDoubleValue(annualInterest);
                break;
            case 'D':
                displayOptionSelected(3, MENUSELECTION_S);
                duration = getDoubleValue(duration);
                break;
            case 'F':
                displayOptionSelected(4, MENUSELECTION_S);
                downPayment = getDoubleValue(downPayment);
                break;
            case 'G':
                displayOptionSelected(5, MENUSELECTION_S);
                displayCurrentVariables(downPayment, assetValue, annualInterest, duration);
                calculateInterestPayments(downPayment, assetValue, annualInterest, duration);
                break;
            case 'Q':
                displayOptionSelected(6, MENUSELECTION_S);
                break;
            default:
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