



/**
 * BROKIE DECIDES TO GET A CAR LOAN INSTEAD OF SAVING HIS PITIFUL $500 LIQUID CASH
 * This is exactly why people are poor.
 * 
 */


#include <stdio.h>

#define MONTHS 12

// Declared functions
double getDouble();
char getMenuKey();
void clearInputBuffer();
void pauseExitProgram();

int main()
{
    const double savings = 500.0;   // Brokie's savings
    double annualInterest = 0.0;
    double duration = 0;
    char menuKey;
    // I'll make a little CLI menu here.
    do
    {
        ///  MENU ///
        printf("-------- /// MENU /// --------\nKeys:\n");
        printf(" 'v' - To view variable values\n");
        printf(" 'a' - To insert annual interest\n");
        printf(" 'q' - To quit program\n");

        menuKey = getMenuKey();

        // Get car purchase price
        // Get annaul interest -> / 12 to get monthly interest payments
        // Get duration (years)



        switch (menuKey)
        {
            case 'A':
                printf("Chose to insert annual interest.\n");
                break;
            case 'V':
                printf("Chose to view variable values.\n");
                break;
            case 'Q':
                printf("Chose to quit program.\n");
                break;
            default:
                printf("Did not enter a valid menu key.\n");
                break;
        }

    } while (menuKey != 'Q');
    


    pauseExitProgram();
    return 0;
}

double getdouble()
{
    double inputVal;
    if(scanf("%lf", &inputVal) != 1)
        return -1;
    if(inputVal < 0)
        return -1;
    
    clearInputBuffer();
    return inputVal;
}

char getMenuKey()
{
    char inputVal;
    printf("Enter a menu key: ");
    if(scanf("%c", &inputVal) != 1)
        return -1;
    if(inputVal < 0)
        return -1;

    if(inputVal >= 'a' && inputVal <= 'z')  // force upper
        inputVal -= 32;
    
    if(inputVal >= '0' && inputVal <= '9')  // force raw value
        inputVal -= 48;

    clearInputBuffer();
    printf("--> %c\n", inputVal);

    return inputVal;
}

void clearInputBuffer()
{
    while(getchar() != '\n');   //
    return;
}

void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    return;
}
