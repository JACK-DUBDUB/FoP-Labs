








#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char date_created[12];
    char email[256];
    char f_name[64];
    char l_name[64];
} Customer;

float* copyArray(const float *source, int size);
float* copyArrayReversed(const float *source, int size);
void displayArray(const float*source, int size);

int main()
{
    Customer customer1;    

    float farray[] = {0.1, 0.2, 0.3};
    int farray_size = sizeof(farray) / sizeof(farray[0]);
    displayArray(farray, farray_size);

    // Copy forwards
    float *f_copy = copyArray(farray, farray_size);
    displayArray(f_copy, farray_size);

    // Reversed
    float *f_reversed = copyArrayReversed(farray, farray_size);
    displayArray(f_reversed, farray_size);

    if (f_copy != NULL)
    {   
        free(f_copy);
    }
    
    if (f_reversed != NULL)
    {
        free(f_reversed);
    }
    return 0;
}


float* copyArray(const float *source, int size)
{
    float* targetArray;
    //targetArray = calloc(size, sizeof(float));
    targetArray = malloc(size * sizeof(float));
    if (targetArray == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        targetArray[i] = source[i];
    }

    return targetArray;
}

float* copyArrayReversed(const float *source, int size)
{
    if (source == NULL || size == 0)
    {
        return NULL;
    }

    float *targetArray = malloc(size * sizeof(float));

    // Remember to check for null
    if (targetArray == NULL)
    {
        return NULL;
    }

    int index = size - 1;
    for (int i = 0; i < size; i++)
    {
        targetArray[index] = source[i];
        index--;
    }

    return targetArray;
}

void displayArray(const float*source, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Value %i: %.2f \n", i, source[i]);
    }
    printf("\n\n");
}