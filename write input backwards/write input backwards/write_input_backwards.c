#include <stdio.h>

void reverse(const char* const sPtr);

int main(void) {

	char sentence[80];

	printf("Enter a line of text:\n");

	//use fgets to read line of text
	fgets(sentence, 80, stdin);

	printf("\nThe line printed backwards is:\n");
	reverse(sentence);
	return 0;
}

void reverse(const char* const sPtr) {

	if (sPtr[0] == '\0') {
		return;
	}
	else {
		reverse(&sPtr[1]);
		putchar(sPtr[0]);
	}
}