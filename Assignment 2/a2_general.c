#include <ctype.h>
#include "a2_general.h"
#include "a2_crud.h"

// Assumption -> what if names are same but not same case
bool compare_caseInsensitive(const char *ptr_exist, const char *ptr_cmpr)
{
    // Filter
    if (ptr_exist == NULL || ptr_cmpr == NULL) 
        return false;
    if (strlen(ptr_exist) != strlen(ptr_cmpr)) 
        return false;

    // Compare each val
    while (*ptr_exist && *ptr_cmpr)
    {
        if (toupper(*ptr_exist) != toupper(*ptr_cmpr)) 
            return false;

        ptr_exist++, ptr_cmpr++;
    }
    return true;
}

// CODE REUSE -> FUNCTIONS ACTUALLY BEING USED 
int calculate_intDiv(const int dividend, const int divisor)
{
    int quotient = dividend / divisor;
    return quotient;
}

int calculate_intMod(const int dividend, const int divisor)
{
    int remainder = dividend % divisor;
    return remainder; 
}

