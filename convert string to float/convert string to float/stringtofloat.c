#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char input[100];
	double dnum;

	printf("Enter a string that icludes a monetary value: ");
	gets(input);

	dnum = atof(input);
	printf("%s%.2f\n%s%.2f\n",
		"The string converted to double ins ", dnum,
		"The converted value divided by 2 is ", dnum / 2.0);
	return 0;
}