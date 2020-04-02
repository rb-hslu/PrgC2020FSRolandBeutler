#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50

/* function prototypes */

int main(int argc, char *argv[])
{
	char inputString[MAX_INPUT_LENGTH];
	char *pCurrentChar = NULL;
	int countVovels = 0, countConsonants = 0;
	

	printf("\n\nCount the number of vowels and consonants: \n");
	printf(    "------------------------------------------ \n");
	printf("Input a string (max. %d): ", MAX_INPUT_LENGTH);

	fgets( inputString, MAX_INPUT_LENGTH, stdin);
 
	pCurrentChar = inputString;		// set pointer to first element

	while( *pCurrentChar != '\0' )
	{
		printf("0x%x\n", *pCurrentChar);

		char temp = toupper(*pCurrentChar);

		if(temp == 'A' || temp == 'E' || temp == 'I' || temp == 'O' || temp == 'U')
		{
			countVovels++;
		}
		else
		{
			
			// ignore whitespace
			if( !isspace(temp) )
			{
			countConsonants++;
			}
		}
		

		pCurrentChar++;
	}

	printf("Number of vowels: %d, Number of consonants: %d\n", countVovels, countConsonants);


	
	return EXIT_SUCCESS;
}


/* function implementation */


