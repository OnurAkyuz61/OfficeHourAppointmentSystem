#include <stdio.h>
#include <string.h>
#include "teacher.h"
#include "readLine.h"

// Function to insert a new office hour
void insert_office_hour() {
    int id;
    char day[MAX_DAY_LEN], start[MAX_TIME_LEN], end[MAX_TIME_LEN];
    char filename[MAX_NAME_LEN];

    // Get teacher's name
    printf("Enter your full name: ");
    read_line(filename, MAX_NAME_LEN);
    // Get office hour details
    printf("Enter identification number: ");
    scanf("%d", &id);
    getchar();  // Consume newline
    printf("Enter a day: ");
    read_line(day, MAX_DAY_LEN);
    printf("Enter starting hour: ");
    read_line(start, MAX_TIME_LEN);
    printf("Enter ending hour: ");
    read_line(end, MAX_TIME_LEN);

    // Write office hour to file
    if (store_office_hour(id, day, start, end, filename) == 0) {
        printf("Office hour added successfully.\n");
    }
    else {
        printf("Error adding office hour.\n");
    }
}

// Function to store office hour details in a file
int store_office_hour(int id, const char* day, const char* start, const char* end, const char* filename) {
    FILE* file = fopen(filename, "a"); // Open file in append mode
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        return -1;
    }
    // Write office hour details to file
    fprintf(file, "%d %s %s %s\n", id, day, start, end);
    fclose(file); // Close file
    return 0;
}

// Function to update an existing office hour
void update_office_hour() {
    int id, choice;
    char new_value[MAX_DAY_LEN];
    char filename[MAX_NAME_LEN];

    // Get teacher's name
    printf("Enter your full name: ");
    read_line(filename, MAX_NAME_LEN);

    // Get details of the office hour to be updated
    printf("Enter the identification number to update: ");
    scanf("%d", &id);
    getchar();  // Consume newline
    printf("1: Update day\n2: Update start time\n3: Update end time\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();  // Consume newline

    printf("Enter the new value: ");
    read_line(new_value, MAX_DAY_LEN);

    // Update office hour details in file
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        return;
    }

    int temp_id;
    char day[MAX_DAY_LEN], start[MAX_TIME_LEN], end[MAX_TIME_LEN];
    long pos;
    while ((pos = ftell(file)) != -1 && fscanf(file, "%d %s %s %s", &temp_id, day, start, end) == 4) {
        if (temp_id == id) {
            fseek(file, pos, SEEK_SET);
            switch (choice) {
            case 1:
                fprintf(file, "%d %s %s %s\n", id, new_value, start, end);
                break;
            case 2:
                fprintf(file, "%d %s %s %s\n", id, day, new_value, end);
                break;
            case 3:
                fprintf(file, "%d %s %s %s\n", id, day, start, new_value);
                break;
            default:
                printf("Invalid choice.\n");
                break;
            }
            break;
        }
    }
    fclose(file); // Close file
}

// Function to print office hours from file
void print_office_hour() {
    char filename[MAX_NAME_LEN];
    printf("Enter your full name: ");
    read_line(filename, MAX_NAME_LEN);

    FILE* file = fopen(filename, "r"); // Open file in read mode
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        return;
    }

    int id;
    char day[MAX_DAY_LEN], start[MAX_TIME_LEN], end[MAX_TIME_LEN];
    printf("ID number Day       Start      End\n");
    while (fscanf(file, "%d %s %s %s", &id, day, start, end) == 4) {
        printf("%d       %s       %s     %s\n", id, day, start, end);
    }

    fclose(file); // Close file
}