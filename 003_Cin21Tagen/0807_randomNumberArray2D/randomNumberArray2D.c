#include <stdio.h>
#include <stdlib.h>
/* Define an Array, fill it with random ints and print it in a table */

enum{ROWS = 7, COLUMNS = 3};

int randNumbers[ROWS][COLUMNS];

/* function prototypes */
void fillArray(void);
void printArray(void);


int main(int argc, char *argv[])
{
	fillArray();

	printArray();

	return 0;
}


/* function initialisiation */

void fillArray(void)
{
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLUMNS; j++)
		{
			randNumbers[i][j] = rand();
		}
	}
}


void printArray(void)
{
	for(int i = 0; i < ROWS; i++)
	{
	printf("\t");	
		for(int j = 0; j < COLUMNS; j++)
		{
			printf("%d\t", randNumbers[i][j]);
		}

	printf("\n");
	}
}

