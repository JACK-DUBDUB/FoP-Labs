/**
 * /// DATE ///
 * 20/03/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 * 
 * /// ABOUT PROGRAM ///
 * Exercise 4
 * Program displays calculation results of 3 houses
 *      Calculation results include, tax rates + fuel costs + house cost totals
 * 
 * /// ALGORITHM ///
 * 1. Call displayResults
 *      2. LOOP [3] TIMES
 *          a. Displays each house's calculation results
 *      3. END LOOP
 * 4. Close program
 * 
 * /// HOW TO COMPILE AND RUN ///
 * To compile: gcc '.\filename_main.c' '.\filename_func.c'-o 'filename'
 * To run: .\filename
*/

 // Libraries
#include <stdio.h>
#include "ex4_houseFunc.h"

int main()
{
    // Variables
    float houseCost[ARRAYLIMIT] = {67000, 62000, 75000}; // {house 1, house 2, house 3}
    float fuelCost[ARRAYLIMIT] = {2300, 2500, 1850};
    float taxRate[ARRAYLIMIT] = {0.025, 0.025, 0.02};

    // Process
    displayResults(houseCost, fuelCost, taxRate);

    // Exit
    printf("Press enter to quit program...");
    getchar();
    return 0;
}