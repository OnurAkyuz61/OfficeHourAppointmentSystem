#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "student.h"
#include "readLine.h"

// Function to create an appointment
void create_appointment() {
    char student_name[MAX_NAME_LEN], teacher_name[MAX_NAME_LEN];
    int id;

    // Get student's name
    printf("Enter your full name: ");
    read_line(student_name, MAX_NAME_LEN);
    // Get teacher's name
    printf("Enter teacher's full name: ");
    read_line(teacher_name, MAX_NAME_LEN);

    // Print teacher's office hours
    print_office_hour(teacher_name);

    // Get the desired office hour ID
    printf("Enter the desired office hour ID: ");
    scanf("%d", &id);

    // Write appointment details to file
    FILE* file = fopen("appointments.txt", "a");
    if (file == NULL) {
        printf("Error opening file appointments.txt.\n");
        return;
    }

    fprintf(file, "%s %s %d\n", student_name, teacher_name, id);
    fclose(file); // Close file
}