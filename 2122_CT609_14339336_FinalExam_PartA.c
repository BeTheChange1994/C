/*CT609 - 14339336 - Week 8 Exam Part 1*/

/*
University tracker for covid vaccinations with the following actions

	
1. Add a new person
2. View vaccination status for all students and staff
3. Modify existing record
4. Sort vaccinated people by name
5. Sort unvaccinated people by name
6. Sort vaccinated people by date
7. Display percentage of unvaccinated people
8. Display a list of people with an underlying condition older than 65
9. Exit and save

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LINESIZE 100

struct Records
{
	char firstName[25]; 
	char secondName[25];
	char DOB[11];
	long int studentStaffNumber;
	char vaccineVendor[25];
	char vaccineDate[11];
	char conditions[50];
} *ptrRecords[1000]; //Array of pointers to struct Records

int arraySize = 0; //declare global variable array size to manage the number of records in the struct

//function prototypes
void load_data();
void display_menu();
int array_size();
void add_new_record();
void view_all_records();
void modify_record();
void sort_vaccinated_by_name();
void sort_unvaccinated_by_name();
void sort_vaccinated_by_date();
void display_percent_unvaccinated();
void display_seniors_with_condition();
void save_data();

//main function begins program execution
int main(void)
{
	int menuItem = 0; // stores selection made

	load_data(); // calls the load data function which loads the data from the file into the struct

	do
	{
		display_menu(); // calls function to display menu options
		menuItem = 0;

		while (menuItem < 1 || menuItem > 9) //numbers must be between 1 and 9
		{
			printf("\nChoose an option (1 to 9): ");
			scanf("%d", &menuItem);
		}
		switch (menuItem) //switch statement calls the function depending on number entered
		{
		case 1:
			add_new_record();
			break;
		case 2:
			view_all_records();
			break;
		case 3:
			modify_record();
			break;
		case 4:
			sort_vaccinated_by_name();
			break;
		case 5:
			sort_unvaccinated_by_name();
			break;
		case 6:
			sort_vaccinated_by_date();
			break;
		case 7:
			display_percent_unvaccinated();
			break;
		case 8:
			display_seniors_with_condition();
			break;
		default:
			break;
		}
	} while (menuItem != 9);

	save_data(); // calls function to write data to the file
	free(*ptrRecords); // free dynamic memory allocated
	return 0; //indicates successful execution
}

/*
The load data function checks whether the records.txt file exists.
If it does it loads the data in array of pointers to the records struct.
If the file isn't found it creates one for the user.
*/
void load_data()
{
	FILE* filePtr; //file pointer
	//local variables
	int fileEnd = 0;
	int i = 0;

	if ((filePtr = fopen("records.txt", "r")) != NULL) //checks if file is found
	{
		printf("Results file has been opened.\n");
		filePtr = fopen("records.txt", "r"); //opem file with read access

		do
		{
			ptrRecords[i] = (struct Records*)malloc(sizeof(struct Records)); //dynamically assingn memory for each element of the struct
			fileEnd = fscanf(filePtr, "%s %s %s %ld %s %s %s", ptrRecords[i]->firstName, ptrRecords[i]->secondName, ptrRecords[i]->DOB, &ptrRecords[i]->studentStaffNumber, ptrRecords[i]->vaccineVendor, ptrRecords[i]->vaccineDate, ptrRecords[i]->conditions);
			i++;

		} while (fileEnd != EOF); //while not the end of file
	}
	else
	{
		filePtr = fopen("records.txt", "w"); //open file with write access which creates the file for using
		printf("Results file was not found. An empty file has now been created.\n");
	}

	fclose(filePtr); //close the file

	arraySize = array_size(); //call the array size function to set the array size equal to the global array size variable
}

/*
This function displays the menu
*/
void display_menu()
{
	printf("\n------------------------------------------------------------------\n");
	printf("***                  University Vaccination Tracker              ***\n");
	printf("------------------------------------------------------------------\n\n");
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

/*
This function counts the number of elements in the array
*/

int array_size()
{
	int i;
	for (i = 0; ptrRecords[i] != NULL; i++); //loop through the array
	return i - 1; //return the count
}
/*
This function displays all the records to main screen
*/
void view_all_records()
{
	int i;

	printf("\n%-25s%-25s%-25s%-25s%-25s%-25s%-25s\n", "First Name", "Second Name", "DOB", "Student/Staff Number", "Vaccine Vendor", "Vaccine Date", "Conditions"); 

	for (i = 0; i < arraySize; i++) //loop through the array
	{
		//print the results neatly
		printf("%-25s%-25s%-25s%-25ld%-25s%-25s%-25s\n", ptrRecords[i]->firstName, ptrRecords[i]->secondName, ptrRecords[i]->DOB, ptrRecords[i]->studentStaffNumber, ptrRecords[i]->vaccineVendor, ptrRecords[i]->vaccineDate, ptrRecords[i]->conditions);
	}
}

/*
This function allows the user to enter a new records
*/ 
void add_new_record()
{
	//declare local variables which includes temporary storage for the data for the new record
	char tempfirstName[25];
	char tempsecondName[25];
	char tempDOB[11];
	long int tempstudentStaffNumber = 0;
	char tempvaccineVendor[25];
	char vaccineDate[11];
	char tempconditions[50];
	int i;

	printf("\n");

	//prompt user for data and save the result to the arrays declared above
	printf("Please enter a first name: ");
	scanf("%s", tempfirstName);
	printf("Please enter a second name: ");
	scanf("%s", tempsecondName);
	printf("Please enter a DOB in the format DD/MM/YYYY: ");
	scanf("%s", tempDOB);
	printf("Please enter an eight digit student/staff number: ");
	scanf("%ld", &tempstudentStaffNumber);
	printf("Please enter a vaccine vendor (Enter 'none' if unvaccinated): ");
	scanf("%s", tempvaccineVendor);
	printf("Please enter the vaccine date in the format DD/MM/YYYY (Enter 'none' if unvaccinated): ");
	scanf("%s", vaccineDate);
	printf("Please enter any medical condition: ");
	scanf("%s", tempconditions);

	ptrRecords[arraySize] = (struct Records*)malloc(sizeof(struct Records)); //assign memory for the new record
	//copy the input to the struct in the array size number which is the next number in the array
	strcpy(ptrRecords[arraySize]->firstName, tempfirstName);
	strcpy(ptrRecords[arraySize]->secondName, tempsecondName);
	strcpy(ptrRecords[arraySize]->DOB, tempDOB);
	ptrRecords[arraySize]->studentStaffNumber = tempstudentStaffNumber;
	strcpy(ptrRecords[arraySize]->vaccineVendor, tempvaccineVendor);
	strcpy(ptrRecords[arraySize]->vaccineDate, vaccineDate);
	strcpy(ptrRecords[arraySize]->conditions, tempconditions);

	arraySize += 1; //increment the arraysize variable

	//print the new record details
	printf("\nNew record:\n");
	printf("%-25s%-25s%-25s%-25s%-25s%-25s%-25s\n", "First Name", "Second Name", "DOB", "Student/Staff Number", "Vaccine Vendor", "Vaccine Date", "Conditions");
	printf("%-25s%-25s%-25s%-25ld%-25s%-25s%-25s\n", tempfirstName, tempsecondName, tempDOB, tempstudentStaffNumber, tempvaccineVendor, vaccineDate, tempconditions);
}

/*
This function allows the user to enter an ID and if it is found you can edit the details of that record
*/
void modify_record()
{
	//declare local variables
	int toEdit = 0;
	long int tempIDArray[9];
	int i;
	int IDfound = 0;
	int recordNumber = 0;
	char tempfirstName[25];
	char tempsecondName[25];
	char tempDOB[11];
	long int tempstudentStaffNumber = 0;
	char tempvaccineVendor[25];
	char vaccineDate[11];
	char tempconditions[50];

	for (i = 0; i < arraySize; i++) // loop through the array
	{
		tempIDArray[i] = ptrRecords[i]->studentStaffNumber; //save the student number to a local array created in this function
	}

	if (arraySize > 0) //catches whether there is any records existing in the first place
	{
		printf("\nEnter the student/staff ID of the record you would like to update: "); //enter ID
		scanf("%d", &toEdit);

		i = 0;

		do
			{
			if (toEdit == tempIDArray[i]) // check if the entered ID matches any existing ID
			{
				IDfound = 1; //sets this variable to 1 which is used further on to show whether the entered ID matches one in the array
				recordNumber = i; //says which number in the struct the match was
			}

			i++;
		} while (i < arraySize);

		if (IDfound == 1) // if the ID was found
		{
			//print the details
			printf("\nDetails found:\n");
			printf("%-25s%-25s%-25s%-25s%-25s%-25s%-25s\n", "First Name", "Second Name", "DOB", "Student/Staff Number", "Vaccine Vendor", "Vaccine Date", "Conditions");
			printf("%-25s%-25s%-25s%-25ld%-25s%-25s%-25s\n\n", ptrRecords[recordNumber]->firstName, ptrRecords[recordNumber]->secondName, ptrRecords[recordNumber]->DOB, ptrRecords[recordNumber]->studentStaffNumber, ptrRecords[recordNumber]->vaccineVendor, ptrRecords[recordNumber]->vaccineDate, ptrRecords[recordNumber]->conditions);

			//Prompt the user to enter the modified details and save them in the locally created array
			printf("Please enter a first name: ");
			scanf("%s", tempfirstName);
			printf("Please enter a second name: ");
			scanf("%s", tempsecondName);
			printf("Please enter a DOB in the format DD/MM/YYYY: ");
			scanf("%s", tempDOB);
			printf("Please enter an eight digit student/staff number: ");
			scanf("%ld", &tempstudentStaffNumber);
			printf("Please enter a vaccine vendor (Enter 'none' if unvaccinated): ");
			scanf("%s", tempvaccineVendor);
			printf("Please enter the  vaccine date in the format DD/MM/YYYY (Enter 'none' if unvaccinated): ");
			scanf("%s", vaccineDate);
			printf("Please enter any medical condition: ");
			scanf("%s", tempconditions);

			//print the updated details
			printf("\nUpdated details:\n");
			printf("%-25s%-25s%-25s%-25s%-25s%-25s%-25s\n", "First Name", "Second Name", "DOB", "Student/Staff Number", "Vaccine Vendor", "Vaccine Date", "Conditions");
			printf("%-25s%-25s%-25s%-25ld%-25s%-25s%-25s\n", tempfirstName, tempsecondName, tempDOB, tempstudentStaffNumber, tempvaccineVendor, vaccineDate, tempconditions);

			//copy the inputted details into the array of structs
			strcpy(ptrRecords[recordNumber]->firstName, tempfirstName);
			strcpy(ptrRecords[recordNumber]->secondName, tempsecondName);
			strcpy(ptrRecords[recordNumber]->DOB, tempDOB);
			ptrRecords[recordNumber]->studentStaffNumber = tempstudentStaffNumber;
			strcpy(ptrRecords[recordNumber]->vaccineVendor, tempvaccineVendor);
			strcpy(ptrRecords[recordNumber]->vaccineDate, vaccineDate);
			strcpy(ptrRecords[recordNumber]->conditions, tempconditions);
		}
		else //if the ID entered doesn't match any ID in the array
		{
			printf("\nThere are currently no records on file with that ID. Press 3 and try again.");
		}
	}
	else //if there are no records on file
	{
		printf("\nThere are currently no records on file. Press 1 to add one.");
	}
}

/*
This function orders the names of vaccinated individuals by last name and prints the names in the format LastNameFirstName since it sorted by last name.
If the vaccine date says 'none' this means they have not been vaccinated.
*/ 
void sort_vaccinated_by_name()
{
	//declare local variables plus arrays
	char tempNameArray[1000][52];
	int pass;
	int i;
	int numberVaccinated = 0;
	char hold[52];
	int result;
	char unvaccinatedArray[] = { "none" };

	for (i = 0; i < arraySize; i++) //loop through the array
	{
		result = strcmp(ptrRecords[i]->vaccineDate, unvaccinatedArray); //compare if the vaccine date is none or not and save the integer result to the result variable

		if (result != 0) // if the result is not 0 which means the date is not none and therefore they have been vaccinated
		{
			//save the first and second name of those who are vaccinated in the format lastnamefirstname so the record can be sorted accurately
			strcpy(tempNameArray[numberVaccinated], ptrRecords[i]->secondName);
			strcat(tempNameArray[numberVaccinated], ptrRecords[i]->firstName);
			numberVaccinated += 1;
		}
	}

	if (arraySize > 0) //checks to make sure there is records in the array in the first place
	{
		if (numberVaccinated == 0) //this is a check to catch is no record is a vaccinated person
		{
			printf("\nThere are currently no vaccinated records.");
		}
		else
		{
			//bubble sort
			for (pass = 1; pass < numberVaccinated; pass++) 
			{
				for (i = 0; i < numberVaccinated - pass; i++) 
				{
					if (strcmp(tempNameArray[i], tempNameArray[i + 1]) > 0) 
					{
						strcpy(hold, tempNameArray[i]);     
						strcpy(tempNameArray[i], tempNameArray[i + 1]); 
						strcpy(tempNameArray[i + 1], hold); 
					} 
				} 
			} 
		}

		printf("\nVaccinated:\n");

		//print those who are vaccinated
		for (i = 0; i < numberVaccinated; i++)
		{
			printf("%s\n", tempNameArray[i]);
		}
	}
	else //if there are no records
	{
		printf("\nThere are currently no records on file. Press 1 to add one.");
	}
}

/*
This function orders the names of vaccinated individuals by last name and prints the names in the format LastNameFirstName since it sorted by last name.
If the vaccine date says 'none' this means they have not been vaccinated. This is the same function as above with the only difference being it looks where the vaccine date matches none.
For simplicity months have been set to 30 days so number of day in a year = 30*12.
*/
void sort_unvaccinated_by_name()
{
	char tempNameArray[1000][52];
	int pass;
	int i;
	int numberUnvaccinated = 0;
	char hold[52];
	int result;
	char unvaccinatedArray[] = { "none" };

	for (i = 0; i < arraySize; i++)
	{
		result = strcmp(ptrRecords[i]->vaccineDate, unvaccinatedArray);

		if (result == 0)
		{
			strcpy(tempNameArray[numberUnvaccinated], ptrRecords[i]->secondName);
			strcat(tempNameArray[numberUnvaccinated], ptrRecords[i]->firstName);
			numberUnvaccinated += 1;
		}
	}
	if (arraySize > 0)
	{
		if (numberUnvaccinated == 0)
		{
			printf("\nThere are currently no unvaccinated records.");
		}
		else
		{
			for (pass = 1; pass < numberUnvaccinated; pass++) 
			{
				for (i = 0; i < numberUnvaccinated - pass; i++) 
				{
					if (strcmp(tempNameArray[i], tempNameArray[i + 1]) > 0) 
					{
						strcpy(hold, tempNameArray[i]);     
						strcpy(tempNameArray[i], tempNameArray[i + 1]); 
						strcpy(tempNameArray[i + 1], hold); 
					} 
				} 
			} 
		}

		printf("\nUnvaccinated:\n");

		for (i = 0; i < numberUnvaccinated; i++)
		{
			printf("%s\n", tempNameArray[i]);
		}
	}
	else
	{
		printf("\nThere are currently no records on file. Press 1 to add one.");
	}
}

/*
*This function takes everyone who is vaccinated and sorts them by their vaccinated date. Dates are converted to days. 
For simplicity rather than calculating days since today it has been manually set to calculate since the start of 2022.
This was down to time constrints building this program.
For simplicity months have been set to 30 days so number of day in a year = 30*12.
*/ 
void sort_vaccinated_by_date()
{
	//declare all local variables and array
	int day;
	int month;
	int year;
	char stringday[3];
	char stringmonth[3];
	char stringyear[5];
	char converteddate[11];
	int i;
	int numberOfDays[1000];
	int primaryKey[100];
	int result;
	char unvaccinatedArray[] = { "none" };
	int count = 0;
	int pass;
	int hold;
	int hold2;

	for (i = 0; i < arraySize; i++) //loop through the array
	{
		result = strcmp(ptrRecords[i]->vaccineDate, unvaccinatedArray); //check if the vaccine date matches none

		if (result != 0) // if they are vaccinated
		{
			//breaks the string up into separate parts and into integers
			day = atoi(ptrRecords[i]->vaccineDate);
			month = atoi(ptrRecords[i]->vaccineDate + 3);
			year = atoi(ptrRecords[i]->vaccineDate + 6) - 2022;

			numberOfDays[count] = (day + (month * 30) + (year * 12 * 30)) * -1; //calculate number of days 
			primaryKey[count] = i; //this is a primary key of arrays that will be used for the printing the data of those vaccinated later on in the function

			count++;
		}
	}

	printf("\n");

	//bubble sort
	for (pass = 1; pass < count; pass++) //loop for number of passes
	{
		for (i = 0; i < count - pass; i++) //loop for comparisons of i and i+1
		{
			if (numberOfDays[i] > numberOfDays[i + 1]) //compare if i is greater than i+1
			{
				hold = primaryKey[i];
				primaryKey[i] = primaryKey[i + 1];
				primaryKey[i + 1] = hold;
				hold2 = numberOfDays[i];
				numberOfDays[i] = numberOfDays[i + 1];
				numberOfDays[i + 1] = hold2;
			}
		}
	}
	//loop through the vaccinated records
	for (i = 0; i < count; i++)
	{
		//parse the dates out so they can be reformatted
		day = atoi(ptrRecords[primaryKey[i]]->vaccineDate); 
		month = atoi(ptrRecords[primaryKey[i]]->vaccineDate + 3);
		year = atoi(ptrRecords[primaryKey[i]]->vaccineDate + 6);

		//change the integers to a string and concatenate them togeteher in the desired format
		sprintf(stringday, "%d", day);
		sprintf(stringmonth, "%d", month);
		sprintf(stringyear, "%d", year);
		strcpy(converteddate, stringyear);
		strcat(converteddate, "/");
		strcat(converteddate, stringmonth);
		strcat(converteddate, "/");
		strcat(converteddate, stringday);

		printf("%-25s%-25s%-25s\n", ptrRecords[primaryKey[i]]->firstName, ptrRecords[primaryKey[i]]->secondName, converteddate); //print the ordered vaccinated records
	}
}

/*
This function displays the percentage of people unvaccinated
Calculation: unvacinated/total number of records
*/
void display_percent_unvaccinated()
{
	//declare local variables
	int unVaccinated = 0;
	int i;
	int result;
	char unvaccinatedArray[] = { "none" };
	float percentUnvaccinated = 0;

	printf("\n");

	//check if the records has been vaccinated
	for (i = 0; i < arraySize; i++)
	{
		result = strcmp(ptrRecords[i]->vaccineDate, unvaccinatedArray);

		if (result == 0)
		{
			unVaccinated += 1; //counts number unvaccinated
		}
	}

	printf("Unvacinated: %d\n", unVaccinated);
	printf("Total on record: %d\n", arraySize);

	percentUnvaccinated = ((float)unVaccinated / (float)arraySize) * 100; //calculates the percentage unvaccinated

	printf("Percent vaccinated: %.2f%%\n", percentUnvaccinated); //print the result
}

/*
This function displays the names of the records who are over 65 with a medical condition.
Someone has a medical condition if the result doesn't equal none. 
These are then ordered by age from oldest to youngest.
For simplicity months have been set to 30 days so number of day in a year = 30*12.
*/
void display_seniors_with_condition()
{
	//declare local variables
	int day;
	int month;
	int year;
	int numberOfDays;
	int i;
	int count = 0;
	int result;
	char healthCondition[] = { "none" };

	printf("\n");

	printf("Records for those over 65 with medical conditions:\n");
	printf("%-25s%-25s%-25s\n", "First Name", "Second Name", "Conditions");

	//loop through the array in order to parse out the integers from the date string
	for (i = 0; i < arraySize; i++)
	{

		day = atoi(ptrRecords[i]->DOB);
		month = atoi(ptrRecords[i]->DOB + 3);
		year = atoi(ptrRecords[i]->DOB + 6) - 2022;

		numberOfDays = (day + (month * 30) + (year * 12 * 30)) * -1; //calculate age

		result = strcmp(ptrRecords[i]->conditions, healthCondition); //check if condition is equal to none
		

		if (numberOfDays >= 23741 && result != 0) //check if the person is over 65 and the condition wasn't 'none'
		{
			//print those individuals
			printf("%-25s%-25s%-25s\n", ptrRecords[i]->firstName, ptrRecords[i]->secondName, ptrRecords[i]->conditions);
		}
	}
}

/*
This function saves the array at the time to the records file. 
It is called right before the program finishes executing.
*/
void save_data()
{
	FILE* filePtr;
	int i;
	char outputFile[100];

	filePtr = fopen("records.txt", "w"); //open file with writeaccess

	//loop through the array
	for (i = 0; i < arraySize - 1; i++)
	{
		//print array to the file for array size - 1 with a carriage return
		fprintf(filePtr, "%s %s %s %ld %s %s %s\n", ptrRecords[i]->firstName, ptrRecords[i]->secondName, ptrRecords[i]->DOB, ptrRecords[i]->studentStaffNumber, ptrRecords[i]->vaccineVendor, ptrRecords[i]->vaccineDate, ptrRecords[i]->conditions);
	}

	//print the last record with no carriage return
	fprintf(filePtr, "%s %s %s %ld %s %s %s\n", ptrRecords[i]->firstName, ptrRecords[i]->secondName, ptrRecords[i]->DOB, ptrRecords[i]->studentStaffNumber, ptrRecords[i]->vaccineVendor, ptrRecords[i]->vaccineDate, ptrRecords[i]->conditions);

	fclose(filePtr); //close file
}

