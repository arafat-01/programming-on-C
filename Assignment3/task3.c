/*
 ============================================================================
 Name        : task3.c
 Author      : Arafat Bauyrzhanuly
 Version     :
 Copyright   : All rights reserved (2019)
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {    // Creating new data type called station
	char name[20];
	double km;
} station;

int readStations(char fileName[20], station line[]) {
	FILE *infile = fopen(fileName, "r");
	if (infile == NULL) {
		printf("Problem in opening file.\n");
		return 0;
	}
	int n = 0;
	while (!feof(infile)) {
		fscanf(infile, "%lf %s", &line[n].km, line[n].name);  // Reading input data from input file
		n++;
	}
	return n;  // Returning number of stations in input file
}
void printStation(station line[], int stationNumber, int includeNumber) {
	if (includeNumber == 1) {
		printf("[%i] ", stationNumber);
	}
	int i;
	// According to assignment rules, we do not need to print '*', and should print ' ' instead of '-'
	for (i = 0;; i++) {
		if (line[stationNumber].name[i] == '*')
			break;
		if (line[stationNumber].name[i] == '-')
			line[stationNumber].name[i] = ' ';   // Changing '-' to ' '
		printf("%c", line[stationNumber].name[i]);
	}
	printf("\n");
}
double ticketPrice(station line[], int departure, int destination, int ticketClass) {
	double dist = line[departure].km - line[destination].km; // Calculating distance
	if (dist < 0)            // Check whether we travel in opposite direction
		dist *= -1.0;          // Convert into positive
	double cf;
	if (ticketClass == 1)
		cf = 0.25;             // Class 1 ticket costs 0.25
	else
		cf = 0.15;             // Class 2 ticket costs 0.15
	return dist * cf;        // Returning total price 
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	station railwayLine[100];
	int numberOfStations = readStations("london-cambridge.txt", railwayLine);
	int i;
	// Printing some ticket prices
	for (i = 1; i < numberOfStations;i ++) {
		double cost = ticketPrice(railwayLine, 0, i, 1);
		printf("The first class ticket price between 0 and %i is %f.\n", i, cost);
	}
	printf ("\n");
	for (i = 1;i < numberOfStations;i ++) {
		double cost = ticketPrice (railwayLine, i, 0, 2);
		printf("The second class ticket price between %i and 0 is %f.\n", i, cost);
	}
	return 0;
}