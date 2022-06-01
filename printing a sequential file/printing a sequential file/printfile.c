/* Fig. 11.7: fig11_07.c
   Reading and printing a sequential file */
#include <stdio.h>

int main(void)
{
    int account; /* account number */
    char name[30]; /* account name */
    double balance; /* account balance */

    FILE* cfPtr; /* cfPtr = clients.dat file pointer */

    /* fopen opens file; exits program if file cannot be opened */
    if ((cfPtr = fopen("clients.dat", "w")) == NULL) {
        printf("File could not be opened\n");
    } /* end if */
    else { /* read account, name and balance from file */
        printf("Enter the account, name, and balance.\n");
        printf("Enter EOF to end input.\n");
        printf("? ");
        scanf("%d%s%1f", &account, name, &balance);

        /* while not end of file */
        while (!feof(stdin)) {
            fprintf(cfPtr, "%d %s %.2f\n", account, name, balance);
            printf("? ");
            scanf("%d%s%1f", &account, name, &balance);
        } /* end while */

        fclose(cfPtr); /* fclose closes the file */
    } /* end else */

    return 0; /* indicates successful termination */
} /* end main */