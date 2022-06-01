/**
  Week 7 Assignment Question 1: week7_qn1.c

  Author: Wendy Neary
  Date: 9 January 2022
  Course: CT609 Fundamentals of Programming
  Workshop 7
  This program:
   1) Takes a series of timestamps in the format: "dd/mm/yyyy-hh:mm:ss"
   2) Sorts them chronologically using an alphanumeric bubble sort algorithm

  General file reading help from:
  https://stackoverflow.com/questions/8975369/reading-lines-out-of-a-file-and-putting-them-into-a-string-array/8975717

  Timestamp rearranging help from:
  https://nuigalway.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_134398_1&nav=group_forum&group_id=_57730_1&conf_id=_187839_1&forum_id=_78264_1&message_id=_533068_1

  Bubblesort help from:
  https://www.geeksforgeeks.org/sorting-strings-using-bubble-sort-2/
  
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 21  // size of each timestamp to read 
#define SIZE 50 // number of lines to read in file

// function prototypes
void bubblesortStrings(char arr[][BUF], int n);

// function main starts program execution
int main(void) {

    // INITIALIZATION

    char fileIn[50];                // file to read in, given by user
    char fileOut[50];               // file to output, given by user
    char tsArray[SIZE][BUF];        // timestamps array
    char tsChronArray[SIZE][BUF];   // sorted timestamps array

    FILE *fileInPtr = NULL; 
    FILE *fileOutPtr = NULL;
    
    size_t i = 0;           
    size_t j = 0;
    int total = 0;          // count # lines in array

    // PROCESSING

    // Prompt user for input file name first

	printf("%s", "Input the filename to be sorted:\n");
    printf("%s", "File name format: c:/mydirectory/filename.txt\n");
	scanf("%s", fileIn);	

    // Read strings from text file and store in string array

    if ( ( fileInPtr = fopen(fileIn, "r") ) == NULL ) {     

        // while file can't be opened -- keep prompting user
        do {
            printf("%s", "File could not be opened\n" );
            printf("%s", "Input the filename to be sorted:\n");
            printf("%s", "File name format: c:/mydirectory/filename.txt\n");
            scanf("%s", fileIn);            
        } while ( ( fileInPtr = fopen(fileIn, "r") ) == NULL ); 

    } 
    else {
        
        printf("%s", "File opened\n\n" );
        while( fgets(tsArray[i], BUF, fileInPtr )) {
            // get rid of ending \n from fgets 
            tsArray[i][strlen(tsArray[i]) - 1] = '\0';
            i++;
        }
        fclose( fileInPtr );
    }
    
    total = i;

    // rearrange the data to sort chronologically
    for ( j = 0; j < total; j++ ) {
       
        char day[3];        
        char mon[3];        
        char year[5];       
        char time[10];      

        // read in the fields from the timestamps
        sscanf( tsArray[j], "%2s/%2s/%4s-%8s", &day, &mon, &year, &time);
        // output into a new array, rearranged
        sprintf( tsChronArray[j], "%4s/%2s/%2s-%8s", year, mon, day, time );
    }

    // sort rearranged array with bubble sort

    bubblesortStrings( tsChronArray, SIZE );

    // prompt user for output file name and output

	printf("%s", "Input the filename to save the sorted data to:\n");
    printf("%s", "File name format: c:/mydirectory/filename.txt\n");
	scanf("%s", fileOut);

    if ((fileOutPtr = fopen( fileOut, "w" )) == NULL ) {
        // while file can't be opened -- keep prompting user
        do {
            printf("%s", "File could not be opened\n" );
            printf("%s", "Input the filename to save the sorted data to:\n");
            printf("%s", "File name format: c:/mydirectory/filename.txt\n");
            scanf("%s", fileOut);            
        } while ( ( fileOutPtr = fopen(fileOut, "w") ) == NULL ); 
    } else {
        for ( i = 0; i < total; i++ ) {
            fprintf( fileOutPtr, "%s\n", tsChronArray[i] );
        }
        
        fclose(fileOutPtr);

        printf("Sorted data saved to: %s\n", fileOut );
    }
    
    // TERMINATION

    return 0;
}

// https://www.geeksforgeeks.org/sorting-strings-using-bubble-sort-2/
void bubblesortStrings(char arr[][BUF], int n) {
    char temp[BUF];
  
    // Sorting strings using bubble sort
    for (int j = 0; j < n-1; j++)
    {
        for (int i = j+1; i < n; i++)
        {
            if (strcmp(arr[j], arr[i]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[i]);
                strcpy(arr[i], temp);
            }
        }
    }
}