#include <stdio.h>
/* Test if-else */




int main(void)
{
	int testValue = 0;
	int limitValue = 0;
	
	printf("Give Number 1 to test: ");
	scanf("%d", &testValue);

	printf("Give Number 2 to test: ");
	scanf("%d", &limitValue);

	if(testValue >= limitValue){
		printf("%d is bigger or equal to %d\n", testValue, limitValue);
	}
	else{
		printf("%d is less than %d\n", testValue, limitValue);
	}

	return 0;
}

