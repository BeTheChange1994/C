//importing the math and stdio libraries
#include <stdio.h>
#include <math.h>

//function constructor
double hypotenuse(double side1, double side2);

int main(void) {

	//print each triangle and call function with two side length arguements 
	printf("The hypotenuse of triangle 1 is: %.2f\n", hypotenuse(3.0, 4.0) );
	printf("The hypotenuse of triangle 2 is: %.2f\n", hypotenuse(5.0, 12.0));
	printf("The hypotenuse of triangle 3 is: %.2f\n", hypotenuse(8.0, 15));

	return 0;

}

//The actual function
double hypotenuse(double side1, double side2) {

	//initialize x to take the two side values, square and add them
	double x = pow(side1, 2) + pow(side2, 2);

	//return the squared root of x
	return sqrt(x);

}