#ifndef HGHGH_H
#define HGHGH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MARKS 5
#define size 1000
#define GROUPS 4

typedef struct Student {
    int marks[MARKS];
    char name[size];
    float average;
} Student;

Student** make_place();
int doesitexist(Student* stud, int mark_it);
void input_size(int* amount);
Student input_student();
void input_group(Student* group, int n);
Student* memory_for_group(int amount);
void making_groups(Student** all_groups, Student* group, int* for_marks, int n);
void average_for_all(Student** all_groups, int* for_marks);
void sorting_students(Student** all_groups, int* k);
void counting_fs(Student** groups, int* k);
void output_group(Student** all_groups, int* for_marks);

#endif
