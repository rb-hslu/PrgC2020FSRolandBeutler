#include <stdio.h>
/* Print size of data types */


int main(void)
{
//in Byte
	printf("Printing date type sizes:\n");
	printf("Size of char: %ld Byte\n",sizeof(char));
	printf("Size of short: %ld Byte\n",sizeof(short));
	printf("Size of int: %ld Byte\n",sizeof(int));
	printf("Size of long: %ld Byte\n",sizeof(long));
	printf("Size of long long: %ld Byte\n",sizeof(long long));
	printf("Size of float: %ld Byte\n",sizeof(float));
	printf("Size of double: %ld Byte\n",sizeof(double));
	printf("Size of long double: %ld Byte\n",sizeof(long double));

//in bits
	printf("\nPrinting date type sizes:\n");
	printf("Size of char: %ld bits\n",sizeof(char)*8);
	printf("Size of short: %ld bits\n",sizeof(short));
	printf("Size of int: %ld bits\n",sizeof(int)*8);
	printf("Size of long: %ld bits\n",sizeof(long)*8);
	printf("Size of long long: %ld bits\n",sizeof(long long)*8);
	printf("Size of float: %ld bits\n",sizeof(float)*8);
	printf("Size of double: %ld bits\n",sizeof(double)*8);
	printf("Size of long double: %ld bits\n",sizeof(long double)*8);


	return 0;
}

