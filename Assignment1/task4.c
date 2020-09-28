/*
 ============================================================================
 Name        : task4.c
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
	int k;
	do {
		scanf ("%d", &k); // Reading input
		int i, j;
		for (i = 1;i <= k;i ++) { // Loop iterating over lines
			for (j = 1;j <= i;j ++) { // Loop iterating over numbers in current line i
				printf ("%d ", j); // Printing current line's numbers
			}
			printf ("\n");  // Switching to the next line
		}
	} while (k > 0);  // If k is negative or zero, finish the program

	return 0;
}
