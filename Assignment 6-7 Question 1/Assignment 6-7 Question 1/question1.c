#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void){

	char filename[100];
	FILE* filePtr = NULL;

	char timestamps[50][20];

	int i = 0;
	
	while (filePtr == NULL) {

		printf("Name of file to process? ");
		scanf("%s", filename);

		filePtr = fopen(filename, "r");
	}

	char line[20];
	while (fgets(*line, sizeof(line), filePtr) != NULL) {

		strncpy(timestamps[i], *line, sizeof(*line));
		i++;	

	}

	for (int j = 0; j < i; j++) {
		printf("%s\n", timestamps[j]);
	}

	return 0;
	}