/* Find the avaerage grade from an undetermined set of students */

#include <stdio.h>

int main(void) {

	int total = 0;
	int counter = 0;
	int grade = 0;
	float average = 0;

	printf("Enter grade, -1 to end");
	scan("%d", &grade);

	while (grade != -1) {

		total = total + grade;
		counter = counter + 1;

		printf	printf("Enter grade, -1 to end");
		scan("%d", &grade);

	}

	if (total != 0) {

		average = (float)total / counter;

		printf("The class average is: %.2f\n", average);
	}
	else {
		printf("No grades were entered\n");
	}


	return 0;

}