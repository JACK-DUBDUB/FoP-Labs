
#include <ctype.h>
#include <stdio.h>
#include "ex7_const.h"
#include "ex7_func.h"
#include "../LAB_5_LIB.h"


// ---- read samples from user ----

void handle_readSamples(float *tempSamples[], int arrSize)
{
    int index = 0;

    printf("-------- Enter Temperature Samples --------\n");
    printf("Insert up to [%i] temperature samples (Kelvin) \n", arrSize);
    printf("Where balues must be positive float values\n");

    while (index != arrSize)
    {
        printf("Sample [%d]: ", index + 1);

        float fsample = 0;
        bool valid = read_sampleValue(&fsample);

        if (valid){
            tempSamples[KELVIN][index]      = fsample;
            tempSamples[CELSIUS][index]     = (fsample  - ZERO_C);
            tempSamples[FAHRENHEIT][index]  = ((fsample  - ZERO_C) * MUL_F) + ZERO_F;
            index++;
        } else {
            printf("Please re-enter a valid float value.\n\n");
        }
    }
    program_status_pause(CONTINUE);
    return;
}

bool read_sampleValue(float *fuserValue)
{
    if (read_float(fuserValue) != true) {
        printf("User did not enter a valid temperature sample.\n");
        return false;
    }

    if (*fuserValue  <= 0) {
        printf("Cannot have float values BELOW or EQUAL to zero Kelvin.\n");
        return false;
    }
    return true;
}


// ---- Water ----

void handle_getStates(float *tempSamples[], int arrSize)
{
    printf("\n-------- States Of Water --------\n\n");
    get_states(tempSamples, arrSize);
    program_status_pause(CONTINUE);
    return;
}

void get_states(float *tempSamples[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("    ---- Sample [%d] ----\n", i + 1 );
        printf("    Kelvin:      %.2f\n", tempSamples[KELVIN][i]);
        printf("    Celsius:     %.2f\n", tempSamples[CELSIUS][i]);
        printf("    Fahrenheit:  %.2f\n", tempSamples[FAHRENHEIT][i]);

        if(tempSamples[CELSIUS][i] >= GAS)
            printf("    State:       GAS\n\n");
        else if(tempSamples[CELSIUS][i] <= SOLID)
            printf("    State:       SOLID\n\n");
        else
            printf("    State:       LIQUID\n\n");
    }
    return;
}

// ---- Min Max ----

void handle_getMinMax(float tempSample[], int arrSize)
{
    int min = 0;
    int max = 0;
    get_minMax(tempSample, arrSize, &min, &max);
    
    printf("\n-------- Temperature min max --------\n\n");
    printf("Lowest  temperature: Sample[%i] = %.2f K\n", min+1, tempSample[min]);
    printf("Highest temperature: Sample[%i] = %.2f K\n", max+1, tempSample[max]);
    program_status_pause(CONTINUE);
    return;
}

void get_minMax(float tempSample[], int arrSize, int *min, int *max)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (tempSample[i] < tempSample[*min]) {
            *min = i;
        }
        if (tempSample[i] > tempSample[*max]) {
            *max = i; 
        }
    }
    return;
}

// ---- Average ----

void handle_getAverages(float *tempSamples[], int arrSize)
{
    float tempAvgs[TEMP_TYPES] = {KELVIN, CELSIUS, FAHRENHEIT};
    get_averages(tempSamples, arrSize, tempAvgs, TEMP_TYPES);

    // Display averages
    printf("\n-------- Temperature Averages --------\n\n");
    printf("Kelvin samples average:     %.2f K\n", tempAvgs[KELVIN]);
    printf("Celsius samples average:    %.2f C\n", tempAvgs[CELSIUS]);
    printf("Fahrenheit samples average: %.2f F\n", tempAvgs[FAHRENHEIT]);
    program_status_pause(CONTINUE);
    return;
}

void get_averages(float *tempSamples[], int sampleSize, float tempAvgs[], int avgSize)
{
    float totalK = 0, totalC = 0, totalF = 0;

    for (int i = 0; i < sampleSize; i++){
        totalK += tempSamples[KELVIN][i];
        totalC += tempSamples[CELSIUS][i];
        totalF += tempSamples[FAHRENHEIT][i];
    }

    tempAvgs[KELVIN]        = totalK / sampleSize;
    tempAvgs[CELSIUS]       = totalC / sampleSize;
    tempAvgs[FAHRENHEIT]    = totalF / sampleSize;
    return;
}

// ---- Search the samples below a user value ----

void handle_searchModule(float tempSample[], int arrSize)
{
    printf("\n-------- Search for temperature values --------\n\n");
    char quit = 0;
    do 
    {
        // set search value
        float searchV = read_searchValue();
        clear_input_buffer();

        // get number of samples
        int count = get_numberOfSamples(tempSample, arrSize, searchV);
        printf("\nNumber of samples found below %.2f K: %i\n\n", searchV, count);

        // set quit
        quit = read_quitSearch();
        if (quit == 'R') {
            printf("\n---- Next Search ----\n");
        }
    } while (quit != 'Q');

    clear_input_buffer();
    return;
}

float read_searchValue()
{
    bool valid = false;
    float fsearch;
    do {
        printf("Please enter a positive search (float) value: ");
        valid = read_sampleValue(&fsearch);

        if (!valid) {
            printf("Please re-enter a valid float value.\n\n");
        }
    } while (!valid);

    return fsearch;
}

// Simple O(n) linear search for values below the search value
int get_numberOfSamples(float tempSample[], int arrSize, float searchV)
{
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (tempSample[i] < searchV) {
            count++;
        }
    }
    return count;
}

char read_quitSearch()
{
    bool valid = false;
    char c;

    printf("Search again or Quit?\n");
    printf(" 'Q' to Quit\n");
    printf(" 'R' to Retry\n");

    do {
        printf("Please enter a value (Q-R): ");
        valid = read_char(&c);
        if (islower(c)){
            c = toupper(c);
        }

        if (c == 'Q' || c == 'R') {
            valid = true;
        } else {
            valid = false;
            printf("Please enter a valid value\n\n");
        }
    } while (!valid);
    return c;
}