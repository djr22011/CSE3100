#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* print out an error message and exit */
void my_error(char *s)
{
    perror(s);
    exit(1);
}

/* Concatnate two strings.
 * Dynamically allocate space for the result.
 * Return the address of the result.
 */
char *my_strcat(char *s1, char *s2)
{
    // TODO 
    int len = strlen(s1) + strlen(s2) + 1; //stores the length of the strings together and null terminator
    char *conc = malloc(len); //allocates enough memory to store string of length len

    //raises error if malloc fails
    if(conc == NULL)
    {
        my_error("Not enough memory");
    } 

    strcpy(conc, s1); //copies first string to allocated memory 
    strcat(conc, s2); //concatenates the second string to first, storing them both in memory

    return conc; //returns the concatenated string
}

int main(int argc, char *argv[])
{
    char    *s;

    s = my_strcat("", argv[0]);

    for (int i = 1; i < argc; i ++) {
        s = my_strcat(s, argv[i]);
    }

    printf("%s\n", s);
    free(s); //free the allocated memory

    return 0;
}