#include <stdio.h>
#include <stdlib.h>

int main(void) {

	const char* string = "-1234567abbc";//Initialize string pointer

	char* remainderPtr;
	long x;

	x = strtol(string, &remainderPtr, 0);

	printf("%s\"%s\"\n%s%ld\n%s\"%s\"\n%s%ld\n",
		"The original string is ", string,
		"The converted value is ", x,
		"The remainder of the original string is ",
		remainderPtr,
		"The converted value plus 567 is ", x + 567);
	return 0;
}