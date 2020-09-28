/*
 ============================================================================
 Name        : task1.c
 Author      : Arafat Bauyrzhanuly
 Version     :
 Copyright   : All rights reserved(2019)
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main () {
  setvbuf (stdout, NULL, _IONBF, 0);

  printf ("Please, enter size of matrixes: ");
  int n;        // Size of given matrixes
  scanf ("%i", &n);     // Reading input data
  if (n <= 0) {      // If n is not positive, then input data is incorrect
    printf ("Please, provide positive value.");
    return 0;
  }

  int a[n][n]; // Declaring 2-d array for matrix a
  int b[n][n]; // Declaring 2-d array for matrix b
  int c[n][n]; // Declaring 2-d array for matrix c, which stores result matrix

  int i, j, k;   // Declaring variables which are used to iterate over matrix dimensions
  printf ("Please, enter matrix a:\n");
  for (i = 0;i < n;i ++) {
    for (j = 0;j < n;j ++) {
      scanf ("%i", &a[i][j]);    // Reading matrix a
    }
  }
  printf ("Please, enter matrix b:\n");
  for (i = 0;i < n;i ++) {
    for (j = 0;j < n;j ++) {
      scanf ("%i", &b[i][j]);    // Reading matrix b
    }
  }
  for (i = 0;i < n;i ++) {
    for (j = 0;j < n;j ++) {
      c[i][j] = 0;      // Initializing value of c[i][j]
      for (k = 0;k < n;k ++) {   // Iterating over common dimension of matrix a and b
        c[i][j] += a[i][k] * b[k][j]; // Adding up multiplication of a[i][k] with b[k][j]
      }
    }
  }
  printf ("RESULT C: \n");
  for (i = 0;i < n;i ++) {
    for (j = 0;j < n;j ++) {
      printf ("%i ", c[i][j]);   // Printing answer
    }
    printf ("\n");       // Switching to the new line
  }
  return 0;
}
