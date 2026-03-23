/**
 * 
 * // High level
 *  START
 *      Insert 10 temperature values
 *      Convert values int 
 *      
 *      
 * 
 * // Low level
 * 
 * 
 * /// Compile and Run
 * gcc '.\ex7_water_main.c' '.\ex7_water_func.c'  -o ex7_water
 * .\ex7_water.exe
 */

#include <stdio.h>
#define LIMIT 10
#define ZERO_C -273.15  // = 0 k   WAter = 
#define ZERO_F 32       // = 0 k
#define MUL_C 1         // 
#define MUL_F 1.8       // 9/5 = 1.8
#define GAS 100

void getSamples(float kelvinSamples[]);
void getState(float kelvinSamples[], float celsiusSamples[], float fahrenheitSamples[]);
void getConversions(float kelvinSamples[], float samples[], float mul, float unit);

int main()
{
    // Get Kelvin
    float kelvinSamples[LIMIT];
    float celsiusSamples[LIMIT];
    float fahrenheitSamples[LIMIT]; 
    
     // Kelvin
    getSamples(kelvinSamples);

    // Conversions
    getConversions(kelvinSamples, celsiusSamples, MUL_C, ZERO_C);
    getConversions(celsiusSamples, fahrenheitSamples, MUL_F, ZERO_F);

    // Min Max


   

    // Min Max
    //getMinMax(celsiusSamples, kelvinSamples);

    // Average
    //getAverage(celsiusSamples, kelvinSamples);
    
    // State 
    getState(kelvinSamples, celsiusSamples, fahrenheitSamples);


    return 0;
}

void getConversions(float kelvinSamples[], float samples[], float mul, float unit)
{
    for(int i = 0; i < LIMIT; i++)
    {
        samples[i] = kelvinSamples[i] * mul + unit; 
    }
    return;
}

void getSamples(float kelvinSamples[])
{
    float input;
    int valid;
    printf("Insert [%d] temperature samples (Kelvin) \n", LIMIT);
    for(int i = 0; i < LIMIT; i++)
    {
        printf("Sample [%d]: ", i + 1);

        valid = scanf("%f",&input);
    
        if(getchar() != '\n')
        {
            while(getchar() != '\n');
            valid = 0;
        }

        if(valid)
        {
            kelvinSamples[i] = input;
        }
        else
            i--;
    }

    return;
}

void getState(float kelvinSamples[], float celsiusSamples[], float fahrenheitSamples[])
{
    printf("\n-------- State Of Matter --------\n");
    for (int i = 0; i < LIMIT; i++)
    {
        printf("---- Sample [%d] ----\n", i + 1 );
        printf("Kelvin:      %.2f\n", kelvinSamples[i]);
        printf("Celsius:     %.2f\n", celsiusSamples[i]);
        printf("Fahrenheit:  %.2f\n", fahrenheitSamples[i]);

        if(celsiusSamples[i] >= GAS)
            printf("State:       GAS\n\n");
        else if(celsiusSamples[i] <= 0)
            printf("State:       SOLID\n\n");
        else
            printf("State:       LIQUID\n\n");
    }

    return;
}

void getMinMax(float celsiusSamples[], float kelvinSamples[])
{
    
}