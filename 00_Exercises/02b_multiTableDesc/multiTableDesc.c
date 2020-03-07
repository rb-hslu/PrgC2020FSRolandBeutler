#include <stdio.h>
#include <stdlib.h>

void printUsageMessage(void);
void printMultiTable(int);

const int lowerLimit = 1;
const int upperLimit = 20;


int main(int argc, char* argv[])
{
	int inputValue = 0;

	if(argc != 2)
	{
		// no valid input number
		printUsageMessage();
		return 0;
	}
	else
	{
		inputValue = atoi(argv[1]);
		
		if(inputValue >= lowerLimit && inputValue <= upperLimit)
		{
			// input is valid
			printMultiTable(inputValue);
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
	printf("Usage: multiTable wholeNumber\n\twholeNumber: integer on the interval[%d,%d]\n",lowerLimit,upperLimit);
}

void printMultiTable(int tableLimit)
{
	for(int i = 1; i <= tableLimit; i++)
	{
		for(int j = tableLimit; j >= 1; j--)
		{
			printf("%d\t",i*j);
		}
		printf("\n");
	}
}


