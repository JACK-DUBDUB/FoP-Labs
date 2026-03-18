/**
 * TODO:
 * STRUCTURE CHART
 * ABOUT
 * CODE
 * 
 * What do you mean modular design?
 * How modular are we talking?
 * 
 * About question 4:
 * How modular do you want Lab 4's exercise 4 to be because I have only one modular function but it returns nothing, it only displays the results.
 * 
 * CODE = DONE
 */




#include <stdio.h>

#define ARRAYLIMIT 3
#define PERIOD 5

int main()
{
    // Could use a 2D array here?
    // float houseData[LIMIT][LIMIT] = {{67000, 2300, 0.025}, {62000, 2500, 0.025}, {75000, 1850, 0.02}};
    int houseCost[] = {67000, 62000, 75000};    // House cost
    int fuelCost[] = {2300, 2500, 1850};        // Fuel cost
    float taxRate[] = {0.025, 0.025, 0.02};     // Tax rate

    // The house
    for (int i = 0; i < ARRAYLIMIT; i++)
    {
        int totalFuel = 0;
        float totalTax = 0;

        // The 5 years period
        for (int j = 0; j < PERIOD; j++) 
        {
            totalFuel += fuelCost[i];
            totalTax += houseCost[i] * taxRate[i];
            //printf("Year: %d  |  Fuel cost: %d  |  Tax: %f\n", j + 1, fuelCost[i] ,houseCost[i] * taxRate[i]);
        }

        printf("--- House %d ---\nInitial House cost: %d\n", i + 1, houseCost[i]);
        printf("Total fuel cost over a 5 year period: %d\nTotal tax over a 5 year period: %f\nTotal cost of a house over a 5 year period: %.2f\n\n", totalFuel, totalTax, (houseCost[i] + totalFuel + totalTax));
    }

    return 0;
}