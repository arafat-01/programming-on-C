/*
 ============================================================================
 Name        : task2.c
 Author      : Arafat Bauyrzhanuly
 Version     :
 Copyright   : All rights reserved(2019)
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main () {
  setvbuf (stdout, NULL, _IONBF, 0);
  FILE *infile;
  FILE *outfile;
  infile = fopen ("cipher.txt", "r");              
  outfile = fopen ("plain.txt", "w");              
  if (infile == NULL) {                            // Check if file does not exist
    printf ("Problem opening input file.");
    return 1;
  }
  printf ("File opened successfully.\n");

  char c;
  _Bool Upper = 1;                      // Declaring boolean which will store information about whether we should print Upper Case letter or not
  
  while ((c = getc (infile)) != EOF) {                // Read characters until the end of file
    if (Upper == 1) {                                 // If current character should be upper case
      if (c >= '0' && c <= '9') Upper = 0;            // If it is digit, then we refresh boolean
      if (c >= 'A' && c <= 'Z') Upper = 0;            // If it is already upper case, then refresh it 
      if (c >= 'a' && c <= 'z') {                     // If it is not upper case letter
        c = c - 32;                                   // Convert to upper case letter
        Upper = 0;                                    // Refresh boolean
      }
    }              
    if (c >= 'a' && c <= 'z') {                //
      c = c - 3;                               //
      if (c < 'a') c = c + 26;                 //
    }                                          // DECRYPTING ENGLISH LETTERS
    if (c >= 'A' && c <= 'Z') {                //
       c = c - 3;                              //
       if (c < 'A') c = c + 26;                //
    } 
    if (c == '.' || c == '!' || c == '?') {    // If current character is ./?/! then next letter should be upper case letter
      Upper = 1;
    }
    putc (c, outfile);                         // Printing current character after changes made on it
  } 
 
  fclose (infile);                              // Closing input file
  fclose (outfile);                             // Closing output file
  return 0;
}
