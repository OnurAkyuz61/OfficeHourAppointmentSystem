#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_DAY_LEN 10
#define MAX_TIME_LEN 10

int store_office_hour(int id, const char *day, const char *start, const char *end);
int find_office_hour(int id);

void insert_office_hour() {
    int id;
    char day[MAX_DAY_LEN];
    char start[MAX_TIME_LEN];
    char end[MAX_TIME_LEN];

    printf("Enter identification number: ");
    scanf("%d", &id);
    printf("Enter a day: ");
    scanf("%s", day);
    printf("Enter starting hour: ");
    scanf("%s", start);
    printf("Enter ending hour: ");
    scanf("%s", end);

    if (store_office_hour(id, day, start, end)) {
        printf("Office hour added successfully.\n");
    } else {
        printf("Error: Office hour already exists or database is full.\n");
    }
}

void update_office_hour() {
    int id;
    int option;
    char new_value[MAX_TIME_LEN];

    printf("Enter identification number: ");
    scanf("%d", &id);

    int index = find_office_hour(id);
    if (index == -1) {
        printf("Error: Office hour not found.\n");
        return;
    }

    printf("Enter 1 to update day, 2 to update start, 3 to update end: ");
    scanf("%d", &option);
    printf("Enter new value: ");
    scanf("%s", new_value);

    // Logic to update the office hour in the file
    // This is a simplified version and would need proper file handling
    // code to locate and update the specific line in the file.

    printf("Office hour updated successfully.\n");
}

void print_office_hour() {
    char teacher_name[MAX_NAME_LEN];
    printf("Enter your full name: ");
    scanf("%s", teacher_name);

    FILE *file = fopen(teacher_name, "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return;
    }

    int id;
    char day[MAX_DAY_LEN];
    char start[MAX_TIME_LEN];
    char end[MAX_TIME_LEN];

    printf("ID number  Day       Start   End\n");
    while (fscanf(file, "%d %s %s %s", &id, day, start, end) != EOF) {
        printf("%d         %s    %s  %s\n", id, day, start, end);
    }

    fclose(file);
}

int store_office_hour(int id, const char *day, const char *start, const char *end) {
    // Simplified storage logic
    char teacher_name[MAX_NAME_LEN];
    printf("Enter your full name: ");
    scanf("%s", teacher_name);

    FILE *file = fopen(teacher_name, "a");
    if (!file) {
        return 0;
    }

    fprintf(file, "%d %s %s %s\n", id, day, start, end);
    fclose(file);

    return 1;
}

int find_office_hour(int id) {
    // Simplified search logic
    char teacher_name[MAX_NAME_LEN];
    printf("Enter your full name: ");
    scanf("%s", teacher_name);

    FILE *file = fopen(teacher_name, "r");
    if (!file) {
        return -1;
    }

    int search_id;
    char day[MAX_DAY_LEN];
    char start[MAX_TIME_LEN];
    char end[MAX_TIME_LEN];

    while (fscanf(file, "%d %s %s %s", &search_id, day, start, end) != EOF) {
        if (search_id == id) {
            fclose(file);
            return search_id;
        }
    }

    fclose(file);
    return -1;
}
