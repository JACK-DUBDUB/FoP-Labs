#include <stdio.h>
#include "a1_coins_func.h"
#include "a1_coins_const.h"

// ---- get user input functions ----
int getUserInt(int rangeMin, int rangeMax, int lowestMultiple, const char *currentStep)
{
    int userInput = 0;
    int valid = 0;

    // Notify the user if a specified multiple is required
    if(lowestMultiple != LOWEST_MULTIPLE){
        rangeMin = lowestMultiple;
        printf("\nAllowable change amount must be a multiple of: %i", rangeMin);
    }

    do
    {
        printf("\n%s(%i-%i): ", currentStep, rangeMin, rangeMax);
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
        else if (valid &&  (userInput % lowestMultiple != 0)){
            printf("Change value has to be a multiple of: %i\n", lowestMultiple); // Can only be triggered if lowestMultiple is not equal to 1
            valid = 0;
        }

        if (!valid){
            printf("Please enter a valid value.\n");
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

void displayCurrencyMenu(const int *coinsArray[], const int coinsArrayNum, const int coinsArraySizes[], const char *CURRENCY_TYPE_S[])
{
    printf("/// Currency Selection Menu ///");
    printf("\nCoin variants of currencies (cents)");
    for (int i = 0; i < coinsArrayNum; i++){
        printf("\n[%i] %s: ", i+1, CURRENCY_TYPE_S[i]); // Example:  "[1] $ USD coins: "
       
        for (int j = 0; j < coinsArraySizes[i]; j++){
            // Print the coin variants of current currency
            printf("%i  ", coinsArray[i][j]); // 2D array is easier to work with

            if(coinsArray[i][j] < 9){ // So it looks neater
                printf(" ");
            }
        }
    }
    return;
}

void displayChange(int change, int sortedCoins[], const int currency[], int arraySize, const char*currencyType)
{
    printf("\n/// Calculated Coins ///\n");
    printf("Currency type selected: %s\n", currencyType);
    printf("Change value inserted: %i cents\nCOINS | ", change);
    
    // Display total coins counted
    for (int i = 0; i < arraySize; i++){
        printf("[%d] cent: %i | ", currency[i], sortedCoins[i]);
    }
    return;
}

// ---- calculation functions ---- 

void calculateChange(int change, const int currency[], int arraySize, const char *currencyType, int sortedcoins[])
{
    // Sort the number of coin variants required
    for (int i = 0; i < arraySize; i++){
        sortedcoins[i] = change / currency[i];  // insert number of coins
        change %= currency[i];                  // get remainder
    }
    return;
}