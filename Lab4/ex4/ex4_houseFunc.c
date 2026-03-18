#include <stdio.h>
#include "ex4_houseFunc.h"

void displayResults(float house[], float fuel[], float tax[])
{
    for (int i = 0; i < ARRAYLIMIT; i++)    
    {
        float totalFuel = fuel[i] * PERIOD;
        float totalTax = (house[i] * tax[i]) * PERIOD;
        // Display results
        printf("--- House %d ---\n", i + 1);
        printf("Initial House cost: $%.2f\n",house[i]);
        printf("Total cost of fuel over a %d year period: $%.2f\n", PERIOD, totalFuel);
        printf("Total cost of tax over %d year period: $%.2f\n", PERIOD, totalTax);
        printf("Total cost of maintainenance over a %d year period: $%.2f\n", PERIOD, (totalFuel + totalTax));
        printf("Total cost of house and maintenance over a %d year period: $%.2f\n\n", PERIOD, (house[i] + totalFuel + totalTax));
    }
    return;
}