#include <stdio.h>
#include "a1_coins_func.h"
#include "a1_coins_const.h"

// ---- get user input functions ----
int getUserInt(int rangeMin, int rangeMax, int lowestMultiple, const char *currentStep)
{
    int userInput = 0;
    do
    {
        userInput = 0;
        printf("\n%s(%i-%i): ", currentStep, rangeMin, rangeMax);
        if (scanf("%d",&userInput) != 1){
            userInput = USER_INPUT_ERROR;
        }
        
        if (getchar() != '\n'){
            userInput = USER_INPUT_ERROR;
            clearInputBuffer();
        }

        if (userInput < rangeMin || userInput > rangeMax){
            userInput = USER_INPUT_ERROR;
        }

        if ((userInput != USER_INPUT_ERROR) && (userInput % lowestMultiple != 0)){
            userInput = USER_INPUT_ERROR;
            printf("\nChange value has to be a multiple of: %i", lowestMultiple);
        }

        if (userInput == USER_INPUT_ERROR){
            printf("\nPlease enter a valid value.\n");
        }

    } while (userInput == USER_INPUT_ERROR);
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

void displayMenu(const int *coinsArray[], const int coinsArrayNum, const int coinsArraySizes[], const char *CURRENCY_TYPE_S[])
{
    printf("/// Currency Selection Menu ///");
    printf("\nCoin variants of currencies (cents)");
    for (int i = 0; i < coinsArrayNum; i++){
        // Needs to be either a pointer OR 2D array style
        // int *currentArray[] = coinsArray[i];
        printf("\n[%i] %s: ", i+1, CURRENCY_TYPE_S[i]); // Example:  "[1] $ USD coins: "
       
        for (int j = 0; j < coinsArraySizes[i]; j++){
            // Print the coin variants of current currency
            printf("%i  ", coinsArray[i][j]); // 2D is easier

            if(coinsArray[i][j] < 9){
                printf(" ");
            }
        }
    }
    return;
}

void displayChange(int change, int changeFinal, int sortedCoins[], const int currency[], int arraySize, const char*currencyType)
{
    printf("\n/// Calculated Coins ///\n");
    printf("Currency type selected: %s\n", currencyType);
    printf("Change value inserted: %i cents\nCOINS | ", change);

    // Display total coins counted
    // int approximateValue = 0;
    for (int i = 0; i < arraySize; i++){
        printf("%d cent: %i | ", currency[i], sortedCoins[i]);
        //approximateValue += sortedCoins[i] * currency[i];
    }

    return;
}

// ---- calculation functions ---- 

int calculateChange(int change, const int currency[], int arraySize, const char *currencyType, int sortedcoins[])
{
    // Force rounding to lowest available value if applicable (AUD)
    // Modulus the change by the smallest coin value, compare it to the smallest coin value divided by 2
    // If the modulus value is > the halved coin then add an additional coin
    if(change % currency[arraySize -1] > currency[arraySize -1] / 2){ 
        change += currency[arraySize - 1];
    }
    // Count number of coins required
    for (int i = 0; i < arraySize; i++){
        sortedcoins[i] = change / currency[i];   // insert number of coins
        change %= currency[i];                  // get remainder
    }

    return change; // In $AU, there are no 1 cent coins, so rounding is required.
}