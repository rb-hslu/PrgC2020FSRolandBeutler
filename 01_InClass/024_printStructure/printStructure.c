#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

struct Student
{
	char name[MAX_NAME_LENGTH];
	int age;
};

/* function prototypes */
void printStudentPassByValue(struct Student inputStudent );
void printStudentPassByVReference(struct Student *inputStudent );


int main(int argc, char *argv[])
{
	struct Student student1; // instantiate a Student

	printf("Enter name: ");
	fgets(student1.name, MAX_NAME_LENGTH, stdin);

	printf("Enter age: ");
	scanf("%d", &student1.age);

	printStudentPassByValue( student1 );

	printStudentPassByVReference( &student1 );

	
	return EXIT_SUCCESS;
}


/* function implementation */

void printStudentPassByValue(struct Student inputStudent )
{
	printf("\nStudent information (by value):\n");
	printf(  "-------------------------------\n");
	printf("Name: %s", inputStudent.name);
	printf("Age: %d\n", inputStudent.age);
	inputStudent.age++;
}


void printStudentPassByVReference(struct Student *inputStudent )
{
	printf("\nStudent information (by reference):\n");
	printf(  "-------------------------------\n");
	printf("Name: %s", inputStudent->name );
	printf("Age: %d\n\n", inputStudent->age );
	inputStudent->age++;
}



























