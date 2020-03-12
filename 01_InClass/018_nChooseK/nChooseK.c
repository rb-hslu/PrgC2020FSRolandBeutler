#include <stdio.h>
#include <stdlib.h>

/* compute n choose k */

// prototype
long factorial(long n);
long nChooseK(int n, int k);


int main( int argc, char* argv[] )
{
    int n = 0, k = 0, waitOnValidInput = 1;
	while(waitOnValidInput){
		printf("*****************************************\n");
		printf("Calculate n choose k:\n");
		printf("-----------------------------------------\n");
	    printf("Enter n and k (positive integers, n >= k): ");
    	scanf("%d %d",&n,&k);
	    //printf("Enter k (positive integer): ");
    	//scanf("%d",&k);
		if(n >= k && k >= 0) {
		    printf("(%d choose %d) = %ld\n", n, k, nChooseK(n,k));
			break;
		}
		else
		{
			printf("Invalid input. Try again.\n");
		}
	}
	return EXIT_SUCCESS;
}

// implementation of the factorial function
long  factorial(long n) {
    if (n>=1)
	{
        return n*factorial(n-1);
	}
    else
	{
        return 1;
	}
}

// implementation of n choose k function
long nChooseK(int n, int k){
	long result = 0;
	result = factorial(n)/(factorial(k) * factorial(n-k));
	return result;
}


