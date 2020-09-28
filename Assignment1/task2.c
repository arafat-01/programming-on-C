/*
 ============================================================================
 Name        : task2.c
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
  int n;
  scanf ("%d", &n); // Reading input
  int rev_n = 0;    // Declaring variable which stores reversed n
  int x = n;      // Declaring variable which helps to not loose value of original n
  int dig;      // Declaring variable which stores last digit of number
  int leading_zeros = 0; // Declaring variable which stores how many leading zeros have reversed n
  _Bool was = 0;
  do {
        dig = x % 10; // Saving last digit of number
        if (dig == 0 && was == 0) leading_zeros ++;    // Counting leading zeros of reversed n
        else was = 1;                                  // if dig is not 0, then next dig will not be considered as leading zero
        rev_n = (rev_n * 10) + dig;  // Calculating reversed number
        x /= 10;    // Deleting last digit
    } while (x != 0);
  
  if (n == 0) {                                     // Considering corner case when n equals 0
    printf ("number: 0, reverse: 0, palindrome.");
    return 0;
  }

  printf ("number: %d, reverse: ", n);                 
  
  int i;
  for (i = 1;i <= leading_zeros;i ++) printf ("0");  // Printing leading zeros reversed n if there are
  printf ("%d, ", rev_n); 

  if (n == rev_n) printf ("palindrome.");
  else printf ("Not palindrome.");

  return 0;
}
