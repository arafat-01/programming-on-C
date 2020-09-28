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

typedef struct {       // Creating new data type called station 
	char name[20];
	double km;
} station; 

int readStations (char fileName[20], station line[]) {
	FILE *infile = fopen (fileName, "r");   
	if (infile == NULL) {
		printf ("Problem in opening file.\n");
		return 0;
	}
	int n = 0;
	while (!feof (infile)) {
		fscanf (infile, "%lf %s", &line[n].km, line[n].name); // Reading input data from file
		n ++;
	}
	return n; // Returning number of stations in input file
}
void printStation (station line[], int stationNumber, int includeNumber) {
	if (includeNumber == 1) {
		printf ("[%i] ", stationNumber);
	}
	int i;
	// According to assignment rules, we do not need to print '*', and should print ' ' instead of '-'
	for (i = 0;;i ++) {
		if (line[stationNumber].name[i] == '*') 
			break;
		if (line[stationNumber].name[i] == '-') 
			line[stationNumber].name[i] = ' ';  // Changing '-' to ' '
		printf ("%c", line[stationNumber].name[i]);
	}
	printf("\n");
}

int main() {
	setvbuf (stdout, NULL, _IONBF, 0);
	station railwayLine[100];
	int numberOfStations = readStations ("london-cambridge.txt", railwayLine);
	int i;
	for (i = 0;i < numberOfStations;i ++) 
		printStation (railwayLine, i, 1);    // Printing stations with station numbers in brackets
	for (i = 0;i < numberOfStations;i ++) 
		printStation (railwayLine, i, 0);    // Printing stations without station numbers in brackets
	return 0;
}