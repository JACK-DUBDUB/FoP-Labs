#include <stdio.h>
#include "a2_create.h"

// ============ CREATE ============

int create_handleDataOut(const Customer *customers, const Currency *currencies, const char *file_name, const int rows)
{
    FILE *outfile;
    int out_value = 0, error_code = 0;

    error_code = fopen_s(&outfile, file_name, "w");

    if (!!error_code) {
        printf("Error code: %i \n", error_code);
        return -1;
    }

    out_value = create_customerDataOut(outfile, customers, currencies, rows);

    fclose(outfile);

    return out_value;
}

int create_customerDataOut(FILE *outfile, const Customer *customers, const Currency *currencies, const int rows)
{
    // Example print: "'name', the change for 'x' cents in '$XYZ' is 'a,b,c,d'\n"
    int rows_printed = 0;
    for (int i = 0; i < rows; i++)
    {
        if (customers[i].name == NULL) {
             break;
        }
        for (int j = 0; j < MAX_CURRENCY_TYPES; j++)
        {
            if (!customers[i].change_values[j]) {
                continue;
            }

            fprintf(outfile, "%s, the change for %i cents in %s is ", customers[i].name, customers[i].change_values[j], currencies[j].code);
            
            for (int k = 0; k < MAX_COIN_VARIANTS; k++) {

                if (k + 1 == MAX_COIN_VARIANTS){
                    fprintf(outfile, "%i\n", customers[i].coins_ptr[j][k]);
                } 
                else {
                    fprintf(outfile, "%i,", customers[i].coins_ptr[j][k]);
                }
            }
            rows_printed++;
        }
    }
    return rows_printed;
}