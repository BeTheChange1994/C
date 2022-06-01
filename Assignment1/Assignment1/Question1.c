/* Program that takes two numbers from the user an shows their sum, product, difference, quotient and remainder */

#include <stdio.h>

int main(void) {

	int input1;
	int input2;

	printf("Enter first integer\n");
	scanf("%d", &input1);

	printf("Enter second integer\n");
	scanf("%d", &input2);

	printf("The sum of the two numbers is: %d\n", input1 + input2);
	printf("The product of the two numbers is: %d\n", input1 * input2);
	printf("The difference of the two numbers is: %d\n", input1 - input2);
	printf("The quotient of the two numbers is: %d\n", input1 / input2);
	printf("The remainder of the two numbers is: %d\n", input1 % input2);

	return 0;
}