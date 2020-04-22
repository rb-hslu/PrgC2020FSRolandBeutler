/*
Module: bit operations supporting the handling
of register manipulations on microcontrollers
*/

// this modules header
#include "bitOperation.h"


// source file

void SetBitNof8( unsigned char* target, unsigned char bitNumber)
{
	*target = (*target | ( 1 << bitNumber) );
}

void ClearBitNof8( unsigned char* target, unsigned char bitNumber)
{
	*target = (*target & ~( 1 << bitNumber ) );
}

void FlipBitNof8( unsigned char* target, unsigned char bitNumber)
{
	*target = (*target ^ ( 1 << bitNumber ) );
}

unsigned char CheckBitNof8( unsigned char target, unsigned char bitNumber)
{
	// sexy version
	return ( target & (1 << bitNumber)) >> bitNumber;

	// long version

	/*
	unsigned char BitIsSet = 0;

	if( ( target & (1 << bitNumber)) >> bitNumber)
	{
		BitIsSet = 1;
	}
	else
	{
		BitIsSet = 0;
	}

	return BitIsSet;
*/
}





