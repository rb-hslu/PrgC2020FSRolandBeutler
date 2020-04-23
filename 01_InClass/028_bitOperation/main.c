// system headers
#include <stdio.h>
#include <stdlib.h>

// custom headers
#include "bitOperation.h"

// local function prototype
void printBinary( unsigned int input, unsigned char nBitsToPrint );

int main(int argc, char *argv[])
{
	unsigned char testRegister = 0;

	// test 1, setting all bits, one-by-one
	printBinary(testRegister,8);

	for(int i = 0; i < 8 ; i++ )
		{
		SetBitNof8(&testRegister,i);
		printBinary(testRegister,8);
		}
	printf("\n");

	// test 2, clearing all bits, one-by-one
	for(int i = 7; i >= 0 ; i-- )
		{
		ClearBitNof8(&testRegister,i);
		printBinary(testRegister,8);
		}
	printf("\n");

	// test 3, flip every bit twice, one-by-one

	for(int i = 0; i < 8 ; i++ )
		{
		FlipBitNof8(&testRegister,i);
		printBinary(testRegister,8);
		FlipBitNof8(&testRegister,i);
		printBinary(testRegister,8);
		}
	printf("\n");

	// test 4, check every bit twice, first -> false, flip -> true, one-by-one

	for(int i = 0; i < 8 ; i++ )
		{
		printBinary(testRegister,8);
		printBinary(CheckBitNof8(testRegister,i),8);
		FlipBitNof8(&testRegister,i);
		printBinary(testRegister,8);
		printBinary(CheckBitNof8(testRegister,i),8);
		FlipBitNof8(&testRegister,i);
		}
	printf("\n");

	
	return EXIT_SUCCESS;
}




void printBinary( unsigned int input, unsigned char nBitsToPrint )
{
	unsigned int i = 0;

	printf("%u =  \t 0b", (unsigned short)input);

	for( i = (1 << (nBitsToPrint-1)) ; i > 0; i = (i >> 1))
	{
		if(input & i)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
}



