// 2200005590, Onur AKYUZ

#ifndef TEACHER_H 
#define TEACHER_H

#include "project.h"

void insert_office_hour();
void update_office_hour();
void print_office_hour();
int store_office_hour(int id, const char* day, const char* start, const char* end, const char* filename);

#endif // TEACHER_H