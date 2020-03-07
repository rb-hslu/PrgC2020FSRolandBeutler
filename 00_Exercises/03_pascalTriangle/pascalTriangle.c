#include <stdio.h>
#include <stdlib.h>

void printUsageMessage(void);
void printPascalTriangle(int);

const int lowerLimit = 1;
const int upperLimit = 20;


int main(int argc, char* argv[])
{
	int inputValue = 0;

	if(argc != 2)
	{
		// no valid number of inputs
		printUsageMessage();
		return 0;
	}
	else
	{
		inputValue = atoi(argv[1]);
		
		if(inputValue >= lowerLimit && inputValue <= upperLimit)
		{
			// input is valid
			printPascalTriangle(inputValue);
		}
		else
		{
			// no valid input
			printUsageMessage();
			return 0;
		}
	}
	
	return 0;
}



void printUsageMessage(void)
{
	printf("Usage: pascalTriangle wholeNumber\n\twholeNumber: integer on the interval[%d,%d]\n",lowerLimit,upperLimit);
}


void printPascalTriangle(int numberOfRows)
{
	int coefficient = 1;
	
	for(int i = 1; i <= numberOfRows; i++)
	{
		// add space to buid triangle
		for(int space = 1; space <= numberOfRows-i; space++)
		{
			printf("   ");
		}
		// loop for columns
		for(int j = 0; j < i; j++)
		{
			if(j == 0)
			{
				printf("%6d", 1);
			}
			else
			{
				coefficient = coefficient * (i-j)/j;
				printf("%6d", coefficient);
			}
		}
		coefficient = 1;
		printf("\n");
	}
}


