#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "project.h"

void create_appointment() {
    char student_name[MAX_NAME_LEN];
    char teacher_name[MAX_NAME_LEN];
    int id;

    printf("Enter your full name: ");
    if (scanf("%s", student_name) != 1) {
        printf("Error reading student name.\n");
        return;
    }
    printf("Enter teacher's full name: ");
    if (scanf("%s", teacher_name) != 1) {
        printf("Error reading teacher name.\n");
        return;
    }

    char filename[100];
    snprintf(filename, sizeof(filename), "%s_appointments.txt", teacher_name);

    FILE *file = fopen(teacher_name, "r");
    if (!file) {
        printf("Error: Could not open teacher's file.\n");
        return;
    }

    printf("ID number  Day       Start   End\n");
    int office_id;
    char day[MAX_DAY_LEN];
    char start[MAX_TIME_LEN];
    char end[MAX_TIME_LEN];

    while (fscanf(file, "%d %s %s %s", &office_id, day, start, end) != EOF) {
        printf("%d         %s    %s  %s\n", office_id, day, start, end);
    }
    fclose(file);

    printf("Enter desired identification number of office hour: ");
    if (scanf("%d", &id) != 1) {
        printf("Error reading office hour ID.\n");
        return;
    }

    file = fopen(filename, "a");
    if (!file) {
        printf("Error: Could not open appointment file.\n");
        return;
    }

    fprintf(file, "%s %s %s %s %s\n", teacher_name, student_name, day, start, end);
    fclose(file);

    printf("Appointment created successfully.\n");
}