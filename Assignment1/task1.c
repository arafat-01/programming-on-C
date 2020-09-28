/*
 ============================================================================
 Name        : task1.c
 Author      : Arafat Bauyrzhanuly
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	int k;
	while (1) {
		scanf ("%d", &k);   // Reading input k
		if (k <= 0) break;  // Finish the program if K is negative or zero
		double e = 0;		// Declaring variable which computes e
		double i = 1;		// Declaring variable of for loop
		double factorial = 1; // Declaring variable which stores factorial number
		for (i = 1;i <= k;i ++) {
			e += (1.0/factorial);  // Adding up 1/(i!) to the answer
			factorial *= i; 		// Computing next value of factorial number
		}
		printf ("%f\n", e);
	}
	return 0;
}
