//nested loops for list entered by user

#include <stdio.h>

int main(void) {

	//initialization phase
	float number = 0, total = 0, average = 0;
	int numbersentinel = -1, listsentinel = 1, numbercount = 0;

	while (listsentinel != 0) {

		printf("\nEnter a number, -1 to finish >>");
		scanf("%f", &number);

		while (number != numbersentinel) {
			
			total = total + number;
			numbercount++;
			printf("\nEnter a number, -1 to finish >>");
			scanf("%f", &number);
		}

		average = total / numbercount;
		printf("\nAverage = %.2f\n", average);

		printf("\nAnother list? Enter 1 for Yes, 0 for No >>");
		scanf("%d", &listsentinel);

		numbercount = 0;
		number = 0;
		total = 0;
		average = 0;

	}

	return 0;

}