// 2200005590, Onur AKYUZ

// for Visual Studio compiler
#define _CRT_SECURE_NO_WARNINGS

// Include necessary header files
#include <stdio.h>
#include <ctype.h>
#include "project.h"

int read_line(char str[], int n) { // read line function
    int ch, i = 0; // define variables

    while (isspace(ch = getchar())); // skip white spaces
    str[i++] = ch; // store character in string
    while ((ch = getchar()) != '\n') { // loop until newline character is encountered
        if (i < n) { // if string length is less than n
            str[i++] = ch; // store character in string
        }
    }
    str[i] = '\0'; // add null character to end of string
    return i; // return string length
}