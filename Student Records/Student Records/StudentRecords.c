#include<stdio.h>
#include<string.h>

typedef struct {
	char name[10];
	char degree[10];
	int grade;
}Student;

Student tempStudent;//global struct instance

void prnMenu();
void showFile();
void addStudent();
void editStudent();
void editStudentNum(int num);

int main(void) {

	int menuItem;

	//check whether file exists
	FILE* filePtr = fopen("students.dat", "r");
	if (filePtr != NULL) {
		printf("\nStudent record file opened\n");
	}
	else {
		filePtr = fopen("students.dat", "w");
		if (filePtr != NULL) {
			printf("\nNew student record file created\n");
		}
		else {
			printf("\nUnable to create file! Goodbye!\n");
			return 1;
		}
	}
	fclose(filePtr);

	do {//titlescreen & menuu
		prnMenu();
		menuItem = 0;//reset to 0
		while (menuItem < 1 || menuItem > 4) {
			printf("\nChoose an option (1-4)");
			scanf("%d", &menuItem);
		}
		switch (menuItem) {
		case 1:
			showFile();
			break;
		case 2:
			addStudent();
			break;
		case 3:
			editStudent();
			break;
		default:
			break;
		}
	} while (menuItem != 4);
	printf("\n\nBye!\n\n");
	return 0;
}

void prnMenu() {
	printf("\n	--------------------------------------\n");
	printf("** Student Records Application **");
	printf("	------------------------------------\n\n");
	printf("1.Show students in file\n");
	printf("2. Add a new student\n");
	printf("3. Edit an Existing student\n");
	printf("4. Exit\n");
}

void showFile() {
	
	int count = 0, fileEnd = 0;
	FILE* filePtr = fopen("students.dat", "r");

	printf("\n%10s%10s%10s\n", "NAME", "DEGREE", "GRADE");
	do{
		fileEnd = fscanf(filePtr, "%s%s%d", tempStudent.name, tempStudent.degree, &tempStudent.grade);
		if (fileEnd != EOF) {
			printf("\n%10s%10s%10d", tempStudent.name, tempStudent.degree, tempStudent.grade);
			count++;
		}
	} while (fileEnd != EOF);
	fclose(filePtr);
	printf("\n\nTotal students in file: %d\n", count);
}

void addStudent() {

	FILE* filePtr = fopen("students.dat", "a+");

	strcpy(tempStudent.name, "<Name>");
	strcpy(tempStudent.degree, "<Degree>");
	tempStudent.grade = 0;

	fprintf(filePtr, "%s\n%s\n%d\n", tempStudent.name, tempStudent.degree, tempStudent.grade);
	fclose(filePtr);
}

void editStudent() {

	int fileEnd = 0, count = 0, toEdit;
	FILE* filePtr = fopen("students.dat", "r");
	do {
		fileEnd = fscanf(filePtr, "%s%s%d", tempStudent.name, tempStudent.degree, &tempStudent.grade);
		if (fileEnd != EOF) {
			count++;
		}
	} while (fileEnd != EOF);
	fclose(filePtr);

	if (count > 0){
		toEdit=0;
			while (toEdit<1 || toEdit>count) {
				printf("\nStudent n0. to edit? (1 - %d): ", count);
					scanf("%d", &toEdit);
			}
		editStudentNum(toEdit);
	}
	else {
		printf("\nNo students to edit");
	}
}

void editStudentNum(int num)
{
}

void editDtudentNum(int num) {

	int i, fileEnd = 0;
	char tempstring[50];

	FILE* filePtr = fopen("students.dat", "r");
	FILE* file2Ptr = fopen("temp.dat", "w");

	//copy across contents of file before student to edit
	for (i = 1; i < num; i++) {
		fscanf(filePtr, "%s%s%d", tempStudent.name, tempStudent.degree, &tempStudent.grade);
		fprintf(file2Ptr, "%s\n%s\n$d\n", tempStudent.name, tempStudent.degree, tempStudent.grade);
	}
	// get and display record to edit
	fscanf(filePtr, "%s%s%d", tempStudent.name, tempStudent.degree, &tempStudent.grade);
	printf("\nCurrent details in record %d:\n", num);
	printf("Name: %s\nDegree: %s\nGrade: %d\n", tempStudent.name, tempStudent.degree, tempStudent.grade);
	//promt for new name
	printf("\nPress Enter to keep any text detail unchanged");
	printf("\nName: ");
	gets(tempstring);//remove previous Enter from buffer
	gets(tempstring);//do the real input
	if (strlen(tempstring) > 0) {
		strcpy(tempStudent.name, tempstring);
	}
	//prompt for new degree
	printf("\nDegree: ");
	gets(tempstring);
	if (strlen(tempstring) > 0) {
		strcpy(tempStudent.degree, tempstring);
	}
	//prompt for new grade
	printf("\nGrade: ");
	scanf("$d", &tempStudent.grade);
	//write updated record
	fprintf(file2Ptr, "%s\n%s\n%d\n", tempStudent.name, tempStudent.degree, tempStudent.grade);
	//copyacross rest of file
	do {

		fileEnd - fscanf(filePtr, "%s%s%d", tempStudent.name, tempStudent.degree, &tempStudent.grade);
		if (fileEnd != EOF) {
			fprintf(file2Ptr, "%s\n%s\n%d\n", tempStudent.name, tempStudent.degree, tempStudent.grade);
		}
	} while (fileEnd != EOF);

	fclose(filePtr);
	fclose(file2Ptr);
	//delete old file
	remove("students.dat");
	//rename temp file
	rename("temp.dat", "students.dat");
}