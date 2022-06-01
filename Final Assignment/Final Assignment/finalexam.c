#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	char vaccine_vendor[20];
	char vaccinedDate[10];
	char dob[10];
	char condition[20];
	int id;
}VaccineRecord;

VaccineRecord tempRecord;

void load_data();



int main(void) {

	load_data();

	return 0;

}

void load_data() {

	//Checks for file and creats new if not found
	FILE* filePtr = fopen("records.txt", "r");
	if (filePtr != NULL) {
		printf("\nRecord file opened\n");
	}
	else {
		filePtr = fopen("records.txt", "w");
		if (filePtr != NULL) {
			printf("\nNew record file created\n");
		}
		else {
			printf("\nError, unable to create file\n");
			return;
		}
	}



	

}

