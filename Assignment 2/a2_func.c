#include <stdio.h>
#include "a2_func.h"
#include "a2_crud.h"

// ---- get user input functions ----
int getUserInt(int rangeMin, int rangeMax) 
{
    int userInput = 0;
    int valid = 0;
    do {
        printf("\nEnter a valid value: ");
        valid = scanf_s("%i", &userInput);
        valid = validateUserInput(valid, userInput, rangeMin, rangeMax);
        if (!valid) {
            printf("Please enter a valid value between (%i-%i) inclusive.\n", rangeMin, rangeMax);
        }

    } while (!valid);
    return userInput;
}

int validateUserInput(int valid, int userInput, int rangeMin, int rangeMax)
{
    if (!valid) {
        printf("User did not enter an integer value.\n");
        clearInputBuffer();
        return 0;
    } 
    if (valid && getchar() != '\n') {
        printf("User entered an integer value with a non-integer value.\n");
        clearInputBuffer();
        return 0;
    } 
    if (valid && (userInput < rangeMin || userInput > rangeMax)) {
        printf("User entered a value outside of range.\n" );
        return 0;
    }
    if (valid &&  (userInput % rangeMin != 0)) { // Possible values of rangeMin: (1, 5)
        printf("Change value must be a multiple of: %i\n", rangeMin);
        return 0;
    }
    return valid;
}

void pauseExitProgram()
{
    printf("\nPress enter to quit program...");
    getchar();
    return;
}

void clearInputBuffer()
{
    while (getchar() != '\n');
    return;
}

// ---- display to user functions ----

void promptUserCurrency()
{
    printf("\n\n/// Currency Selection Menu ///");
    printf("\nCoin variants of currencies (cents)\n");
    printf("[1] $ USD: %i  %i  %i  %i\n", COIN_VAL_50, COIN_VAL_25, COIN_VAL_10, COIN_VAL_1);
    printf("[2] $ AUD: %i  %i  %i  %i\n", COIN_VAL_50, COIN_VAL_20, COIN_VAL_10, COIN_VAL_5);
    printf("[3] $ EUR: %i  %i   %i  %i\n", COIN_VAL_20, COIN_VAL_10, COIN_VAL_5, COIN_VAL_1);
    printf("Please select a currency type\n\n");
    return;     
}

void promptUserChange(int rangeMin, int rangeMax, int currencyType)
{
    printf("\n/// Enter change value ///\n");
    printf("Please enter change amount between: (%i-%i)", rangeMin, rangeMax);
    if(currencyType == CURRENCY_AUD){
        printf("\nAllowable change amount must be a multiple of: %i\n", rangeMin);
    }
    return;
}

void promptUserExit()
{
    printf("\n/// Retry or Exit ///\n");
    printf("Would you like to exit program or try again?\n");
    printf("[%i] - Try again \n", PROG_CONT);
    printf("[%i] - Exit program\n", PROG_EXIT);
    printf("Please enter a selection\n");
    return;
}

void displayUserValues(int currencyType, int userChange)
{
    printf("\n/// Calculated Coins ///\n");
    printf("Currency type selected: ");
    
    if (currencyType == CURRENCY_USD) 
        printf("$ USD\n");
    else if (currencyType == CURRENCY_AUD) 
        printf("$ AUD\n");
    else 
        printf("$ EUR\n");

    printf("Change value inserted: %i cents\n", userChange);
    printf("| Value | Amount |\n");
    return;
}

void displayCoinResults(int coinValue, int coinAmount)
{
    // Purely cosmetic spacing changes for coin values below 10 ***
    if(coinValue < COIN_VAL_10) 
        printf("|   %i   |    %i   |\n", coinValue, coinAmount);
    else
        printf("|  %i   |    %i   |\n", coinValue, coinAmount);
    return;
}

// ---- get value functions ---- 

int getCoinValue(int currencyType, int coinVal_1, int coinVal_2, int coinVal_3)
{
    if (currencyType == CURRENCY_USD) 
        return coinVal_1;
    else if (currencyType == CURRENCY_AUD) 
        return coinVal_2;
    else 
        return coinVal_3;
}



// CODE REUSE -> FUNCTIONS ACTUALLY BEING USED:

int getCoinAmount(int coinValue, int userChange)
{
    int coinAmount = userChange / coinValue;
    return coinAmount;
}

int getChangeRemaining(int coinValue, int coinAmount, int userChange)
{
    int changeRem = userChange - (coinValue * coinAmount);
    return changeRem; 
}

