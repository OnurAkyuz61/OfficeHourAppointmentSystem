// 2200005590, Onur AKYUZ

#ifndef TEACHER_H // if teacher.h is not defined

// define teacher.h
#define TEACHER_H

#include "project.h" // Include project header to use common macros

void insert_office_hour(); // Insert office hour function
void update_office_hour(); // Update office hour function
void print_office_hour(const char* filename); // Print office hour function
int store_office_hour(int id, const char* day, const char* start, const char* end, const char* filename); // Store office hour function

#endif // TEACHER_H