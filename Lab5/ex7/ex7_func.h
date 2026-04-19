#ifndef EX7_FUNC_H
#define EX7_FUNC_H

#include <stdbool.h>

// ---- Functions ----

// Samples
void handle_readSamples(float *tempSamples[], int arrSize);
bool read_sampleValue(float *fuserValue);

// States
void handle_getStates(float *tempSamples[], int arrSize);
void get_states(float *tempSamples[], int arrSize);

// Min max
void handle_getMinMax(float tempSample[], int arrSize);
void get_minMax(float tempSample[], int arrSize, int *min, int *max);

// Average
void handle_getAverages(float *tempSample[], int arrSize);
void get_averages(float *tempSamples[], int sampleSize, float tempAvgs[], int avgSize);

// Search modules
void handle_searchModule(float tempSample[], int arrSize);
float read_searchValue();
int get_numberOfSamples(float tempSample[], int arrSize, float searchV);
char read_quitSearch();

#endif