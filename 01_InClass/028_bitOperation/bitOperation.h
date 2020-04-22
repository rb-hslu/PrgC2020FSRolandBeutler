/*
Module: bit operations supporting the handling
of register manipulations on microcontrollers
*/

// Header file


#ifndef _H_BIT_OPERATON_H_
#define _H_BIT_OPERATON_H_

// function prototypes
void SetBitNof8( unsigned char* target, unsigned char bitNumber);
void ClearBitNof8( unsigned char* target, unsigned char bitNumber);
void FlipBitNof8( unsigned char* target, unsigned char bitNumber);
unsigned char CheckBitNof8( unsigned char target, unsigned char bitNumber);

#endif // _H_BIT_OPERATON_H_

