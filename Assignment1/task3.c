/*
 ============================================================================
 Name        : task3.c
 Author      : Arafat Bauyrzhanuly
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main () {
	setvbuf(stdout, NULL, _IONBF, 0);
	double x;
	int k;
	scanf ("%lf %d", &x, &k);
	x = x * 3.14159 / 180.0; // Converting into radians
	int i;				 // Declaring variable of for loop
	double power_of_x = 1;	 // Declaring variable which stores some power of x
	double factorial = 1; 	 // Declaring variable which stores factorial
	int sign = 1;
	double ans = 0; 		// Declaring variable which stores answer to the problem
	for (i = 1;i <= 2 * k + 1;i ++) {
		power_of_x *= x;	 // Computing x^i
		factorial *= i; 	 // Computing i!
		if (i % 2 == 0) continue;	// According to formula, we don't need to do anything with even numbers
		ans += sign * (power_of_x / factorial);
		if (sign == 1) sign = -1;	// Changing sign for the next adding number
		else sign = 1;
	}
	printf ("%f", ans);			// Printing answer to the task

	return 0;
}
