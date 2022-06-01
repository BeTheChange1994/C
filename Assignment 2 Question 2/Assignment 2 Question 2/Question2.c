#include <stdio.h>
#include "windspeeds.h"
#define SIZE 1440

int main(void) {

	//Initialise variables
	float max = windspeedsorted[SIZE - 1];
	float min = windspeedsorted[0];
	int i;

	float a[5] = {0};//array for partitions
	int count[5] = {0};//array for partition counts

	//Calculate the divisions
	a[0] = max / 5;
	a[1] = a[0] * 2;
	a[2] = a[0] * 3;
	a[3] = a[0] * 4;
	a[4] = max;

	for (i = 0; i < SIZE; i++) {//Loop array
		
		//Itterate through each partition to find commonality
		if (windspeedunsorted[i] < a[0] && windspeedunsorted[i] > 0) {
			count[0]++;
		}
		if (windspeedunsorted[i] < a[1] && windspeedunsorted[i] > a[0]) {
			count[1]++;
		}
		if (windspeedunsorted[i] < a[2] && windspeedunsorted[i] > a[1]) {
			count[2]++;
		}
		if (windspeedunsorted[i] < a[3] && windspeedunsorted[i] > a[2]) {
			count[3]++;
		}
		if (windspeedunsorted[i] <= a[4] && windspeedunsorted[i] > a[3]) {
			count[4]++;
		}

	}

	//Print results
	printf("The Maximum wind speed on that date was: %.4fm/s\n", max);
	printf("The Minimal wind speed on that date was: %.4fm/s\n", min);
	printf("The partition range is:\n0 - %.4f,  %.4f - %.4f,  %.4f - %.4f,  %.4f - %.4f,  %.4f - %.4f", a[0], a[0], a[1], a[1], a[2], a[2], a[3], a[3], a[4], a[4]);
	printf("\n\n");
	printf("Number of measurements between 0m/s and %.4fm/s is: %d\n", a[0], count[0]);
	printf("Number of measurements between %.4fm/s and %.4fm/s is: %d\n", a[0], a[1], count[1]);
	printf("Number of measurements between %.4fm/s and %.4fm/s is: %d\n", a[1], a[2], count[2]);
	printf("Number of measurements between %.4fm/s and %.4fm/s is: %d\n", a[2], a[3], count[3]);
	printf("Number of measurements between %.4fm/s and %.4fm/s is: %d\n", a[3], a[4], count[4]);


	return 0;
}