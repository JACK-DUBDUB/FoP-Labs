/**
 * TODO:
 * STRUCTURE CHART 
 * ABOUT
 * CODE
 * 
 * About question 4:
 * How modular do you want Lab 4's exercise 4 to be, because I only have one modular function and it returns nothing, it only displays the results.
 * 
 * CODE = DONE
 */

 // Libraries
#include <stdio.h>

// Defined constants
#define ARRAYLIMIT 3
#define PERIOD 5        

// Declared Functions
void displayResults(float house[], float fuel[], float tax[]);

int main()
{
    // Variables
    float houseCost[ARRAYLIMIT] = {67000, 62000, 75000};
    float fuelCost[ARRAYLIMIT] = {2300, 2500, 1850};
    float taxRate[ARRAYLIMIT] = {0.025, 0.025, 0.02};

    // Process
    displayResults(houseCost, fuelCost, taxRate);

    // Exit
    printf("Press enter to quit program...");
    getchar();
    return 0;
}

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