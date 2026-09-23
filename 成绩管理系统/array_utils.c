#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include "student.h"


int add_student(Student students[], int* count, Student new_student);
int delete_student_by_id(Student students[], int* count, int id);
int find_student_by_id(Student students[], int count, int id);
int find_student_by_name(Student students[], int count, const char* name);
int shift_array_left(Student students[],int *count,int  index)



#endif