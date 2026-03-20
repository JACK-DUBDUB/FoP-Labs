



/**
 * BROKIE DECIDES TO GET A CAR LOAN INSTEAD OF SAVING HIS PITIFUL $500 LIQUID CASH
 * This is exactly why people are poor.
 * 
 * Learnt something cool -> for (;;){} is actually a while loop
 * 
 */


#include <stdio.h>
#include <math.h>

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

int main()
{   
    // Extern const char
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
        printf("-------- /// MENU /// --------\n Menu keys:\n");
        printf(" 'v' - To view current variable values\n");
        printf(" 'a' - To insert new asset value\n");
        printf(" 's' - To insert new annual interest rate\n");
        printf(" 'd' - To insert new duration\n");
        printf(" 'f' - To insert new down payment amount\n");
        printf(" 'g' - To perform interest calculation\n");
        printf(" 'q' - To quit program\n\n");

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

double getDoubleValue(double currentValue)
{
    double inputVal = 0.0;
    if(scanf("%lf", &inputVal) != 1)
        inputVal = -1;
    
    clearInputBuffer(); // Clear

    if(inputVal <= 0)
    {
        printf("\nUser did not enter a valid value.\n");  // User cannot use negative values for a loan
        returnToMenu();
        return currentValue; //
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

    if(inputVal >= 'a' && inputVal <= 'z')  // force upper
        inputVal -= 32;
    
    if(inputVal >= '0' && inputVal <= '9')  // force raw value
        inputVal -= 48;
    
    return inputVal;
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF); //EOF -> end of file
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

void calculateInterestPayments(double downPayment, double assetValue, double interest, double duration)
{
    if (downPayment <= 0 || assetValue <= 0 || interest <= 0 || duration <= 0)
    {
        printf("ERROR: Current values are invalid.\nCannot perform calculations.\n");
        returnToMenu();
        return;
    }
    
    /**
     * Took a lot longer than expected but I got there in the end.
     * Had to use math.h
     * 
     *                      P x r x (1 + M)^n               M x P 
     * Monthly payments  =  -------------------   =   ------------------
     *                         (1 + M)^n - 1            1 - (1 + M)^-n 
     */

    // P principle - The loan
    double loanValue_p = (assetValue - downPayment); 

    // n Nth  - Number of total payments                  Expected durations:  (36, 48, 60) = (3.0y, 4.0y, 5.0y)
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
    printf("N Number of payments    =   %d \n\n", months_n);
    printf("Total interest payment  = $ %.2lf\n", (monthlyPayment * months_n) - loanValue_p);
    printf("Total loan payment      = $ %.2lf\n", monthlyPayment * months_n);
    printf("Total payment           = $ %.2lf\n\n", downPayment + monthlyPayment * months_n);
    printf("Monthly payments        = $ %.2lf\n", monthlyPayment);
    returnToMenu();
    return;
}