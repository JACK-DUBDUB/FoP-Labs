
/** Assignment 1
 * Same dog, same tricks.
 * 
 * 
 * 
 * Coin sorting algorithm
 * 
 */

#include <stdio.h>

#define USER_INPUT_ERROR -1
#define USER_MAX 95
#define USER_MIN 1

int getUserInt(int rangeMin, int rangeMax);
void displayChange(int selection, int change, int currency[], int arraySize, const char *currencyType);

int main()
{
    int coinsUS[] = {50, 25, 10, 1};
    int coinsAU[] = {50, 20, 10, 5};
    int coinsEU[] = {20, 10 , 5, 1};

    const char *MENUSELECTION_S[] = {
    "Currency Selection: ",
    "[1] $ USD - [ 50, 25, 10, 1 ]",
    "[2] $ AUD - [ 50, 20, 10, 5 ]",
    "[3] $ EUR - [ 20, 10,  5, 1 ]"
    };

    const char *CURRENCYTYPE_S[] = {"$ USD", "$ AUD", "$ EUR"};


    // Get change value
    printf("Please enter change amount (1-95 cents): ");
    int userChange = getUserInt(USER_MIN, USER_MAX);

    if(userChange == USER_INPUT_ERROR)
    {
        printf("User entered an invalid change amount.\n");
        return 1;
    }

    // Display selection
    for(int i = 0; i < 4; i++)
    {
        printf("%s\n", MENUSELECTION_S[i]);
    }

    printf("Please enter currency type (1-3): ");
    int userSelection = getUserInt(1, 3) - 1;   // Currency Selection: 1 = US, 2 = AU, 3 = EU

    if(userSelection == USER_INPUT_ERROR)
    {
        printf("User entered an invalid currency type selection.\n");
        return 1;
    }

    int arraySize;
    switch (userSelection)
    {
        case 0:
            arraySize = (sizeof(coinsUS) / sizeof(coinsUS[0]));
            displayChange(userSelection, userChange, coinsUS, arraySize, CURRENCYTYPE_S[userSelection]);  
            break;
        case 1:
            arraySize = (sizeof(coinsAU) / sizeof(coinsAU[0]));
            displayChange(userSelection, userChange, coinsAU, arraySize, CURRENCYTYPE_S[userSelection]);  
            break;
        case 2:
            arraySize = (sizeof(coinsEU) / sizeof(coinsEU[0]));
            displayChange(userSelection, userChange, coinsEU, arraySize, CURRENCYTYPE_S[userSelection]);
            break;  
        default:
            printf("Default block triggered - ERROR.");
            break;
    }
         
    return 0;
}

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

    if(userInput < rangeMin || userInput > rangeMax) // In sid the sloth's voice: "I'm a genius"
        userInput = USER_INPUT_ERROR;
    
    return userInput;
}

void displayChange(int selection, int change, int currency[], int arraySize, const char *currencyType)
{
    int temp;
    int results[arraySize];

    printf("Currency selected: %s\n", currencyType);
    printf("Change value: %d\n", change);

    for (int i = 0; i < arraySize; i++)
    {
        temp = change;  // Get change value

        results[i] = temp / currency[i]; // Get number

        change %= currency[i]; // Find remainders

        if((i == (arraySize - 1) && change > 0) && (change > (currency[i] / 2))) // Only AUD suffers from this
            results[i] += 1;
    }

    // Display results
    int approximateValue = 0;
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d cent coins: %d\n", currency[i], results[i]);
        approximateValue += results[i] * currency[i];
    }
    printf("Approximate value: %d \n\n", approximateValue);
    return;
}