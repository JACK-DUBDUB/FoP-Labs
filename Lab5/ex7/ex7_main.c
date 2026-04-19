/**
 * /// DATE ///
 * 17/04/2026
 * 
 * /// AUTHOR ///
 * Name: Jack du boulay 
 * Student ID: 32712899 
 *  
 * /// ABOUT PROGRAM ///
 * Exercise 7
 * Reads 10 positive float inputs as kelvin temperature samples
 * Converts the 10 kelvin samples into celsius and fahrenheit equivalents
 * Finds and displays the highest and lowest temperatures provided
 * Finds and displays the average of the 3 temperature type's samples
 * Lets the user search with a float value, counts the number of values below the search value
 * User can repeat search or quit
 * 
 * /// Compile and Run
 * gcc '.\ex7_water_main.c' '.\ex7_water_func.c' ..\LAB_5_LIB.c  -o ex7
 * .\ex7.exe
 */

#include "ex7_const.h"
#include "ex7_func.h"
#include "../LAB_5_LIB.h"


int main()
{
    float kelvin[SAMPLE_LIMIT];
    float celsius[SAMPLE_LIMIT];
    float fahrenheit[SAMPLE_LIMIT];
    float *tempSamples[TEMP_TYPES] = {kelvin, celsius, fahrenheit};

    // Read Kelvin samples
    handle_readSamples(tempSamples, SAMPLE_LIMIT);
    
    // Get and display water states
    handle_getStates(tempSamples, SAMPLE_LIMIT);
    
    // Get and display lowest and highest temp of kelvin samples
    handle_getMinMax(tempSamples[KELVIN], SAMPLE_LIMIT);
    
    // Get and display temperature averages
    handle_getAverages(tempSamples, SAMPLE_LIMIT);

    // 1. Prompt user to search -> read a float value
    // 2. Search for kelvin values less than the search value 
    // 3. Prompt user to quit or retry -> read a char value
    handle_searchModule(tempSamples[KELVIN], SAMPLE_LIMIT);

    // Quit program
    program_status_pause(QUIT);
    return 0;
}