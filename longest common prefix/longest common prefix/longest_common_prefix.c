#include <stdio.h>
#include <stdlib.h>

char* commonprefix(char* w1, char* w2);

int main(void) {

	char word1[100], word2[100];
	char* prefix;

	printf("Type 2 words please:\n");
	gets(word1);
	gets(word2);

	prefix = commonprefix(word1, word2);

	printf("The longest common prefix of your words is: %s\n", prefix);

	free(prefix);
}

char* commonprefix(char* w1, char* w2) {

	int len = 0;
	char* p;
	int i;

	while (w1[len] == w2[len] && w1[len] != '\0' && w2[len] != '\0')
		len++;

	p = (char*)malloc(len + 1);

	if (p == NULL) {

		printf("unable to allocate momory!");
		exit(1);
	}

	for (i = 0; i < len; i++) 
		p[i] = w1[i];
	p[len] = '\0';
	return p;
}