#pragma once
#ifndef STUDENT_H
#define STUDENT_H

# define MAX_NAME_LEN 20
#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5

typedef struct {
	int id;
	char name[MAX_NAME_LEN];
	float scores[MAX_SUBJECTS];
	float average;
	float total;
}Student;


#endif