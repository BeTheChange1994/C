#include <stdio.h>
#include <ctype.h>

int main(void) {
	
	char filename[100];
	FILE* fileptr;

	int letters[26] = { 0 };
	char c;

	printf("Name of file to process? ");
	scanf("%s", filename);

	fileptr = fopen(filename, "r");
	if (fileptr == NULL) {
		printf("Unable to open the file '%s' for input!\n", filename);
	}
	else{
		while (!feof(fileptr)) {
			fscanf(fileptr, "%c", &c);
			c = toupper(c);
			if (c >= 'A' && c <= 'Z')
				letters[c - 'A']++;
		}
		fclose(fileptr);

		printf("The file '%s' contains the following occurrences of letters:\n\n", filename);
		for (c = 'A'; c <= 'Z'; c++) {
			printf("%c : %d\n", c, letters[c - 'A']);
		}
	}
	return 0;
}