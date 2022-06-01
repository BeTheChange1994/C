/* Program that reads teh radius of a circle from the user and calculates the diameter, circumference and area*/

#include <stdio.h>

int main(void) {

	float pie = 3.14159265;
	float radius;

	printf("Please enter the radius of the circle\n");
	scanf("%f", &radius);

	printf("The diameter of the circle is: %f\n", 2 * radius);
	printf("The cicumference of the circle is: %f\n", 2 * pie * radius);
	printf("The area of the circle is: %f\n", pie * (radius * radius) );

	return 0;

}