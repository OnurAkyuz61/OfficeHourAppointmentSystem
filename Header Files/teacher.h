// 2200005590, Onur AKYUZ

// if teacher.h is not defined
#ifndef TEACHER_H 

// define teacher.h
#define TEACHER_H 

// include project header
#include "project.h" 

void insert_office_hour(); // insert office hour function
void update_office_hour(); // update office hour function
void print_office_hour(); // print office hour function
int store_office_hour(int id, const char* day, const char* start, const char* end, const char* filename); // store office hour function

#endif // TEACHER_H