// 2200005590, Onur Akyuz

// for Visual Studio compiler
#define _CRT_SECURE_NO_WARNINGS

// Include necessary header files
#include <stdio.h>
#include <string.h>
#include "teacher.h"
#include "readLine.h"

void insert_office_hour() { // insert office hour function
    int id; // define id
    char day[MAX_DAY_LEN], start[MAX_TIME_LEN], end[MAX_TIME_LEN]; // define day, start, and end
    char filename[MAX_NAME_LEN]; // define filename

    printf("Enter your full name: "); // print enter full name message
    read_line(filename, MAX_NAME_LEN); // read full name

    printf("Enter identification number: "); // print enter identification number message
    scanf("%d", &id); // get id
    getchar();  // clear input buffer
    printf("Enter a day: "); // print enter a day message
    read_line(day, MAX_DAY_LEN); // read day
    printf("Enter starting hour: "); // print enter starting hour message
    read_line(start, MAX_TIME_LEN); // read starting hour
    printf("Enter ending hour: "); // print enter ending hour message
    read_line(end, MAX_TIME_LEN); // read ending hour

    if (store_office_hour(id, day, start, end, filename) == 0) { // if store office hour function returns 0
        printf("\nOffice hour added successfully.\n"); // print office hour added successfully message
    }
    else { // if store office hour function returns 1
        printf("\nError adding office hour.\n"); // print error adding office hour message
    }
}

int store_office_hour(int id, const char* day, const char* start, const char* end, const char* filename) { // store office hour function
    FILE* file = fopen(filename, "a"); // open file in append mode
    if (file == NULL) { // if file does not exist
        printf("Error opening file %s.\n", filename); // print error message
        return -1; // return statement
    }

    fprintf(file, "%d %s %s %s\n", id, day, start, end); // write id, day, start, and end to file
    fclose(file); // Close file
    return 0; // return statement
}

void update_office_hour() { // update office hour function
    int id, choice; // define id and choice
    char new_value[MAX_DAY_LEN]; // define new value
    char filename[MAX_NAME_LEN]; // define filename

    printf("Enter your full name: "); // print enter full name message
    read_line(filename, MAX_NAME_LEN); // read full name

    printf("Enter the identification number to update: "); // print enter the identification number to update message
    scanf("%d", &id); // get id
    getchar();  // clear input buffer
    printf("\n1: Update day\n2: Update start time\n3: Update end time\n"); // print update day, start time, and end time message
    printf("Enter your choice: "); // print enter your choice message
    scanf("%d", &choice); // get choice
    getchar();  // clear input buffer

    printf("Enter the new value: "); // print enter the new value message
    read_line(new_value, MAX_DAY_LEN); // read new value

    FILE* file = fopen(filename, "r+"); // open file in read and write mode
    if (file == NULL) { // if file does not exist
        printf("Error opening file %s.\n", filename); // print error message
        return; // return statement
    }

    int temp_id; // define temp id
    char day[MAX_DAY_LEN], start[MAX_TIME_LEN], end[MAX_TIME_LEN]; // define day, start, and end
    long pos; // define position
    while ((pos = ftell(file)) != -1 && fscanf(file, "%d %s %s %s", &temp_id, day, start, end) == 4) { // loop until end of file is reached
        if (temp_id == id) { // if temp id is equal to id
            fseek(file, pos, SEEK_SET); // set position to pos
            switch (choice) { // switch on choice
            case 1: // if choice is 1
                fprintf(file, "%d %s %s %s\n", id, new_value, start, end); // write id, new value, start, and end to file
                break; // break statement
            case 2: // if choice is 2
                fprintf(file, "%d %s %s %s\n", id, day, new_value, end); // write id, day, new value, and end to file
                break; // break statement
            case 3: // if choice is 3
                fprintf(file, "%d %s %s %s\n", id, day, start, new_value); // write id, day, start, and new value to file
                break; // break statement
            default: // if choice is invalid
                printf("Invalid choice.\n"); // print invalid choice message
                break; // break statement
            }
            break; // break statement
        }
    }
    fclose(file); // Close file
}

void print_office_hour() { // print office hour function
    char filename[MAX_NAME_LEN]; // define filename
    printf("\nEnter your full name: "); // print enter full name message
    read_line(filename, MAX_NAME_LEN); // read full name

    FILE* file = fopen(filename, "r"); // Open file in read mode
    if (file == NULL) { // if file does not exist
        printf("\nError opening file %s.\n", filename); // print error message
        return; // return statement
    }

    int id; // define id
    char day[MAX_DAY_LEN], start[MAX_TIME_LEN], end[MAX_TIME_LEN]; // define day, start, and end
    printf("\n%-10s %-10s %-15s %-15s\n", "ID number", "Day", "Start", "End"); // print id number day, start, and end
    printf("-----------------------------------------------\n");
    while (fscanf(file, "%d %s %s %s", &id, day, start, end) == 4) { // loop until end of file is reached
        printf("%-10d %-10s %-15s %-15s\n", id, day, start, end); // print id, day, start, and end
    }

    fclose(file); // Close file
}