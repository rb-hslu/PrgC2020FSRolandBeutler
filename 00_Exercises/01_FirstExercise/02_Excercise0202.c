#include <stdio.h>
/* test all arithmetic operations of two numbers */


int main(void)
{
	int numberA = 10;
	int numberB = 4;
	
	printf("Plot all arithmetic operations on numbers %d and %d\n",numberA,numberB);
	printf("Sum = %d\n",(numberA+numberB));
	printf("Difference = %d\n",(numberA-numberB));
	printf("Product = %d\n",(numberA*numberB));
	printf("Quotient = %d\n",numberA/numberB);
	printf("Modulus = %d\n",(numberA%numberB));

	return 0;
}

