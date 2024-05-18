// 2200005590, Onur Akyuz

// for Visual Studio compiler
#define _CRT_SECURE_NO_WARNINGS

// Include necessary header files
#include <stdio.h>
#include <ctype.h>
#include "readLine.h"

int read_line(char str[], int n) { // read line function
    int ch, i = 0; // define ch and i
    while (isspace(ch = getchar())) // loop until a non-whitespace character is read
        ;
    while (ch != '\n' && ch != EOF) { // loop until newline or end of file is reached
        if (i < n - 1) // if i is less than n - 1
            str[i++] = ch; // set str[i] to ch and increment i
        ch = getchar(); // get next character
    }
    str[i] = '\0'; // set str[i] to null character
    return i; // return statement
}