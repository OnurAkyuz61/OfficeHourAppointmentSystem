#include <stdio.h>
#include <ctype.h>
#include "readLine.h"

// Read a line of text into str with a maximum length of n
int read_line(char str[], int n) {
    int ch, i = 0;
    while (isspace(ch = getchar())) // Skip white-space characters
        ;
    while (ch != '\n' && ch != EOF) {
        if (i < n - 1)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}