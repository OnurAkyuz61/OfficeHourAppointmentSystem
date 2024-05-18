//2200005590, Onur AKYUZ

// for Visual Studio compiler
#define _CRT_SECURE_NO_WARNINGS

// Include necessary header files
#include <stdio.h>
#include <string.h>
#include "project.h"

// Function definitions for managing office hours and appointments
int store_office_hour(int id, const char *day, const char *start, const char *end);
int find_office_hour(int id);

void insert_office_hour() { // insert office hour function
    int id; // define id
    char day[MAX_DAY_LEN]; // define day
    char start[MAX_TIME_LEN]; // define start time
    char end[MAX_TIME_LEN]; // define end time

    printf("Enter identification number: "); // print enter identification number message
    scanf("%d", &id); // get id
    printf("Enter a day: "); // print enter day message
    scanf("%s", day); // get day
    printf("Enter starting hour: "); // print enter starting hour message
    scanf("%s", start); // get start time
    printf("Enter ending hour: "); // print enter ending hour message
    scanf("%s", end); // get end time

    if (store_office_hour(id, day, start, end)) { // if store office hour function returns 1
        printf("Office hour added successfully.\n"); // print office hour added message
    } else { // if store office hour function returns 0
        printf("Error: Office hour already exists or database is full.\n"); // print error message
    }
}

void update_office_hour() { // update office hour function
    int id; // define id
    int option; // define option
    char new_value[MAX_TIME_LEN]; // define new value

    printf("Enter identification number: "); // print enter identification number message
    scanf("%d", &id); // get id

    int index = find_office_hour(id); // find office hour index
    if (index == -1) { // if index is -1
        printf("Error: Office hour not found.\n"); // print error message
        return; // return statement
    }

    printf("Enter 1 to update day, 2 to update start, 3 to update end: "); // print enter option message
    scanf("%d", &option); // get option
    printf("Enter new value: "); // print enter new value message
    scanf("%s", new_value); // get new value

    printf("Office hour updated successfully.\n"); // print office hour updated message
}

void print_office_hour() { // print office hour function
    char teacher_name[MAX_NAME_LEN]; // define teacher name
    printf("Enter your full name: "); // print enter full name message
    scanf("%s", teacher_name); // get teacher name

    FILE *file = fopen(teacher_name, "r"); // open teacher file
    if (!file) { // if file does not exist
        printf("Error: Could not open file.\n"); // print error message
        return; // return statement
    } 

    int id; // define id
    char day[MAX_DAY_LEN]; // define day
    char start[MAX_TIME_LEN]; // define start time
    char end[MAX_TIME_LEN]; // define end time

    printf("ID number  Day       Start   End\n"); // print header
    while (fscanf(file, "%d %s %s %s", &id, day, start, end) != EOF) { // loop until end of file
        printf("%d         %s    %s  %s\n", id, day, start, end); // print office id, day, start time, and end time
    }

    fclose(file); // close file
}

int store_office_hour(int id, const char *day, const char *start, const char *end) { // store office hour function
    char teacher_name[MAX_NAME_LEN]; // define teacher name
    printf("Enter your full name: "); // print enter full name message
    scanf("%s", teacher_name); // get teacher name

    FILE *file = fopen(teacher_name, "a"); // open teacher file
    if (!file) { // if file does not exist
        return 0; // return 0
    }

    fprintf(file, "%d %s %s %s\n", id, day, start, end); // write office hour to file
    fclose(file); // close file

    return 1; // return 1
}

int find_office_hour(int id) { // find office hour function
    char teacher_name[MAX_NAME_LEN]; // define teacher name
    printf("Enter your full name: "); // print enter full name message
    scanf("%s", teacher_name); // get teacher name

    FILE *file = fopen(teacher_name, "r"); // open teacher file
    if (!file) { // if file does not exist
        return -1; // return -1
    }

    int search_id; // define search id
    char day[MAX_DAY_LEN]; // define day
    char start[MAX_TIME_LEN]; // define start time
    char end[MAX_TIME_LEN]; // define end time

    while (fscanf(file, "%d %s %s %s", &search_id, day, start, end) != EOF) { // loop until end of file
        if (search_id == id) { // if search id is equal to id
            fclose(file); // close file
            return search_id; // return search id
        }
    }

    fclose(file); // close file
    return -1; // return -1
}
