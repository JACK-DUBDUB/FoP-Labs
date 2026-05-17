#include "a2_create.h"

// ============ CREATE ============

int create_handleDataOut(const Customer *customers, const Currency *currencies, const char *file_name, const int rows, int *out_value)
{
    FILE *outfile;

    int error_code = fopen_s(&outfile, file_name, "w");

    if (error_code) 
    {
        printf("Error code: %i \n", error_code);
        printf("\nPROGRAM ERROR - Failed to create file '%s' in 'w' mode. \nFile may still be open and/or missing permissions.\n\n", file_name);
        return 0;
    }

    *out_value = create_customerDataOut(outfile, customers, currencies, rows);

    fclose(outfile);
    return 1;
}

int create_customerDataOut(FILE *outfile, const Customer *customers, const Currency *currencies, const int rows)
{
    // Example print: "'name', the change for 'x' cents in '$XYZ' is 'a,b,c,d'\n"
    int rows_printed = 0;
    for (int i = 0; i < rows; i++)
    {
        if (customers[i].name == NULL) 
        {
             break;
        }

        for (int j = 0; j < MAX_CURRENCY_TYPES; j++)
        {
            if (customers[i].change_values[j]) 
            {
                fprintf(outfile, "%s, the change for %i cents in %s is %i,%i,%i,%i\n",
                    customers[i].name, 
                    customers[i].change_values[j], 
                    currencies[j].code, 
                    // Coin amount
                    customers[i].coins_ptr[j][0],
                    customers[i].coins_ptr[j][1],
                    customers[i].coins_ptr[j][2],
                    customers[i].coins_ptr[j][3]
                );
                rows_printed++;
            }
        }
    }
    return rows_printed;
}