#include <stdio.h>
#include "ex4_houseFunc.h"

void calculateResults(float house[], float fuel[], float tax[])
{
    for (int i = 0; i < ARRAY_LIMIT; i++)    
    {
        // Where period = 5
        float totalFuel = fuel[i] * PERIOD_YEARS; 
        float totalTax = (house[i] * tax[i]) * PERIOD_YEARS;

        // Display results
        displayResults(totalFuel, totalTax, house[i], i + 1);
    }
    return;
}

void displayResults(float totalFuel, float totalTax, float house, int index)
{
        printf("--- House %d ---\n", index);
        printf("Initial House cost: $%.2f\n",house);
        printf("Total cost of fuel over a %d year period: $%.2f\n", PERIOD_YEARS, totalFuel);
        printf("Total cost of tax over %d year period: $%.2f\n", PERIOD_YEARS, totalTax);
        printf("Total cost of maintainance over a %d year period: $%.2f\n", PERIOD_YEARS, (totalFuel + totalTax));
        printf("Total cost of house and maintenance over a %d year period: $%.2f\n\n", PERIOD_YEARS, (house + totalFuel + totalTax));
}