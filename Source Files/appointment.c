#include <stdio.h>
#include "project.h"
#include "teacher.h"
#include "student.h"

int main() {
    int user_type;
    printf("**************************************************\n");
    printf("* WELCOME TO THE OFFICE HOUR APPOINTMENT SYSTEM  *\n");
    printf("**************************************************\n");
    printf("Who are you? (Enter 1 for TEACHER, 2 for STUDENT): ");
    scanf("%d", &user_type);
    getchar();  // Consume newline

    if (user_type == 1) {
        char operation;
        do {
            printf("Enter operation code (i: insert, u: update, p: print, q: quit): ");
            operation = getchar();
            getchar();  // Consume newline
            switch (operation) {
            case 'i':
                insert_office_hour();
                break;
            case 'u':
                update_office_hour();
                break;
            case 'p':
                print_office_hour();
                break;
            case 'q':
                break;
            default:
                printf("Invalid operation code.\n");
            }
        } while (operation != 'q');
    }
    else if (user_type == 2) {
        create_appointment();
    }
    else {
        printf("Invalid user type.\n");
    }

    return 0;
}
