#include <stdio.h>
/* test scanf */


int main(void)
{
	int readValue = 0;
	printf("Enter an int: ");
	scanf("%d", &readValue);

	printf("Value entered: %d", readValue);

	return 0;
}

