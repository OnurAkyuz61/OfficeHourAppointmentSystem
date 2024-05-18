// 2200005590, Onur AKYUZ

// for Visual Studio compiler
#define _CRT_SECURE_NO_WARNINGS

// Include necessary header files
#include <stdio.h>
#include <string.h>
#include "project.h"

void create_appointment() { // create appointment function
    char student_name[MAX_NAME_LEN]; // define student name
    char teacher_name[MAX_NAME_LEN]; // define teacher name
    int id; // define id

    printf("Enter your full name: "); // print enter full name message
    if (scanf("%s", student_name) != 1) { // if scanf fails
        printf("Error reading student name.\n"); // print error message
        return; // return statement
    }
    printf("Enter teacher's full name: "); // print enter teacher name message
    if (scanf("%s", teacher_name) != 1) { // if scanf fails
        printf("Error reading teacher name.\n"); // print error message
        return; // return statement
    }

    char filename[100]; // define filename
    snprintf(filename, sizeof(filename), "%s_appointments.txt", teacher_name); // generate filename

    FILE *file = fopen(teacher_name, "r"); // open teacher file
    if (!file) { // if file does not exist
        printf("Error: Could not open teacher's file.\n"); // print error message
        return; // return statement
    }

    printf("ID number  Day       Start   End\n"); // print header
    int office_id; // define office id
    char day[MAX_DAY_LEN]; // define day
    char start[MAX_TIME_LEN]; // define start time
    char end[MAX_TIME_LEN]; // define end time

    while (fscanf(file, "%d %s %s %s", &office_id, day, start, end) != EOF) { // loop until end of file
        printf("%d         %s    %s  %s\n", office_id, day, start, end); // print office id, day, start time, and end time
    }
    fclose(file); // close file

    printf("Enter desired identification number of office hour: "); // print enter desired office hour message
    if (scanf("%d", &id) != 1) { // if scanf fails
        printf("Error reading office hour ID.\n"); // print error message
        return; // return statement
    }

    file = fopen(filename, "a"); // open appointment file
    if (!file) { // if file does not exist
        printf("Error: Could not open appointment file.\n"); // print error message
        return; // return statement
    }

    fprintf(file, "%s %s %s %s %s\n", teacher_name, student_name, day, start, end); // write appointment to file
    fclose(file); // close file

    printf("Appointment created successfully.\n"); // print appointment created message
}