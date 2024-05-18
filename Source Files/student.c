// 2200005590, Onur Akyuz

// for Visual Studio compiler
#define _CRT_SECURE_NO_WARNINGS

// Include necessary header files
#include <stdio.h>
#include <string.h>
#include "student.h"
#include "readLine.h"

void create_appointment() { // create appointment function
    char student_name[MAX_NAME_LEN], teacher_name[MAX_NAME_LEN]; // define student name and teacher name
    int id; // define id

    printf("Enter your full name: "); // print enter full name message
    read_line(student_name, MAX_NAME_LEN); // read student name

    printf("Enter teacher's full name: "); // print enter teacher's full name message
    read_line(teacher_name, MAX_NAME_LEN); // read teacher name

    print_office_hour(teacher_name); // print office hour for teacher


    printf("Enter the desired office hour ID: "); // print enter desired office hour ID message
    scanf("%d", &id); // get id


    FILE* file = fopen("appointments.txt", "a"); // open appointments file in append mode
    if (file == NULL) { // if file does not exist
        printf("Error opening file appointments.txt.\n"); // print error message
        return; // return statement
    }

    fprintf(file, "%s %s %d\n", student_name, teacher_name, id); // write student name, teacher name, and id to file
    fclose(file); // Close file
}