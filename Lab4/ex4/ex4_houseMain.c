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
 * How to compile
 * 
 * gcc ".\filename1.c" ".\filename2.c" -o program
 * 
 */

 // Libraries
#include <stdio.h>
#include "ex4_houseFunc.h"

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