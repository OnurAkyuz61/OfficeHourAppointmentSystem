// 2200005590, Onur Akyuz

// for Visual Studio compiler
#define _CRT_SECURE_NO_WARNINGS

// Include necessary header files
#include <stdio.h>
#include <string.h>
#include "student.h"
#include "readLine.h"
#include "teacher.h"

void create_appointment() {
    char student_name[MAX_NAME_LEN], teacher_name[MAX_NAME_LEN];
    int id;

    printf("Enter your full name: ");
    read_line(student_name, MAX_NAME_LEN);

    printf("Enter teacher's full name: ");
    read_line(teacher_name, MAX_NAME_LEN);

    print_office_hour(teacher_name);

    printf("Enter the desired office hour ID: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        return;
    }

    FILE* file = fopen("appointments.txt", "a");
    if (file == NULL) {
        printf("Error opening file appointments.txt.\n");
        return;
    }

    fprintf(file, "%s %s %d\n", student_name, teacher_name, id);
    fclose(file);
}
