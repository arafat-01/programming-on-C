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

typedef struct {   // Creating new data type called station
	char name[30];
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
		fscanf (infile, "%lf %s", &line[n].km, line[n].name);  // Reading input data from file
		n ++;
	}
	return n;  // Return number of stations in input file
}

int main () {  
	setvbuf (stdout, NULL, _IONBF, 0);
	station railwayLine[100];
	int numberOfStations = readStations ("london-cambridge.txt", railwayLine);  // Geting number of stations
	printf ("%i\n", numberOfStations);   // Printing number of stations
	int i;
	for (i = 0;i < numberOfStations;i ++) 
		printf ("%.1lf %s\n", railwayLine[i].km, railwayLine[i].name);   // Printing stations
	return 0;
}
