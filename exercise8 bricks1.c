/**
 * 10/03/2026 
 * Jack du boulay - 32712899 
 * Exercise 8 -> Bricks and rows
 * Calculates number of bricks required for a row length n
 * 
 * to compile -> gcc 'filename.c' -o 'filename'
 * to run -> .\filename
**/

// Libraries
#include <stdio.h> 

// Define

// Functions
float calcTotalBricks(int brick, int row);

#pragma region MAIN 
int main () 
{
    /// Variables ///
    const int brickLength = 20;     // in centimetres
    float rowLength = 11;           // in metres.

    // calculate total number of bricks required
    float totalBricks = calcTotalBricks(brickLength, rowLength);
    printf("Brick length: %d\nRow length: %fm\nTotal bricks: %f\n", brickLength, rowLength, totalBricks);

    // Exits program safely
    return 0;
}
#pragma endregion

float calcTotalBricks(int brick, int row)
{
    // Row length: 11 * 100cm = 1100cm
    // Brick length: 20cm
    return (row * 100) / brick;
}