#include <stdio.h>

typedef struct {
	char* firstname;
	char* lastname;
	char* dob;
	int id;
} Student;

int main(void) {

	Student s1;
	Student* sPtr;

	s1.firstname = "John";
	s1.lastname = "Smith";
	s1.dob = "10/03/1985";
	s1.id = 301455;

	sPtr = &s1;

	printf("Student name is %s %s\n", s1.firstname, s1.lastname);
	printf("Student name is %s %s\n", sPtr->firstname, sPtr->lastname);
	printf("Student name is %s %s\n", (*sPtr).firstname, (*sPtr).lastname);

	return 0;
}