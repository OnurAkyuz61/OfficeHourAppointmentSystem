#ifndef PROJECT_H
#define PROJECT_H

#define MAX_NAME_LEN 50
#define MAX_DAY_LEN 10
#define MAX_TIME_LEN 10
#define MAX_LINE_LEN 100

void insert_office_hour();
void update_office_hour();
void print_office_hour();
void create_appointment();
int read_line(char str[], int n);
int store_office_hour(int id, const char *day, const char *start, const char *end);
int find_office_hour(int id);

#endif // PROJECT_H