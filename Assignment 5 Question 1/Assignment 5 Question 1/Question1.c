//Import libraries
#include <stdio.h>
#include <time.h>
#include "windspeed.h"//This imports the Header file with the two unsorted arrays
#define SIZE 1440

//Declare the two sorting algorithm functions
void bubbleSort(float a[]);
void selectionSort(float a[]);

int main(void) {

	//Initialise variables
	int i;

	//Print unsorted array
	printf("Here is the unsorted array:\n");
	for (i = 0; i < SIZE; i++) {

		if (i % 15 == 0) {//Formats the output for new line every 15 numbers
			printf("\n");
		}
			
		printf("%.4f  ", windspeeds1[i]);

	}

	printf("\n");

	///Bubble Sort

	printf("\n\nHere is the Bubble Sorted array:\n");
	clock_t bubbleBegin = clock();//Tag clock function before running sort
	bubbleSort(windspeeds1);//Calling Bubble function with unsorted array
	for (i = 0; i < SIZE; i++) {

		if (i % 15 == 0) {//Formats output
			printf("\n");
		}

		printf("%.4f  ", windspeeds1[i]);//Print the sorted array

	}
	clock_t bubbleEnd = clock();//Tag clock after sort
	double bubbletime = (double)(bubbleBegin - bubbleEnd) / CLOCKS_PER_SEC;//Deducting program run time and parsing to double

	printf("\n\n");


	//Select Sort

	printf("\n\nHere is the Select Sorted array:\n");
	clock_t selectBegin = clock();//Tag clock
	selectionSort(windspeeds2);//Calling Select function with second unsorted array
	for (i = 0; i < SIZE; i++) {

		if (i % 15 == 0) {//Formatting
			printf("\n");
		}
		
		printf("%.4f  ", windspeeds2[i]);//Print sorted array

	}
	clock_t selectEnd = clock();//Tag clock
	double selecttime = (double)(selectBegin - selectEnd) / CLOCKS_PER_SEC;//Deducting program run time and parsing to double

	printf("\n\n");

	printf("Bubble Sort finished in: %.3f Seconds\n", bubbletime);//Print run time Bubble Sort
	printf("Selection Sort finished in: %.3f Seconds\n", selecttime);//Print run time Selection Sort

	return 0;

}

void bubbleSort(float a[]) {

	//Initialise Variables
	int pass, j, comps = 0, swaps = 0;
	float hold;

	for (pass = 1; pass < SIZE; pass++) {//Loop array

		for (j = 0; j < SIZE - 1; j++) {//Loop for each element

			comps++;//Count comparisions
			if (a[j] > a[j + 1]) {//checks to see if it is less then next element, then swaps
				swaps++;//count swaps
				hold = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hold;
			}

		}
	}

	printf("\nThe Bubble Sort Algorithm did %d comparisons and %d swaps\n", comps, swaps);

}

void selectionSort(float a[]) {

	//Initialise variables
	int i, j, position, comps = 0, swaps = 0;
	float hold;

	for (i = 0; i < SIZE - 1; i++) {//loop array

		position = i;
		
		for (j = i + 1; j < SIZE; j++) {//loop for each element

			comps++;//count comparisons
			if (a[position] > a[j]) {
				position = j;
			}
		}
		if (position != i) {//
			swaps++;//count swaps
			hold = a[i];
			a[i] = a[position];
			a[position] = hold;
		}
	}

	printf("\nThe Selection Sort Algorithm did %d comparisons and %d swaps\n", comps, swaps);

}