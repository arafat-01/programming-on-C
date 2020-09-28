/*
 ============================================================================
 Name        : task3.c
 Author      : Arafat Bauyrzhanuly
 Version     :
 Copyright   : All rights reserved(2019)
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>

typedef struct {
  int xcoor;
  int ycoor;
  char name[30];
} city;

int main () {
  setvbuf (stdout, NULL, _IONBF, 0);
  FILE *infile;
  infile = fopen ("cities.txt", "r");              
  if (infile == NULL) {                            // Check if file does not exist
    printf ("Problem opening input file.");
    return 1;
  }
  printf ("File opened successfully.\n");

  city a[30];                                     // Declaring array of cities
  int n = 0;                                      // Declaring variable which will store the number of cities
  while (fscanf (infile, "%i %i %s", &a[n].xcoor, &a[n].ycoor, a[n].name) == 3) {  // Reading input datat from cities.txt
    n ++;                                                                          // Increase number of cities by 1
  }
  int i, j;                                           // Declaring variables which will iterate over pairs (i, j)
  double current_distance;                            // Declaring variable which will store distance between pair (i, j)
  double minimal_distance;                            // Declaring variable which will store the shortest distance between pair (i, j)
  double x_diff;                                      // Declaring variable which will store x-coordinates difference between pair (i, j)
  double y_diff;                                      // Declaring variable which will store y-coordinates difference between pair (i, j)
  int first_city;                                     // Declaring variable which will store number of first city of answer
  int second_city;                                    // Declaring variable which will store number of second city of answer

  x_diff = a[0].xcoor - a[1].xcoor;                               //
  y_diff = a[0].ycoor - a[1].ycoor;                               //  INITIAL SETUP FOR ALL VARIABLES ABOVE
  current_distance = sqrt (x_diff * x_diff + y_diff * y_diff);    //  ASSUMING THAT MINIMAL DISTANCE IS 
  minimal_distance = current_distance;                            //  BETWEEN PAIR (0, 1)
  first_city = 0;                                                 //  
  second_city = 1;                                                //


  for (i = 0;i < n;i ++) {                            // Iterating over first city 'i'
    for (j = 0;j < i;j ++) {                          // Iterating over second city 'j'
      x_diff = a[i].xcoor - a[j].xcoor;               // Calculating x-coordinates' difference
      y_diff = a[i].ycoor - a[j].ycoor;               // Calculating y-coordinates' difference
      current_distance = sqrt (x_diff * x_diff + y_diff * y_diff);  // Calculating current distance between cities (i, j)   
      if (current_distance < minimal_distance) {                    // If we found distance which smaller than our minimal distance, then we should update it
        minimal_distance = current_distance;                        //
        first_city = i;                                             // UPDATING OUR ANSWERS
        second_city = j;                                            //
      }
    }  
  }
  printf ("Minimum distance is: %g, Between %s and %s", minimal_distance, a[first_city].name, a[second_city].name);   // Printing answer
  fclose (infile);                                                  // Closing input file
  return 0;
}
