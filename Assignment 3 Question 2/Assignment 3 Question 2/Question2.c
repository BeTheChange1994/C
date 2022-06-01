//program to take in 5 numbers and print * accordingly 

#include <stdio.h>

int main(){

    //initialize variables
    int i, x;
    int input;
    int num1, num2, num3, num4, num5;

    //opening statement
    printf("Please enter 5 numbers between 1 and 30\n");

    //for loop to take 5 numbers
    for (i = 1; i <= 5; i++) {

        //scan in input
        scanf("%d", &input);

        //catch number outside 1 to 30 and decrement loop back
        if (input < 1 || input > 30) {

            printf("Please enter antoter number\n");

            i--;
        }

        //else to prevent the rest from executing when If catches error input
        //switch statement to set variable values to user input
        else {

            switch (i) {

            case 1:
                num1 = input;
                break;

            case 2:
                num2 = input;
                break;

            case 3:
                num3 = input;
                break;

            case 4:
                num4 = input;
                break;

            case 5:
                num5 = input;
                break;

            }
        }   

            //code from original coding

            /*              for (x = 1; x <= input; ++x) {

                               printf("* ");
                           }
           */
            
            //spacing
            printf("\n");

    }

    //These for loops will print each input's *
    for (x = 1; x <= num1; ++x) {

        printf("* ");
     }

    printf("\n");

    for (x = 1; x <= num2; ++x) {

        printf("* ");
    }

    printf("\n");

    for (x = 1; x <= num3; ++x) {

        printf("* ");
    }

    printf("\n");

    for (x = 1; x <= num4; ++x) {

        printf("* ");
    }

    printf("\n");

    for (x = 1; x <= num5; ++x) {

        printf("* ");
    }

    //program ends
    return 0;

}