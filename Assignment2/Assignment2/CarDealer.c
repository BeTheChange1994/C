// To calculate a car salesperson's commission 

//import stdio library for scan tools
#include <stdio.h>

//main body fo the codestart here
int main(void) {

	//initialize variables and set to 0 where necessary
	int counter = 1;
	float sale = 0;
	float gross;
	float largest = 0;

	//I'll be using a whie loop, a do while could be used also
	//while condition set with counter variable
	while (counter <= 10) {

		//print opening message and take user input, set to sale variable
		printf("Please enter the sales of salesperson %d\n", counter);
		scanf("%f", &sale);

		//calculate the salesperson's gross pay
		gross = (sale / 100) * 7 + 300;

		//using an if statement to find the largest sale
		if (sale > largest) {
			
			largest = sale;
		}

		//prints off the salesperson's gross pay with every input
		printf("\nThe pay for salesperson %d is €%.2f\n", counter, gross);


		//increment counter
		++counter;

	} 

	//print largest sale after
	//tried the UTF-8 encoding for the euro symbol but still didnt show up correctly in the console
	printf("\nThe largest sale was \u20AC%.2f\n", largest);

	return 0;
}