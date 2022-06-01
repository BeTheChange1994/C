#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	//char vaccine_status[3];
	char vaccine_vendor[20];
	char vaccinedDate[10];
	char dob[10];
	char condition[20];
	int id;
}VaccineRecord;

//Global Variables
VaccineRecord *ptrArray[1500];
int countRecords = 0;

//Function Prototypes
void load_data();
void display_menu();
void add_record();
void view_records();
void modify_records();
void sort_vaccinated_by_name();
void sort_unvaccinated_by_name();


int main(void) {

	int menuSelection = 0;

	load_data();

	do {

		display_menu();
		menuSelection = 0;

		while (menuSelection < 1 || menuSelection > 9) {
			printf("\nPlease choose a number between option 1 - 9\n");
			scanf("%d", &menuSelection);
		}
		switch(menuSelection) {

		case 1:
			printf("\n\n");
			add_record();
			break;
		case 2:
			printf("\n\n");
			view_records();
			break;
		case 3:
			printf("\n\n");
			modify_records();
			break;
		case 4:
			printf("\n\n");
			sort_vaccinated_by_name();
			break;
		case 5:
			printf("\n\n");
			sort_unvaccinated_by_name();
			break;
		case 6:
			printf("success");
			break;
		case 7:
			printf("success");
			break;
		case 8:
			printf("success");
			break;
		default:
			break;
		
		}

	} while (menuSelection != 9);

	return 0;

}

void load_data() {

	//local variables
	int endOfFile = 0;
	int i = 0;

	//Checks for file and creats new if not found
	FILE* filePtr = fopen("records.txt", "r");

	if (filePtr != NULL) {

		printf("\nRecord file opened\n");

		while (endOfFile != EOF) {

			ptrArray[i] = (VaccineRecord*)malloc(sizeof(VaccineRecord));
			endOfFile = fscanf(filePtr, "%s %s %s %s %s %d", ptrArray[i]->name, /*ptrArray[i]->vaccine_status,*/ ptrArray[i]->vaccine_vendor, ptrArray[i]->vaccinedDate, ptrArray[i]->dob, ptrArray[i]->condition, ptrArray[i]->id);

			countRecords++;
			i++;
		}

		countRecords = countRecords - 1;

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
	fclose(filePtr);

}

void display_menu() {
	printf("\n*---------------------------------------------------------------*\n");
	printf("      ***               Vaccine Tracker               ***\n");
	printf("*---------------------------------------------------------------*\n\n");
	printf("1. Add a new person\n");
	printf("2. View vaccination status for all students and staff\n");
	printf("3. Modify existing record\n");
	printf("4. Sort vaccinated people by name\n");
	printf("5. Sort unvaccinated people by name\n");
	printf("6. Sort vaccinated people by date\n");
	printf("7. Display percentage of unvaccinated people\n");
	printf("8. Display a list of people with an underlying condition older than 65\n");
	printf("9. Exit \n");
}

void add_record() {

	char inputName[128];
	//char inputVaccine_status[3] = NULL;
	char inputVaccine_vendor[128];
	char inputVaccineDate[128];
	char inputDob[128];
	char inputCondition[128];
	int inputId;

	printf("Please enter name (Last_first): ");
	scanf("%s", inputName);

	/*
	while (inputVaccine_status != "Y" || inputVaccine_status != "y" || inputVaccine_status != "N" || inputVaccine_status != "n"){

		printf("Is this person vaccinated? (Y/N)");
		scanf("%s", inputVaccine_status);

		if (inputVaccine_status == "Y" || inputVaccine_status == "y") {
			printf("Please enter Vaccine Vendor: ");
			scanf("%s", inputVaccine_vendor);
			printf("Please enter Vaccine date: ");
			scanf("%ld", inputVaccineDate);
		}
		if (inputVaccine_status == "N" || inputVaccine_status == "n") {
			inputVaccine_vendor[128] = "None";
			inputVaccineDate[128] = "None";
		}
		else {
			printf("Error, Please enter values: (Y/N)");
		}
	}

	printf("%s", inputVaccine_status);
	printf("%s", inputVaccine_vendor);
	*/

	printf("Please enter Vaccine Vendor (Enter None if not vaccinated): ");
	scanf("%s", inputVaccine_vendor);
	printf("Please enter Vaccine date (Enter None if not vaccinated): ");
	scanf("%s", inputVaccineDate);
	printf("Please enter date of birth: ");
	scanf("%s", inputDob);
	printf("Please enter any existing conditions: ");
	scanf("%s", inputCondition);
	printf("Please enter student/staff ID: ");
	scanf("%d", &inputId);

	//Assign memory to the new record
	ptrArray[countRecords] = (VaccineRecord*)malloc(sizeof(VaccineRecord));

	//Add the new record to the array
	strcpy(ptrArray[countRecords]->name, inputName);
	strcpy(ptrArray[countRecords]->vaccine_vendor, inputVaccine_vendor);
	strcpy(ptrArray[countRecords]->vaccinedDate, inputVaccineDate);
	strcpy(ptrArray[countRecords]->dob, inputDob);
	strcpy(ptrArray[countRecords]->condition, inputCondition);
	ptrArray[countRecords]->id = inputId;

	//Print out success and new record
	printf("\nNew record added\n\n");
	printf("------------------------------------------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------------------------------------------\n");
	printf("%-20s%-20s%-20s%-20s%-20s%-20s\n", "Name", "Vaccine Vendor", "Vaccine Date", "Date of birth", "Condition", "ID");
	printf("%-20s%-20s%-20s%-20s%-20s%-20d\n", ptrArray[countRecords]->name, ptrArray[countRecords]->vaccine_vendor, ptrArray[countRecords]->vaccinedDate, ptrArray[countRecords]->dob, ptrArray[countRecords]->condition, ptrArray[countRecords]->id);
	printf("------------------------------------------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------------------------------------------\n\n");

	//Increment Count for new record
	countRecords = countRecords + 1;
}

void view_records() {

	printf("%-20s%-20s%-20s%-20s%-20s%-20s\n", "Name", "Vaccine Vendor", "Vaccine Date", "Date of birth", "Condition", "ID");
	printf("------------------------------------------------------------------------------------------------------------\n\n");
	
	for (int i = 0; i < countRecords; i++) {
		printf("%-20s%-20s%-20s%-20s%-20s%-20d\n", ptrArray[i]->name, ptrArray[i]->vaccine_vendor, ptrArray[i]->vaccinedDate, ptrArray[i]->dob, ptrArray[i]->condition, ptrArray[i]->id);
		printf("\n");
	}
	printf("------------------------------------------------------------------------------------------------------------\n\n");
}

void modify_records() {

	int modifyRecord;

	if (countRecords == 0) {
		
		printf("\nThere are no records to modify\n");
	}
	else {

		printf("\nPlease enter an ID to modify: \n");
		scanf("%d", &modifyRecord);

		for (int i = 0; i < countRecords; i++) {

			if (ptrArray[i]->id == modifyRecord) {

				printf("\nRecord found!\n");
				printf("%-20s%-20s%-20s%-20s%-20s%-20s\n", "Name", "Vaccine Vendor", "Vaccine Date", "Date of birth", "Condition", "ID");
				printf("%-20s%-20s%-20s%-20s%-20s%-20d\n", ptrArray[i]->name, ptrArray[i]->vaccine_vendor, ptrArray[i]->vaccinedDate, ptrArray[i]->dob, ptrArray[i]->condition, ptrArray[i]->id);

				printf("\nPlease enter the new information for the record: \n");

				printf("Please enter name (Last name first): ");
				scanf("%s", ptrArray[i]->name);
				printf("Please enter Vaccine Vendor (Enter None if not vaccinated): ");
				scanf("%s", ptrArray[i]->vaccine_vendor);
				printf("Please enter Vaccine date (Enter None if not vaccinated): ");
				scanf("%s", ptrArray[i]->vaccinedDate);
				printf("Please enter date of birth: ");
				scanf("%s", ptrArray[i]->dob);
				printf("Please enter any existing conditions: ");
				scanf("%s", ptrArray[i]->condition);
				printf("Please enter student/staff ID: ");
				scanf("%d", &ptrArray[i]->id);

				printf("\nThe record has been updated!\n");

			}
			if (ptrArray[i]->id != modifyRecord) {

			}
			else {
				printf("\nRecord Not found!\n");
			}

		}

	}
}

void sort_vaccinated_by_name() {

	//int recordLocation[1500];
	//int recordLocationLocation = 0;
	char tempArray[1500][128];
	char None[] = { "None" };
	char none[] = { "none" };
	int test1;
	int test2;
	int j = 0;
	int pass;
	char hold[128];

	for (int i = 0; i < countRecords; i++) {

		test1 = strcmp(ptrArray[i]->vaccine_vendor, None);
		test2 = strcmp(ptrArray[i]->vaccine_vendor, none);

		if ( test1 + test2 == 0) {

			//printf("success");

			//recordLocation[recordLocationLocation] = i;

			//recordLocationLocation++;

			strcpy(tempArray[j], ptrArray[i]->name);

			j++;
		}

	}

	/*
	for (int i = 0; i < recordLocationLocation; i++) {
		printf("%d", recordLocation[i]);
	}
	*/

	//bubble sort
	for (pass = 1; pass < j; pass++) {

		for (int i = 0; i < j - pass; i++) {

			if (strcmp(tempArray[i], tempArray[i + 1]) > 0) {

				strcpy(hold, tempArray[i]);
				strcpy(tempArray[i], tempArray[i + 1]);
				strcpy(tempArray[i + 1], hold);

			}
		}
	}

	printf("\nVaccinated Ordered by name: \n");

	for (int i = 0; i < j; i++) {
		printf("\n%s", tempArray[i]);
	}
}

void sort_unvaccinated_by_name() {

	char tempArray[1500][128];
	char None[] = { "None" };
	char none[] = { "none" };
	int test1;
	int test2;
	int j = 0;
	int pass;
	char hold[128];

	for (int i = 0; i < countRecords; i++) {

		test1 = strcmp(ptrArray[i]->vaccine_vendor, None);
		test2 = strcmp(ptrArray[i]->vaccine_vendor, none);

		if (test1 + test2 != 0) {
			strcpy(tempArray[j], ptrArray[i]->name);

			j++;
		}

	}

	//bubble sort
	for (pass = 1; pass < j; pass++) {

		for (int i = 0; i < j - pass; i++) {

			if (strcmp(tempArray[i], tempArray[i + 1]) > 0) {

				strcpy(hold, tempArray[i]);
				strcpy(tempArray[i], tempArray[i + 1]);
				strcpy(tempArray[i + 1], hold);

			}
		}
	}

	printf("\nVaccinated Ordered by name: \n");

	for (int i = 0; i < j; i++) {
		printf("\n%s", tempArray[i]);
	}
}