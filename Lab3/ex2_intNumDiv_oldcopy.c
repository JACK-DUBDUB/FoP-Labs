




// Lib
#include <stdio.h>
#include <math.h>   // Needed to use pow()

// Functions
int intValidator();


int main()
{
    int usrInt1, usrInt2;

    usrInt1 = intValidator();
    usrInt2 = intValidator();

    if(usrInt2 == 0){
        printf("\nSecond input is not valid.\n\n");
    }
    else{
        double divOfInts = usrInt1 / (double) usrInt2;
        int modulusOfInts = usrInt1 % usrInt2;
        printf("\nFirst user input: %d\n", usrInt1);
        printf("Second user input: %d\n", usrInt2);
        printf("%d divided by %d equals: %f\n", usrInt1, usrInt2, divOfInts);
        printf("%d modulus %d equals: %d, remainder: %d\n\n", usrInt1, usrInt2, usrInt1/usrInt2, modulusOfInts);
    }

    printf("Press enter to quit program...");
    getchar();
    getchar();

    return 0;
}


int intValidator()
{
    char input[9];                          // 9 digits <- does not exceed the min/max of int-32 -99,999,99 <-> 999,999,999 
    printf("Enter a valid integer number: ");
    scanf("%s", input);
    //printf("You entered: %s\n", input);

    int length = sizeof(input);
    //printf("Length of array: %d\n", length);

    int isValid = 1;
    int actualLength = 0;
    int isNegative = 0;

    for(int i = 0; i < length; i++)         // My own "strlen()" function
    {

        char getChar = input[i];            
        if(input[i] == 00)                  // I designed the max string length to be 9, any values not inserted will be equal to null
        {
           break;
        }

        if(i == 0 && getChar == 48)         // If the char value at position 0 is equal to 0 
        {
            //printf("Not a valid value: Value cannot be zero\n\n");
            isValid = 0;
            break;
        }

        if(i == 1 && getChar == 48 && isNegative)         
        {
            printf("Not a valid value: Value cannot be negative zero\n\n");
            isValid = 0;
            break;
        }
            
        if(i == 0 && getChar == '-')
        {
            isNegative = 1;
        }
        else if(getChar < 48 || getChar > 57)    // If the char value is not within the range of valid integers
        {
            printf("Not a valid value: User did not enter a valid integer\n");
            printf("Value entered: '%s', Value position: '%d', Value: %c\n\n", input, i, getChar);
            isValid = 0;
            break;
        }

        actualLength++;
    }

    // I'm aware theres libraries for this... But I wanted to try it without using other external libraries
    if(isValid)
    {
        //printf("User entered a valid number\n");
        //printf("Actual string length: %d\n", actualLength);

        int validInput = 0;
        for(int i = 0; i < actualLength; i++)
        {
            char getChar = input[i];                   // Get actual number value
            
            // If the number is not negative, then the multiplication is applied 
            if(!isNegative)
            {
                validInput += (getChar - 48)*pow(10, (actualLength - i - 1)); // value * 10^(digit location)
                //printf("%d\n", validInput);
            }
            // If the number is negative and the cell is not [0] then we do apply the multiplication accordingly
            else if(isNegative && i != 0){
                validInput += (getChar - 48)*pow(10, (actualLength - i - 1));
                //printf("%d\n", validInput);
            }
        }
        
        if(isNegative)
        {
            validInput *= -1;
        }

        return validInput;
    }


    return 0;
}