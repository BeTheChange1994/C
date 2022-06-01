#include <stdio.h>

int num_seconds(int hours, int minutes, int seconds);

int main(void) {

	int hh1, mm1, ss1, hh2, mm2, ss2;
	printf("Enter time in hh:mm:ss format >> ");
	scanf("%d:%d:%d", &hh1, &mm1, &ss1);
	printf("\nEnter time 2 in hh:mm:ss format >> ");
	scanf("%d:%d:%d", &hh2, &mm2, &ss2);
	printf("\nDifference is %d secs\n", num_seconds(hh1, mm1, ss1) - num_seconds(hh2, mm2, ss2) );

	return 0;
}

int num_seconds(int hh, int mm, int ss) {

	return ss + 60 * mm + 60 * 60 * hh;

}