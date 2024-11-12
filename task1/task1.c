#include "task1.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void str_lower(char *orig, char *copy) {
    /* Write the function, str_lower, to take two arguments: the original input string and a buffer to store the lowercase version of the input string. The buffer is needed because an array (a string) declared locally to str_lower would be stored on the run-time stack and, thus, could not be safely returned. Alternately, one could dynamically allocate the buffer, but that comes later. Write the str_lower function to copy into the buffer the lowercase version of each character in the original string. You should use tolower from ctype.h (#include this header file) to convert a character to lowercase. */
    int i;
    for (i = 0; i < strlen(orig); i++) {
        copy[i] = tolower(orig[i]);
    }

    copy[strlen(orig)] = '\0';
    
    //printf("ORIGINAL: %s\n", orig);
    //printf("COPY: %s\n", copy);
}

void str_lower_mutate(char *orig) {
    /* Write the function, str_lower_mutate. This function takes a single string argument and changes the characters to lowercase by modifying the contents of the string itself. As such, the "result" is the original argument. This style is not uncommon in C since strings are mutable, but it can lead to unintended side-effects when there are multiple aliases to the same string. */
    // printf("ORIGINAL: %s\n", orig);
    int i;
    for (i = 0; i < strlen(orig); i++) {
        orig[i] = tolower(orig[i]);
    }

    orig[strlen(orig)] = '\0';
    //printf("NEW: %s\n", orig);
}
