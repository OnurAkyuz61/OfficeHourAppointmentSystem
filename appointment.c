#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_NAME_LEN 50
#define MAX_DAY_LEN 10
#define MAX_TIME_LEN 10

void insert_office_hour();
void update_office_hour();
void print_office_hour();
void create_appointment();

int main() {
    int user_type;
    printf("**************************************************\n");
    printf("* WELCOME TO THE OFFICE HOUR APPOINTMENT SYSTEM  *\n");
    printf("**************************************************\n");
    printf("Who are you? (Enter 1 for TEACHER, 2 for STUDENT): ");
    scanf("%d", &user_type);

    if (user_type == 1) {
        char operation;
        while (1) {
            printf("Enter operation code (i: insert, u: update, p: print, q: quit): ");
            scanf(" %c", &operation);

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
                    return 0;
                default:
                    printf("Error: Invalid operation code.\n");
            }
        }
    } else if (user_type == 2) {
        while (1) {
            create_appointment();
            char quit_option;
            printf("Enter 'q' to quit or any other key to continue: ");
            scanf(" %c", &quit_option);
            if (quit_option == 'q') {
                break;
            }
        }
    } else {
        printf("Error: Invalid user type.\n");
    }

    return 0;
}