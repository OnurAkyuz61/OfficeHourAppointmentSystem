// 2200005590, Onur Akyuz

// for Visual Studio compiler
#define _CRT_SECURE_NO_WARNINGS

// Include necessary header files
#include <stdio.h>
#include "project.h"

// functions prototypes
void insert_office_hour(); 
void update_office_hour();
void print_office_hour();
void create_appointment();

// main function
int main() {
    int user_type; // define user type

    // print welcome message
    printf("**************************************************\n");
    printf("* WELCOME TO THE OFFICE HOUR APPOINTMENT SYSTEM  *\n");
    printf("**************************************************\n");
    printf("Who are you? (Enter 1 for TEACHER, 2 for STUDENT): ");
    
    scanf("%d", &user_type); //

    if (user_type == 1) { // if user is teacher
        char operation; // define operation
        while (1) { // infinite loop
            printf("Enter operation code (i: insert, u: update, p: print, q: quit): "); // print operation code
            scanf(" %c", &operation); // get operation code

            switch (operation) { // switch operation code
                case 'i': // if operation code is i
                    insert_office_hour(); // call insert_office_hour function
                    break; // break switch
                case 'u': // if operation code is u
                    update_office_hour(); // call update_office_hour function
                    break; // break switch
                case 'p': // if operation code is p
                    print_office_hour(); // call print_office_hour function
                    break; // break switch
                case 'q': // if operation code is q
                    return 0; // return 0
                default: // if operation code is not i, u, p, or q
                    printf("Error: Invalid operation code.\n"); // print error message
            }
        }
    } else if (user_type == 2) { // if user is student
        while (1) {
            create_appointment(); // call create_appointment function
            char quit_option; // define quit option
            printf("Enter 'q' to quit or any other key to continue: "); // print quit option message
            scanf(" %c", &quit_option); // get quit option
            if (quit_option == 'q') { // if quit option is q
                break; // break while loop
            }
        }
    } else { // if user type is not 1 or 2
        printf("Error: Invalid user type.\n"); // print error message
    }

    return 0; // return statement
}