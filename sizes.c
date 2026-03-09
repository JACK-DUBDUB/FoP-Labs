#include <stdio.h>
#include <math.h>

int power(int sq, int num)
{
	int count = 0;
	int retval = 1;
	while(count < num) {
		retval *= sq;
		count++;
	}
	return (retval);
}

int main()
{
	int size, max, min;

	/*******************************
	 * Calculate the size of an int
	 *******************************/
	size = sizeof(int) * 8;
	printf("\nThe size of an int variable is %d bits. \n", size);

	/* maximum value is 2^(n-1)-1 where n is the size in bits. */
	max = power(2, (size-1)) - 1; // 2147483647 for 32 bit
	
	/* minimum value is -2^(n-1) where n is the size in bits */
	min = 0 - power(2, (size-1)); // -2147483648

	printf("The maximum value that can be stored is %d and the minimum is %d\n\n", max, min);

	/*******************************
	 * Calculate the size of a long int
	 *******************************/
	size = sizeof(long int) * 8;
	printf("The size of a long int variable is %d bits. \n", size);

	/* maximum value is 2^(n-1)-1 where n is the size in bits. */
	max = power(2, (size-1)) - 1;
	
	/* minimum value is -2^(n-1) where n is the size in bits */
	min = 0 - power(2, (size-1));

	printf("The maximum value that can be stored is %d and the minimum is %d\n\n", max, min);

	/*******************************
	 * Calculate the size of an char
	 *******************************/
	size = sizeof(char) * 8;
	printf("The size of an char variable is %d bits. \n", size);

	/* maximum value is 2^(n-1)-1 where n is the size in bits. */
	max = power(2, (size-1)) - 1;
	
	/* minimum value is -2^(n-1) where n is the size in bits */
	min = 0 - power(2, (size-1));

	printf("The maximum value that can be stored is %d and the minimum is %d\n\n", max, min);

	/*******************************
	 * Calculate the size of an float
	 *******************************/
	size = sizeof(float) * 8;
	printf("The size of a float variable is %d bits.\n\n", size);

	/*******************************
	 * Calculate the size of an double
	 *******************************/
	size = sizeof(double) * 8;
	printf("The size of a double variable is %d bits.\n\n", size);

	return(0);
}

	

