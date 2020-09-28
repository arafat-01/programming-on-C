/*
 ============================================================================
 Name        : task2.c
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

FILE *infile;

student *readStudents (char *fileName, int *entry_size, int all_ids[], int *studentSize) {
	infile = fopen (fileName, "r");        // Open input file
	fscanf (infile, "%i", entry_size);           // Reading number of lines in input file
	int i;
	student *cur = (student*)malloc ((*entry_size) * sizeof (student));      // Creating pointer using malloc()

	for (i = 0;i < *entry_size;i ++) {
		(cur + i) -> firstName = (char*)malloc (30 * sizeof(char));             // Creating char array using malloc ()
		(cur + i) -> secondName = (char*)malloc (30 * sizeof(char));
		fscanf (infile, "%s %s %i %i", (cur + i) -> firstName, (cur + i) -> secondName, &(cur + i) -> ID, &(cur + i) -> grade);// Reading input from file 
		if (all_ids[(cur + i) -> ID] == 0) (*studentSize) ++;   // If new student ID, then the number of students increases
		all_ids[(cur + i) -> ID] ++;        // Counting number of entrances of each student ID
	}
	fclose (infile);
	return cur;
}

int main () {
	setvbuf(stdout, NULL, _IONBF, 0);
	int i, lines, howManyStudents = 0;
	int *cnt_id = (int*)malloc (101 * sizeof(int));               // Creating array using malloc()
	for (i = 0;i <= 100;i ++) cnt_id[i] = 0;                      // Get rid of garbages

	student *pstudent = readStudents ("students1.txt", &lines, cnt_id, &howManyStudents);             // Creating pointer and filling it

	for (i = 0;i < lines;i ++) 
		printf ("%s %s %i %i\n", (pstudent + i) -> firstName, (pstudent + i) -> secondName, (pstudent + i) -> ID, (pstudent + i) -> grade);
	return 0;                                               // Printing answer
}