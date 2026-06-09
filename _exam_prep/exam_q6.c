






#include <stdio.h>

void remove_duplicates(int array[], int *a_size, int dups[], int *d_size);
void display_array(int array[], int size);

int main()
{
    int array[] = {12, 4, 7, 3, 32, 12, 3, 4};
    int a_size = sizeof(array) / sizeof(array[0]);
    int dups[a_size];
    int d_size = 0;

    remove_duplicates(array, &a_size, dups, &d_size);

    printf("\nUnique list array: \t");
    display_array(array, a_size);

    printf("\nDuplicates list array: \t");
    display_array(dups, d_size);


    return 0;
}

void remove_duplicates(int array[], int *a_size, int dups[], int *d_size)
{
    int limit = *a_size;


    // Find uniques
    int unique[limit];
    int unique_c = 0;
    for (int i = 0; i < limit; i++)
    {
        int value = array[i];
        int isDup = 0;
        for (int j = i + 1; j < limit; j++)
        {
            if(array[j] == value)
            {
                isDup = 1;
                break;
            }
        }
        if (!isDup)
        {
            unique[unique_c] = value;
            unique_c++;
        }
    }

    int count_arr[unique_c];

    for (int i = 0; i < limit; i++)
    {
        int value = array[i];
        for (int j = i; j < unique_c; j++)
        {
            
            if (value == unique[j] && count_arr[j] >= 1)
            {
                dups[*d_size] = value;
                *d_size += 1;
                *a_size -= 1;
            }

            if (value == unique[j])
            {
                count_arr[j] = 1;
                break;
            }
        }
    }      
    return;
}

void display_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }
}


