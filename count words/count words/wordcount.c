#include <stdio.h>
#include <ctype.h>

int foundNextWord(void);

int main() {

	int wordCount = 0;

	while (foundNextWord() == 1) {
		++wordCount;
	}

	printf("\nNumber of words = %d\n\n", wordCount);

	return 0;
}

int foundNextWord(void) {

	int c;

	while (isspace(c = getchar()))
		;//skip white spaces

	if (c != EOF) {//found a word
		while ((c = getchar()) != EOF && !isspace(c))
			;//skip all except EOF and white space
		return 1;
	}
	return 0;
}