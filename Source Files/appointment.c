// 2200005590, Onur Akyuz

// for Visual Studio compiler
#define _CRT_SECURE_NO_WARNINGS

// Include necessary header files
#include <stdio.h>
#include "project.h"
#include "teacher.h"
#include "student.h"

int main() { // main function
    int user_type; // define user type

    printf("The project file information is given below\n"); // print project file information message

    printf("\tFile: %s\n", __FILE__); // print file name
    printf("\tDate: %s\n", __DATE__); // print date
    printf("\tTime: %s\n", __TIME__); // print time
    printf("\tLine: %s\n", __LINE__); // print line number

    // Prompt user to choose user type
    printf("**************************************************\n");
    printf("* WELCOME TO THE OFFICE HOUR APPOINTMENT SYSTEM  *\n");
    printf("**************************************************\n");
    printf("Who are you? (Enter 1 for TEACHER, 2 for STUDENT): ");

    scanf("%d", &user_type); // get user type

    getchar(); // clear input buffer

    if (user_type == 1) { // if user type is teacher
        char operation; // define operation
        do { // loop until user chooses to exit
            printf("Enter operation code (i: insert, u: update, p: print, q: quit): "); // print enter operation code message
            operation = getchar(); // get operation
            getchar(); // clear input buffer
            switch (operation) { // switch on operation
            case 'i': // if operation is insert
                insert_office_hour(); // call insert office hour function
                break; // break statement
            case 'u': // if operation is update
                update_office_hour(); // call update office hour function
                break; // break statement
            case 'p': // if operation is print
                print_office_hour(); // call print office hour function
                break; // break statement
            case 'q': // if operation is quit
                break; // break statement
            default: // if operation is invalid
                printf("Invalid operation code.\n"); // print invalid operation code message
            }
        } while (operation != 'q'); // loop until operation is quit
    }
    else if (user_type == 2) { // if user type is student
        create_appointment(); // call create appointment function
    }
    else { // if user type is invalid
        printf("Invalid user type.\n"); // print invalid user type message
    }

    return 0; // return statement
}