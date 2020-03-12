#include <stdio.h>
#include <stdlib.h>

/* User Menu */

typedef enum{
	INVALID = 0,
	PRINTCODERNAME,
	CALCONEPLUSONE,
	EXIT
} MenuSelection;


// function prototype
MenuSelection PrintUserMenu( void );


// main 
int main (int argc, char *argv[] )
{
	int runMenuPrompt = 1;
	MenuSelection menuSelection = INVALID;

	while(runMenuPrompt)
	{
		menuSelection = PrintUserMenu();

	
		switch(menuSelection)
		{
			case PRINTCODERNAME:
			printf("rb\n");
			break;

			case CALCONEPLUSONE:
			printf("1 + 1 = 2.5 (Zitat: Pius Portmann)\n");
			break;

			case EXIT:
			printf("Exiting: Bye ...\n");
			runMenuPrompt = 0;
			break;

			default:
			printf("Error Code: ID-10-T\n");
			//runMenuPrompt = 0;
			break;

		} //switch(menuSelection)
	} // while (runMenuPrompt)
	return EXIT_SUCCESS;
}


// implementation of print of user menu
MenuSelection PrintUserMenu( void )
{
	int selectedMenuItem = 0;
	printf("\n------------------------------------\n");
	printf("* * * * Welcome to CoolCode! * * * *\n");
	printf("------------------------------------\n");
	printf("Select from the following options:\n");
	printf("1: Print Coder Name\n");
	printf("2: Calculate 1+1\n");
	printf("3: exit\n");
	printf("-> ");
	scanf("%d", &selectedMenuItem );
	//printf("%d\n", selectedMenuItem);

	if(		selectedMenuItem != PRINTCODERNAME
		&&	selectedMenuItem != CALCONEPLUSONE
		&&	selectedMenuItem != EXIT )
	{
		selectedMenuItem = INVALID;
	}
	return selectedMenuItem;

}









