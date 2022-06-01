//Assignment 3 Question 1
#include <stdio.h>

int main(void) {

	//initialize variables 
	int num;

	//print question part
	printf("a)");

	//part a loops 10 times counting 1 to 10
	for (num = 1; num <= 10; num++) {
		printf("%d ", num);
	}

	//print question part and spaces
	printf("\n\nb)");

	//part b loops 3 to 23 incrementing by 5
	for (num = 3; num <= 23; num = num + 5) {
		printf("%d ", num);
	}

	//print question part and spaces
	printf("\n\nc)");

	//part c loops from 20 to -10 decrementing by 6
	for (num = 20; num >= -10; num = num - 6) {
		printf("%d ", num);
	}

	//print question part and spaces
	printf("\n\nd)");

	//part d loops between 19 and 51 incrementing by 8
	for (num = 19; num <= 51; num = num + 8) {
		printf("%d ", num);
	}

	//print spaces
	printf("\n\n");


	return 0;
}