// main.c
#include <stdio.h>

int read_userYear(int max);
int read_userMonth(int min, int max);
int calc_ageInMonths(int cYear, int cMonth, int uYear, int uMonth);
void displayAge(int ageInMonths);

int main ()
{
    const int currentYear = 2024;
    const int currentMonth = 5;
    
    int uYear = 1;
    while (uYear > 0)
    {
        uYear = read_userYear(currentYear);
        if (uYear < 1)
        {
            break;
        }
        
        int uMonth = 0;
        if (uYear == 2024)
        {
           uMonth = read_userMonth(1, currentMonth);
        }
        else
        {
            uMonth = read_userMonth(1, 12);
        }
        
        int ageInMonths = calc_ageInMonths(currentYear, currentMonth, uYear, uMonth);
        
        displayAge(ageInMonths);
    }   
   
    return 0;
}

// functions.c
// #include <stdio.h>
int read_userYear(int max)
{
    int user_int =  0;
    do {
        printf("Please enter a year: ");
         if (scanf("%i", &user_int))
         {
             if (user_int > max)
             {
                 printf("User entered a value outside of range!\n");
                 user_int = 0;
             }
             else 
             {
                break;
             }
         }
         else
         {
             printf("User entered an invalid value!\n");
             getchar();
         }
    } while (1);
    
    return user_int;
}

int read_userMonth(int min, int max)
{
    int user_int =  0;
    do {
        printf("Please enter a month: ");
         if (scanf("%i", &user_int))
         {
             if (user_int < min || user_int > max)
             {
                 printf("User entered a value outside of range!\n");
                 user_int = 0;
             }
         }
         else
         {
             printf("User entered an invalid value!\n");
             getchar();
         }
    } while (user_int == 0);
    
    return user_int;
}

int calc_ageInMonths(int cYear, int cMonth, int uYear, int uMonth)
{
    int result = ((cYear * 12) + cMonth) - ((uYear * 12) + uMonth);
    return result;
}

void displayAge(int ageInMonths)
{
    printf("The person is %i years(s) and %i month(s) old.\n\n", (ageInMonths / 12), (ageInMonths % 12));
    return;
}