/*
 ============================================================================
 Name        : task1.c
 Author      : Arafat Bauyrzhanuly
 Version     :
 Copyright   : All rights reserved (2019)
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char *firstName;
	char *secondName;             // New struct called 'student'
	int ID, grade;
} student;

typedef struct {
	int ID, avgGrade;            // New struct called 'topThreeAvg'
} topThreeAvg;

int main () {
	setvbuf(stdout, NULL, _IONBF, 0);
	student *pstudent;          // Creating pointer for 'student' data type

	return 0;
}
