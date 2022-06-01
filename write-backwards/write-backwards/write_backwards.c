#include <stdio.h>
#define MAXSTRING 100

int main(void) {

	char filename[MAXSTRING];
	int c;
	FILE* ifp;

	printf("\nInput a filename: ");
	scanf("%s", filename);

	/*binary mode*/
	ifp = fopen(filename, "rb");
	if (ifp != NULL) {
		/*move to end of file, i.e. 0 bytes from end*/
		fseek(ifp, 0, 2);
		/*back one character from current postion*/
		fseek(ifp, -1, 1);

		while (ftell(ifp) >= 0) {

			/*read (and move forward) one character*/
			c = getc(ifp);
			/*display character to the screen*/
			putchar(c);
			/*move back two characters*/
			/*if cannot resposition pointer, at beginning of file*/
			if (fseek(ifp, -2, 1) != 0) {
				printf("\n");
				break;
			}
		}
	}

	fclose(ifp);

	return 0;
}