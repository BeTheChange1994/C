#include <stdio.h>

long double factorial(long number);

int main(void) {

	int i;
	long long int sum = 0;

	for (i = 0; i <= 19; i++) {

		 sum = sum + (1/factorial(i));
	}

	printf("%Lf", sum);

	return 0;
}

long double factorial(long number) {

	if (number <= 1) {
		return 1;
	}
	else {
		return (number * factorial(number - 1));
	}
}