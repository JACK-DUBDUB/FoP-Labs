/**
 * 10/03/2026 
 * Jack du boulay - 32712899 
 * Exercise 9 -> Bricks and rows
 * Calculates number of bricks required for a row length n by brick length of n
 * 
 * to compile -> gcc 'filename.c' -o 'filename'
 * to run -> .\filename
**/

// Libraries
#include <stdio.h> 

// Functions
float calcTotalBricks(int brick, int row);
void displayBrickResults(const int brickLength, float rowLength, float totalBricks);

#pragma region MAIN 
int main () 
{
    /// Variables ///
    float brickLength, rowLength;

    /// Inputs ///
    printf("Brick length(cm): ");
    scanf("%f", &brickLength);

    printf("Row length(m): ");
    scanf("%f", &rowLength);

    // Calculate
    float totalBricks = calcTotalBricks(brickLength, rowLength);

    // Display
    displayBrickResults(brickLength, rowLength, totalBricks);

    // Exits program safely
    return 0;
}
#pragma endregion

#pragma region Functions
// calculate total number of bricks required
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