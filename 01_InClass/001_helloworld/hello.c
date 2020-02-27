#include <stdio.h>
/*
* our first c program ;)
*/


// function prototype
int TestFunction(void);

// global variable
int TestValueReturn = 0;

// main function
int main(void)
{
	TestValueReturn = TestFunction();
	printf("Hello World!\n");
	printf("TestValue: %d\n", TestValueReturn);
	return 0;
}

// implementation of TestFunction

int TestFunction(void)
{
	int retVal = 99;
	return retVal;
}

