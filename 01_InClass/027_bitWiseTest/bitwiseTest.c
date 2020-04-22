#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
void printBinary( unsigned int input );


int main(int argc, char *argv[])
{
	unsigned int a = 12, b = 25;

	// AND
	printf("\n*** AND ***\n");
	printBinary( a );
	printBinary( b );
	printBinary( a&b );

	// OR
	printf("\n*** OR ***\n");
	printBinary( a );
	printBinary( b );
	printBinary( a|b );

	// XOR
	printf("\n*** XOR ***\n");
	printBinary( a );
	printBinary( b );
	printBinary( a^b );

	// Complement
	printf("\n*** Complement ***\n");
	printBinary( a );
	printBinary( ~a );

	// shift left
	printf("\n*** shift left ***\n");
	printBinary( a );
	printBinary( a << 1 );	

	// shift right
	printf("\n*** shift right ***\n");
	printBinary( a );
	printBinary( a >> 1 );

	// bit masking: Set bit 5  --> OR !!
	unsigned char c 	= 0b00001100;
	unsigned char mask 	= 0b00100000;	// set bit 5
	printf("\n*** set bit 5 ***\n");
	printBinary( c );
	unsigned char d = c |mask;
	printBinary( d );
	mask = 1;	// 0b00000001
	printBinary( c | 1 << 5 ); // wichtig !!

	// bit masking: Clear bit 5  --> AND !!
	mask 	= 0b11011111;	// Clear bit 5
	printf("\n*** clear bit 5 ***\n");
	printBinary( d );
	printBinary( d & mask );
	mask = 1;	// 0b00000001
	printBinary( d & ~(1 << 5) ); // wichtig !!

	// check bit 3
	printf("\n*** check bit 3 ***\n");
	printBinary( d );
	mask = 0b00001000;
	printBinary( d & mask );
	printBinary( (d & (1 << 3)) >> 3);

	// flip bits 0 and 3
	printf("\n*** flip bit 3 and 0 ***\n");
	printBinary( d );
	mask = 0b00001001;
	printBinary( d ^ mask);
	printBinary( d ^ ((1<<3)|(1)) );



	return EXIT_SUCCESS;
}


/* function implementation */

void printBinary( unsigned int input )
{
	unsigned int i = 0;

	printf("%u =  \t 0b", (unsigned short)input);

	for( i = (1 << 15) ; i > 0; i = (i >> 1))
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



