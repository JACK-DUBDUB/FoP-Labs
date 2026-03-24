#include <stdio.h>
#include "a1_coins_func.h"
#include "a1_coins_const.h"

#pragma region INPUT FUNCTIONS
int getUserInt(int rangeMin, int rangeMax)
{
    int userInput;
    if(scanf("%d", &userInput) != 1)
        userInput = USER_INPUT_ERROR;
    
    if(getchar() != '\n')
    {
         while(getchar() != '\n');
         userInput = USER_INPUT_ERROR;
    }

    if(userInput < rangeMin || userInput > rangeMax)
        userInput = USER_INPUT_ERROR;
    
    return userInput;
}

void pauseExitProgram()
{
    printf("\n\nPress enter to quit program...");
    getchar();
    return;
}
#pragma endregion

#pragma region DISPLAY FUNCTIONS
void displayChange(int change, const int currency[], int arraySize, const char *currencyType)
{
    int totalCoins[arraySize]; // Stores total number of each coin available 

    printf("\nCurrency selected: %s\n", currencyType);
    printf("Change value: %d\nCOINS | ", change);

    // Force rounding to lowest available value if applicable (AUD)
    if(change % currency[arraySize -1] > currency[arraySize -1] / 2)
        change += currency[arraySize - 1];

    // Count number of coins
    for (int i = 0; i < arraySize; i++)
    {
        totalCoins[i] = change / currency[i];   // insert number of coins
        change %= currency[i];                  // get remainder
    }

    // Display total coins counted
    int approximateValue = 0;
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d cent: %d | ", currency[i], totalCoins[i]);
        approximateValue += totalCoins[i] * currency[i];
    }

    // Display approximate value if change rounding was required
    if(change > 0)
        printf("\n\nApproximate value: %d cents", approximateValue);
    
    return;
}
#pragma endregion