#include <stdio.h>
#include "ex6_interest_msgs.h"

// Array of pointers to multiple strings
const char *MENUSELECTION_S[] = {
    "\nChose to view current variable values.\n",                                     // 0
    "\nChose to insert new asset value.\nEnter new asset value: ",                    // 1
    "\nChose to insert new annual interest.\nEnter new annual interest rate: ",       // 2
    "\nChose to insert new duration.\nEnter new loan duration (years): ",             // 3
    "\nChose to insert new down payment amount.\nEnter new down payment amount: ",    // 4
    "\nChose to perform interest calculation.\n",                                     // 5
    "\nChose to quit program.\n",                                                     // 6
    "\nDid not enter a valid menu key.\n"                                             // 7
};

// One big menu "string"
const char* MENU =
"-------- /// MENU /// --------\n Menu keys:\n"
" 'v' - To view current variable values\n"
" 'a' - To insert new asset value\n"
" 's' - To insert new annual interest rate\n"
" 'd' - To insert new duration\n"
" 'f' - To insert new down payment amount\n"
" 'g' - To perform interest calculation\n"
" 'q' - To quit program\n\n";