/*
 ============================================================================
 Name        : task4.c
 Author      : Arafat Bauyrzhanuly
 Version     :
 Copyright   : All rights reserved (2019)
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {  // Creating new data type called station
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
		fscanf(infile, "%lf %s", &line[n].km, line[n].name); // Reading input data from file
		n++;
	}
	return n;  // Return number of stations in input file
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
	while (1 > 0) {
		printf("List of available stations:\n");
		int i;
		for (i = 0; i < numberOfStations;i ++)
			printStation(railwayLine, i, 1);      // Printing list of available stations
		printf("Choose departure station number, please: "); // Prompt user to choose station number
		int start, finish;
		scanf("%i", &start);   // Reading from user departure station number
		printf("\n");
		for (i = 0; i < numberOfStations; i++)
			if (i != start)
				printStation(railwayLine, i, 1);   // Printing list of available stations for destination
		printf("Choose arrival station number, please: ");
		scanf("%i", &finish); // Reading from user destination station numebr 
		printf("\n");
		printf("The first class ticket for your trip is: %f.\n", ticketPrice(railwayLine, start, finish, 1));  // Print cost of 1-class ticket
		printf("The second class ticket for your trip is: %f.\n", ticketPrice(railwayLine, start, finish, 2)); // Print cost of 2-class ticket
		printf("Which ticket class would you like to buy? (1/2) Please, enter: "); // Prompt user to choose ticket class
		int ticketType;
		scanf("%i", &ticketType);  // Reading ticket's class
		printf("\n");
		printf("Departure station: ");
		printStation(railwayLine, start, 0);   // Printnig departure station
		printf("Destination station: ");
		printStation(railwayLine, finish, 0);  // Printing destination station
		printf("Ticket price: %.2f\n", ticketPrice(railwayLine, start, finish, ticketType));  // Printing cost of trip
		printf("Would you like to buy another ticket? (Y - Yes, N - No)\n");  // Prompt user whether to choose another ticket or not
		char buyTicket;
		buyTicket = getchar(); // Skipping '\n' character
		scanf("%c", &buyTicket);  // Reading choice of user
		if (buyTicket == 'N') {    // Check if user finished choosing ticket
			break;
		} // Otherwise continue process
	}
	return 0;
}