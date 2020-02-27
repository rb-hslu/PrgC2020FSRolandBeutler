#include <stdio.h>
/* Binary Number Printer */


int main(void)
{
	// "programmer input"
	int decimalNumber = 13;

	printf("Initial Decimal: %d\n", decimalNumber);
	printf("Binary Form (LSB to MSB): 0b");

	// needed variables for calculation
	int divisionResult = decimalNumber;
	int remainder = 0;

	while(divisionResult > 0)
	{
		remainder = divisionResult%2;
		printf("%d",remainder);
		divisionResult = divisionResult/2;
	}

	printf("\n");
	return 0;	

}




