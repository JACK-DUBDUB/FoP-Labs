#include <stdio.h>
#include "a1_coins_func.h"

// ---- get user input functions ----
int getUserInt(int rangeMin, int rangeMax)
{
    int userInput = 0;
    int valid = 0;

    // Notify the user if a specified multiple is required
    if(rangeMin != LOWEST_MULTIPLE){ // LOWEST_MULTIPLE = 1
        printf("\nAllowable change amount must be a multiple of: %i\n", rangeMin);
    }

    do
    {
        printf("\nEnter a valid value: ");
        valid = scanf("%d",&userInput);

        // Filter validity of input
        if (valid && getchar() != '\n'){
            printf("User did not insert a valid integer value\n");
            clearInputBuffer();
            valid = 0;
        }
        else if (valid && (userInput < rangeMin || userInput > rangeMax)){
            printf("User inserted a value outside of range.\n" );
            valid = 0;
        }
        else if (valid &&  (userInput % rangeMin != 0)){
            printf("Change value has to be a multiple of: %i\n", rangeMin); // Can only be triggered if lowestMultiple is not equal to 1
            valid = 0;
        }

        if (!valid){
            printf("Please enter a valid value between (%i-%i) inclusive.\n", rangeMin, rangeMax);
        }

    } while (!valid);
    return userInput;
}

void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    return;
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF); //EOF -> end of file (macro)
    return;
}

// ---- display to user functions ----

void promptUserCurrency()
{
    printf("/// Currency Selection Menu ///");
    printf("\nCoin variants of currencies (cents)\n");
    printf("[1] $ USD: 50  25  10  1\n");
    printf("[2] $ AUD: 50  20  10  5\n");
    printf("[3] $ EUR: 20  10   5  1\n");
    printf("Please select a currency type\n");
    return;     
}

void promptUserChange(int min, int max)
{
    printf("\n/// Enter change value ///\n");
    printf("Please enter change amount between: (%i-%i)", min, max);
    return;
}

void promptUserExit()
{
    printf("\n\n/// Retry or Exit ///\n");
    printf("Would you like to try again or exit program?\n");
    printf("[%i] - Try again \n[%i] - Exit program\n", PROG_REPEAT, PROG_EXIT);
    printf("Please enter a selection\n");
    return;
}

void displayCoins(int sortedCoins[], const int currency[], int arraySize)
{
    // Display number of coins
    printf("Coin variants: ");
    for (int i = 0; i < arraySize; i++){
        printf("[%d cent]: %i | ", currency[i], sortedCoins[i]);
    }
    return;
}

// ---- calculation functions ---- 

void calculateCoins(int change, const int currencyType[], int sortedcoins[], int arraySize)
{
    // Sort the number of coin variants required
    for (int i = 0; i < arraySize; i++){
        sortedcoins[i] = change / currencyType[i];  // insert number of coins
        change %= currencyType[i];                  // get remainder for next loop
    }
    return;
}