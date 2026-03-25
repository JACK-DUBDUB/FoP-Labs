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

// Functions
void displayBrickResults(const int brickLength, float rowLength, float totalBricks);
float calcTotalBricks(int brick, int row);

#pragma region MAIN 
int main () 
{
    /// Variables ///
    const int brickLength = 20;     // in centimetres
    float rowLength = 11;           // in metres.
    float totalBricks = calcTotalBricks(brickLength, rowLength);

    // Display results
    displayBrickResults(brickLength, rowLength, totalBricks);

    // Exits program safely
    return 0;
}
#pragma endregion

#pragma region functions
float calcTotalBricks(int brick, int row)
{
    // Row length: 11 * 100cm = 1100cm
    // Brick length: 20cm
    return (row * 100) / brick;
}

void displayBrickResults(const int brickLength, float rowLength, float totalBricks)
{
    printf("Brick length: %d\nRow length: %.2fm\nTotal bricks: %.2f\n", brickLength, rowLength, totalBricks);
    return;
}
#pragma endregion