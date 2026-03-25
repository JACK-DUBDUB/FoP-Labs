#ifndef COIN_SORT_FUNC_H
#define COIN_SORT_FUNC_H

// ---- Declared functions ---- //

// | Range minimum | Range Maximum |
int getUserInt(int rangeMin, int rangeMax);

// | Change amount inserted | currency type chosen (int array) | size of int array chosen | currency type chosen (string)|
void displayChange(int change,const int currency[], int arraySize, const char *currencyType);

// | simple press enter pause |
void pauseExitProgram();

#endif