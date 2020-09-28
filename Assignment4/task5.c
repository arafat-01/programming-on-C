/*
 ============================================================================
 Name        : task5.c
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

int getMaxGrade (student *students, int from, int to) {
    if (from == to) return students -> grade;               // Breaking point when from == to
    int x = getMaxGrade (students + 1, from + 1, to);       // Maximum from the right side of the 'from'
    if (x < students -> grade) x = students -> grade;       // Comparing maximum from the right side with current number
    return x;
}

int getTopThreeAvgGrade (student *students, int entry_size, int id, int all_ids[]) {
    int i, mx1 = 0, mx2 = 0, mx3 = 0;
    for (i = 0;i < entry_size;i ++) {          // Go through students' list
        if (students -> ID != id) {              // We need only certain ID
            students ++;                           // Move to next student
            continue;
        }
        if (students -> grade >= mx1) {                //
            mx3 = mx2;                                   //
            mx2 = mx1;                                   //
            mx1 = students -> grade;                     //   Saving top three grades
        } else if (students -> grade >= mx2) {         //
            mx3 = mx2;                                   //
            mx2 = students -> grade;                     //
        } else if (students -> grade > mx3) {          //
            mx3 = students -> grade;                     //
        }
        students ++;                                  // Move to next student
    }
    int sum = mx1 + mx2 + mx3;                      // Sum of top three grades
    int del = all_ids[id];                          // The number of entries of certain student
    if (del > 3) del = 3;                           // We need only 3 entries at most
    if (del > 0)                                    // Consider a case when number of entries is zero
        sum /= del;                                   // Get average score
    else
        sum = 0;         // Division by 0
    return sum;
}

void fillAllStudentsAvgGrades (topThreeAvg *averages[], student *students, int entry_size, int all_ids[]) {
    int i, sz = -1;
    for (i = 0;i <= 100;i ++) {
        if (all_ids[i] == 0) continue; // We need to consider only valid ids
        sz ++;
        averages[sz] -> ID = i;     // Save id
        averages[sz] -> avgGrade = getTopThreeAvgGrade (students, entry_size, i, all_ids); // Save average score
    }
} 

int main () {
    setvbuf(stdout, NULL, _IONBF, 0);
    int i, lines, howManyStudents = 0;

    int *cnt_id = (int*)malloc (101 * sizeof(int));
    for (i = 0;i <= 100;i ++) cnt_id[i] = 0;

    student *pstudent = readStudents ("students1.txt", &lines, cnt_id, &howManyStudents);

    topThreeAvg *arr[howManyStudents];
    for (i = 0;i < howManyStudents;i ++) arr[i] = (topThreeAvg*)malloc (sizeof(topThreeAvg));

    fillAllStudentsAvgGrades (arr, pstudent, lines, cnt_id);

    for (i = 0;i < howManyStudents;i ++)
        printf ("Student id: %i, student's top three average: %i\n", arr[i] -> ID, arr[i] -> avgGrade);
    return 0;
}
