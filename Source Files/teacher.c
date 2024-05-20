// 2200005590, Onur Akyuz

// for Visual Studio compiler
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // include standard input output header
#include <string.h> // include string header
#include "teacher.h" // include teacher header
#include "readLine.h" // include read line header

void insert_office_hour() { // Insert office hour function
    int id; // Define ID
    char day[MAX_DAY_LEN], start[MAX_TIME_LEN], end[MAX_TIME_LEN]; // Define day, start, and end
    char filename[MAX_NAME_LEN]; // Define filename

    printf("Enter your full name: "); // Print enter full name message
    read_line(filename, MAX_NAME_LEN); // Read filename

    printf("Enter identification number: "); // Print enter identification number message
    if (scanf("%d", &id) != 1) { // Get ID
        printf("Invalid input.\n"); // Print invalid input message
        return; // Return statement
    }
    getchar(); // Clear input buffer
    printf("Enter a day: "); // Print enter a day message
    read_line(day, MAX_DAY_LEN); // Read day
    printf("Enter starting hour: "); // Print enter starting hour message
    read_line(start, MAX_TIME_LEN); // Read start
    printf("Enter ending hour: "); // Print enter ending hour message
    read_line(end, MAX_TIME_LEN); // Read end

    if (store_office_hour(id, day, start, end, filename) == 0) { // If store office hour function returns 0
        printf("\nOffice hour added successfully.\n"); // Print office hour added successfully message
    }
    else { // If store office hour function returns 1
        printf("\nError adding office hour.\n"); // Print error adding office hour message
    }
}

int store_office_hour(int id, const char* day, const char* start, const char* end, const char* filename) { // Store office hour function
    FILE* file = fopen(filename, "a"); // Open file in append mode
    if (file == NULL) { // If file is null
        printf("Error opening file %s.\n", filename); // Print error opening file message
        return -1; // Return -1
    }

    fprintf(file, "%d %s %s %s\n", id, day, start, end); // Write ID, day, start, and end to file
    fclose(file); // Close file
    return 0; // Return 0
}

void update_office_hour() { // Update office hour function
    int id, choice; // Define ID and choice
    char new_value[MAX_DAY_LEN]; // Define new value
    char filename[MAX_NAME_LEN]; // Define filename

    printf("Enter your full name: "); // Print enter full name message
    read_line(filename, MAX_NAME_LEN); // Read filename

    printf("Enter the identification number to update: "); // Print enter the identification number to update message
    if (scanf("%d", &id) != 1) { // Get ID
        printf("Invalid input.\n"); // Print invalid input message
        return; // Return statement
    }
    getchar(); // Clear input buffer
    printf("\n1: Update day\n2: Update start time\n3: Update end time\n"); // Print update day, start time, and end time message
    printf("Enter your choice: "); // Print enter your choice message
    if (scanf("%d", &choice) != 1) { // Get choice
        printf("Invalid input.\n"); // Print invalid input message
        return; // Return statement
    }
    getchar(); // Clear input buffer

    printf("Enter the new value: "); // Print enter the new value message
    read_line(new_value, MAX_DAY_LEN); // Read new value

    FILE* file = fopen(filename, "r"); // Open file in read mode
    if (file == NULL) { // If file is null
        printf("Error opening file %s.\n", filename); // Print error opening file message
        return; // Return statement
    }

    FILE* temp_file = fopen("temp.txt", "w"); // Open temp file in write mode
    if (temp_file == NULL) { // If temp file is null
        printf("Error opening temporary file.\n"); // Print error opening temporary file message
        fclose(file); // Close file
        return; // Return statement
    }

    int temp_id; // Define temp ID
    char day[MAX_DAY_LEN], start[MAX_TIME_LEN], end[MAX_TIME_LEN]; // Define day, start, and end
    int found = 0; // Define found

    while (fscanf(file, "%d %s %s %s", &temp_id, day, start, end) == 4) { // Read file
        if (temp_id == id) { // If temp ID is equal to ID
            found = 1; // Set found to 1
            switch (choice) { // Switch on choice
            case 1: // If choice is 1
                fprintf(temp_file, "%d %s %s %s\n", temp_id, new_value, start, end); // Write temp ID, new value, start, and end to temp file
                break; // Break statement
            case 2: // If choice is 2
                fprintf(temp_file, "%d %s %s %s\n", temp_id, day, new_value, end); // Write temp ID, day, new value, and end to temp file
                break; // Break statement
            case 3: // If choice is 3
                fprintf(temp_file, "%d %s %s %s\n", temp_id, day, start, new_value); // Write temp ID, day, start, and new value to temp file
                break; // Break statement
            default: // If choice is invalid
                printf("Invalid choice.\n"); // Print invalid choice message
                fprintf(temp_file, "%d %s %s %s\n", temp_id, day, start, end); // Write temp ID, day, start, and end to temp file
                break; // Break statement
            }
        }
        else { // If temp ID is not equal to ID
            fprintf(temp_file, "%d %s %s %s\n", temp_id, day, start, end); // Write temp ID, day, start, and end to temp file
        }
    }

    fclose(file); // Close file
    fclose(temp_file); // Close temp file

    if (found) { // If found is 1
        if (rename("temp.txt", filename) != 0) { // If rename function returns 0
            printf("Error renaming temporary file.\n"); // Print error renaming temporary file message
        }
        else { // If rename function returns 1
            printf("Office hour updated successfully.\n"); // Print office hour updated successfully message
        }
    }
    else { // If found is 0
        remove("temp.txt"); // Remove temp file
        printf("ID not found.\n"); // Print ID not found message
    }
}

void print_office_hour(const char* filename) { // Print office hour function
    FILE* file = fopen(filename, "r"); // Open file in read mode
    if (file == NULL) { // If file is null
        printf("\nError opening file %s.\n", filename); // Print error opening file message
        return; // Return statement
    }

    int id; // Define ID
    char day[MAX_DAY_LEN], start[MAX_TIME_LEN], end[MAX_TIME_LEN]; // Define day, start, and end
    printf("\n%-10s %-10s %-15s %-15s\n", "ID number", "Day", "Start", "End"); // Print ID number, day, start, and end message
    printf("-----------------------------------------------\n"); // Print line message
    while (fscanf(file, "%d %s %s %s", &id, day, start, end) == 4) { // Read file
        printf("%-10d %-10s %-15s %-15s\n", id, day, start, end); // Print ID, day, start, and end message
    }

    fclose(file); // Close file
}