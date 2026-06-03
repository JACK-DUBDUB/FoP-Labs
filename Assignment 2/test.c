






#include <stdio.h>
/*

int main()
{
    int n = 0;
    int sum = 0;
    while (n < 100) // While N is less than 100, we continue looping
    {
        printf("\nEnter a number: ");
        scanf("%i", &n);

    }
    printf("Exit\n");

    return 0;
}*/


/*
int is_positive(int number)
{
    if (number <= 0)
	{
		return 0;
	}

	return 1;
}


int main()
{
    int number = 0;
    int sum = 0;

    printf("Please enter a number: ");
    scanf("%i", &number);
    while (number < 100)
    {
        if (is_positive(number) )
        {
            sum += number;
        }
        
        printf("Enter next number: ");
        scanf("%i", &number);
    }
    printf("Sum: %i\n", sum);
    return 0;
}
*/

/*
int read_year()
{
    int user_input;
    do {
        printf("Please enter a birth year: ");
        if(scanf("%i", &user_input) != 1)
        {
            printf("User did not enter an integer\n");
        }
        else
        {
            break;
        }

    } while (1);
 
    return user_input;
}

int read_month()
{
    int user_input = 0;
    do {
	printf("Enter a valid birth month: ");	
	scanf("%i", &user_input);

	} while(user_input < 1 || user_input > 12);
    return user_input;
}

void display_age(int u_year, int u_month)
{
    if (u_year > 2024)
    {
        printf("E1 Invalid birth year\n");
        return;
    }
    if (u_year == 2024 && u_month > 5)
    {
        printf("E2 Invalid birth date\n");
        return;
    }

    int age_m;
    int age_y = 2024 - u_year;
    if ((5 - u_month) < 0)
    {
        age_m = (u_month - 6);
        age_y--;
    }
    else
    {
        age_m = 5 - u_month;
    }


    printf("The person is %i year(s) and %i month (s) old.\n", age_y, age_m);

    return;
}


int main()
{
	int user_month;
	int user_year = 0;
	
	do {
		user_year = read_year();
		if(user_year >  0)
		{
			user_month = read_month();
			display_age(user_year, user_month);
		}

	} while (user_year >  0);

    return 0;
}*/


// Question 4
/*
    Errors noticed:
    missing ampersand for insertion of integer value
    printf() function is not printing the value of the sum
    Program is missing the 5 other numbers

*/

/*
// in main.c
#define SIZE 10

// functions.c
int read_integer()
{
    int user_int = 0;
    printf("\nPlease enter a number> ");
    if (scanf("%i", &user_int))
    {
        return user_int;
    }
    else {
        printf("Invalid Number\n");
    }
    return user_int;
}

void collect_numbers(int array[], int size)
{
    for (int i = 0; i < size; i++) // <- reducing code repeat
    {
        array[i] = read_integer();
    }
}


int calc_sum(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += array[i];
    }
    return sum;
}

// main.c

int main ()
{
    int array[SIZE];

    collect_numbers(array, SIZE);

    int sum = calc_sum(array, SIZE);

    printf("The sum is: %i", sum); // <- printing correct sum

    return 0;
}*/



// Question 5

/*
// Structure chart (you can't read structure charts yet mr deepseek)
// MAIN
    <-> read_intInRange(max); return (user_input);
    <-> calc_diff(num1, num2); return (diff);
    <-> calc_sum(num1, num2); return (sum);
    <-> calc_prod(num1, num2); return (prod);

// | CASE   | VALUES    | EXPECTED OUTPUT | DESK CHECK | P/F |


*/



// func.c
int read_intInRange(int max)
{
    int user_input = 0;

    printf("Please enter a number: ");
    if(scanf("%i", &user_input) != 1)
    {
        printf("\nUser did not enter a valid integer\n");
    }

    if (user_input > max)
    {
        user_input = -1;
    }

    return user_input;
}


int calc_diff(int num1, int num2)
{
    int diff = num1 - num2;

    return diff;
}

int calc_sum(int num1, int num2)
{
    int sum = num1 + num2;

    return sum;
}


int calc_prod(int num1, int num2)
{
    int prod = num1 * num2;

    return prod;
}


// main.c

int main()
{
    int array[10];
    int size = sizeof(array) / sizeof(int);
    int dup[size];

    printf("Size of dup: %i\n", size);


    int user_int1;
    int user_int2;
    
    do {
        user_int1 = read_intInRange(1000);
        user_int2 = read_intInRange(1000);

        if(user_int1 < 1 || user_int2 < 1)
        {
            break;
        }

        printf("Number 1: %i, Number 2: %i\n", user_int1, user_int2);
        printf("Difference of %i - %i = %i\n", user_int1, user_int2, calc_diff(user_int1, user_int2));
        printf("Summation of %i + %i = %i\n", user_int1, user_int2, calc_sum(user_int1, user_int2));
        printf("Product of %i x %i = %i\n\n\n", user_int1, user_int2, calc_prod(user_int1, user_int2));

    }while (1);
    return 0;
}








