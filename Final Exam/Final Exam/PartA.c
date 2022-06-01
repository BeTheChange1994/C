#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

const char* const vendors_list[] = { "AstraZeneca", "Janssen", "Moderna", "Pfizer" };

enum VendorListIndex { ASTRAZENECA, JANSSEN, MODERNA, PFIZER } vendor;

typedef struct VaccineRecord {
	char name[20];
	char vaccine_vendor[20];
	char vaccinedDate[10];
	char dob[10];
	char condition[20];
	int id;
} vaccineRecord; // Global struct instance

vaccineRecord* existingRecords;

void load_data();
void display_menu();
//void add_new_record();
//void view_all_records();
//void modify_record();
//void sort_vaccinated_by_name();
//void sort_unvaccinated_by_name();
//void sort_vaccinated_by_date();
//void display_percentage_unvaccinated();
//void display_seniors_with_condition();
//void save_data();

int main(void) {

	load_data();

	return 0;
}

void load_data() {
	int lines = 0;
	//Tries to open file
	FILE* filePtr = fopen("records.txt", "r");
	if (filePtr != NULL) {
		printf("\nRecord file opened\n");
		char ch;
		while (!feof(filePtr)) {
			ch = fgetc(filePtr);
			if (ch == '\n' || ch == EOF) {
				lines++;
			}
		}
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
	//fclose(filePtr);
	if (lines < 1) lines = 1;

	existingRecords = malloc(sizeof(vaccineRecord) * lines);

	int fileEnd = 1, ii = 0;
	do {
		fileEnd = fscanf(filePtr, "%[^,]%s,%s,%s,%s,%d", existingRecords[ii].name, existingRecords[ii].vaccine_vendor, existingRecords[ii].vaccinedDate, existingRecords[ii].dob, existingRecords[ii].condition, &existingRecords[ii].id);
		ii++;
		if (fileEnd != EOF) {
			printf("\n%s\t%s\t%s\t%s\t%s\t%d\n", existingRecords[1].name, existingRecords[1].vaccine_vendor, existingRecords[1].vaccinedDate, existingRecords[1].dob, existingRecords[1].condition, existingRecords[1].id);
		}
	} while (fileEnd != EOF);

}

void display_menu() {
	printf("\n********************************************\n");
	printf("** Unspecified University Vaccine Tracker **\n");
	printf("********************************************\n\n");
	printf("1.\tAdd a new person\n");
	printf("2.\tView vaccination status for all students and staff\n");
	printf("3.\tModify existing record\n");
	printf("4.\tSort vaccinated people by name\n");
	printf("5.\tSort unvaccinated people by name\n");
	printf("6.\tSort vaccinated people by date\n");
	printf("7.\tDisplay percentage of unvaccinated\n");
	printf("8.\tDisplay a list of people with an underlying condition older than 65\n");
	printf("9.\tExit\n");

}
