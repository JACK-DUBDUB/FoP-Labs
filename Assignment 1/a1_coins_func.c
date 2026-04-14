#include <stdio.h>
#include "a1_coins_func.h"

// ---- get user input functions ----
int getUserInt(int rangeMin, int rangeMax)
{
    int userInput = 0;
    int valid = 0;
    do {
        printf("\nEnter a valid value: ");
        valid = scanf("%i",&userInput);

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
    if (valid &&  (userInput % rangeMin != 0)) {
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
    int c;
    while ((c = getchar()) != '\n' && c != EOF); //EOF -> end of file (macro)
    return;
}

// ---- display to user functions ----

void promptUserCurrency()
{
    printf("\n\n/// Currency Selection Menu ///");
    printf("\nCoin variants of currencies (cents)\n");
    printf("[1] $ USD: 50  25  10  1\n");
    printf("[2] $ AUD: 50  20  10  5\n");
    printf("[3] $ EUR: 20  10   5  1\n");
    printf("Please select a currency type\n");
    return;     
}

void promptUserChange(int rangeMin, int rangeMax)
{
    printf("\n/// Enter change value ///\n");
    printf("Please enter change amount between: (%i-%i)", rangeMin, rangeMax);
    if(rangeMin != LOWEST_MULTIPLE){  // Notify the user if a specified multiple is required
        printf("\nAllowable change amount must be a multiple of: %i\n", rangeMin);
    }
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

void displayUserValues(const char *currency_str, int userChange)
{
    printf("\n/// Calculated Coins ///\n");
    printf("Currency type selected: %s\n", currency_str);
    printf("Change value inserted: %i cents\n", userChange);
    return;
}

void displayCoins(int sortedCoins[], const int currencyCoins[])
{
    // Display number of coins
    printf("Coin variants: | ");
    for (int i = 0; i < COIN_VARIANT_MAX; i++) {
        printf("[%d cent]: %i | ", currencyCoins[i], sortedCoins[i]);    // value of coin, number of coin 
    }
    return;
}

// ---- calculation functions ---- 

void calculateCoins(int userChange, const int currencyCoins[], int sortedCoins[])
{
    // Sort the number of coin variants required
    for (int i = 0; i < COIN_VARIANT_MAX; i++) {
        sortedCoins[i] = userChange / currencyCoins[i];  // insert number of coins
        userChange %= currencyCoins[i];                  // get remainder for next loop
    }
    return;
}