#include <stdio.h>
#include <string.h>

//Global arrays 
char timestamps[50][20];
long int secondsArray[50];

//Functions
void bubbleSortArray();
void timeStampsToSeconds();

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

	//Transform date and sort
	timeStampsToSeconds();
	bubbleSortArray();

	//Caculate 2016 start and end values
	long int yearStart = (16 * 12 * 30 * 24 * 60 * 60);
	long int yearEnd = 59 + (59 * 60) + (11 * 60 * 60) + (30 * 24 * 60 * 60) + (11 * 30 * 24 * 60 * 60) + (16 * 12 * 30 * 24 * 60 * 60);

	//Loop through array and find elements from 2015
	for (i = 0; i < 50; i++) {
		if (secondsArray[i] > yearStart && secondsArray[i] <= yearEnd) {
			printf("%ld\n", secondsArray[i]);
		}
		}

	//Output sorted data
	FILE* f = fopen(outfilename, "wb");

	for (i = 0; i < 50; i++) {
		fprintf(f, "%ld\n", secondsArray[i]);
	}
	fclose(f);

	return 0;

}

//Bubble sort 
void bubbleSortArray() {

	int pass, j;
	long int hold;

	for (pass = 0; pass < 50; pass++) {
		
		for (j = 0; j < 50 - 1; j++) {

			if (secondsArray[j] > secondsArray[j + 1]) {
				hold = secondsArray[j];
				secondsArray[j] = secondsArray[j + 1];
				secondsArray[j + 1] = hold;
			}
		}

	}

}

//Convert from string and calculate seconds from 01/01/2000
void timeStampsToSeconds() {

	//variables for converted ints and array for calculated seconds
	int day, mon, year, hours, minutes, seconds, i;
	long int secondsTotal = 0;

	//string arrays 
	char dd[3];
	char mm[3];
	char yyyy[5];
	char hh[3];
	char mins[3];
	char secs[3];

	//Loop through array, assign to variable, convert to int and cacluate seconds, assigning to new array
	for (i = 0; i < 50; i++) {

		sscanf(timestamps[i], "%2s/%2s/%4s-%2s:%2s:%2s", dd, mm, yyyy, hh, mins, secs);

		day = atoi(dd) - 1;
		mon = atoi(mm) - 1;
		year = atoi(yyyy) - 2000;
		hours = atoi(hh);
		minutes = atoi(mins);
		seconds = atoi(secs);

		secondsTotal = seconds + (minutes * 60) + (hours * 60 * 60) + (day * 24 * 60 * 60) + (mon * 30 * 24 * 60 * 60) + (year * 12 * 30 * 24 * 60 * 60);

		secondsArray[i] = secondsTotal;

		secondsTotal = 0;

	}



}