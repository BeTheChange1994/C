#include <stdio.h>
#include <string.h>

//Global arrays 
char timestamps[50][20];
char sortedtimestamps[50][20];

void bubbleSortArray();

int main(void) {

	//Take file name and open
	char filename[128];
	char outfilename[128];
	FILE* filePtr = NULL;


	while (filePtr == NULL) {

		printf("Enter file name \n");
		scanf("%s", filename);

		filePtr = fopen(filename, "r");

		//Catch incorrect input
		if (filePtr == NULL) {
			printf("Input filename is incorrect or file does not exist! Please try again \n");
		}
	}

	//Ask for output file name
	printf("Enter output file name \n");
	scanf("%s", outfilename);
	printf("Inserted name is: %s \n", outfilename);

	//Read the data into 2 dimentional array
	int i = 0;

	while (fgets(timestamps[i], 25, filePtr)) {
		
		//Remove \n from strings
		char last_char_of_line = timestamps[i][strlen(timestamps[i]) - 1];
		if (last_char_of_line == '\n') {
			timestamps[i][strlen(timestamps[i]) - 1] = '\0';
		}
		
		i++;
	}
	fclose(filePtr);

	//Transform date format
	char day[3];
	char mon[3];
	char year[5];
	char time[10];

	for (int i = 0; i < 50; i++) {
		sscanf(timestamps[i], "%2s/%2s/%4s-%8s", day, mon, year, time);

		sprintf(sortedtimestamps[i], "%4s/%2s/%2s-%8s", year, mon, day, time);
	}

	bubbleSortArray();

	//Transform the data back to original format
	for (int i = 0; i < 50; i++) {
		sscanf(sortedtimestamps[i], "%4s/%2s/%2s-%8s", year, mon, day, time);
		
		sprintf(sortedtimestamps[i], "%2s/%2s/%4s-%8s", day, mon, year, time);
	}

	//Output sorted data
	FILE* f = fopen(outfilename, "wb");

	for (i = 0; i < 51; i++) {
		fprintf(f, "%s\n", sortedtimestamps[i]);
	}
	fclose(f);

	return 0;

}

//Bubble sort 
void bubbleSortArray() {

	char hold[21];

	for (int pass = 1; pass <= 50; pass++) {

		for (int j = 0; j < 50 - pass; j++) {
			if (strcmp(sortedtimestamps[j], sortedtimestamps[j + 1]) > 0) {
				strcpy(hold, sortedtimestamps[j]);
				strcpy(sortedtimestamps[j], sortedtimestamps[j + 1]);
				strcpy(sortedtimestamps[j + 1], hold);
			}
		}
	}
}