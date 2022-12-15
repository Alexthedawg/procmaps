#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE "usage: ./procmaps [PROC_NUMBER]"

// prints error message and exits program
void errexit (const char *msg) {
  printf ("%s\n", msg);
  exit (EXIT_FAILURE);
}

// prints .so files of specified PROC_NUMBER - if PROC_NUMBER is negative, searches all proc/nnn/maps
void printso (const int procn) {
  
  // grepping all .so files from /proc/nnn/maps, since no specific pid requested
  if (procn == -1) {
    system ("ls /proc | grep -E '\\.so'  $(sed -En 's/([0-9]+)/\\/proc\\/\\1\\/maps/p')");
  }
  
  // if a pid is specified, grep the .so files from /proc/[pid]/maps
  if (procn != -1) {
    char command [strlen ("grep -E '\\.so' /proc/%d/maps") *2];
    sprintf (command, "grep -E '\\.so' /proc/%d/maps", procn);
    system (command);
  }
}


// parses CL argument prints the .so objects
int main (int argc, char **argv) {
  int procn = -1;
  
  // validate correct num or arguments: should be './procmaps PROC_NUMBER'
  if (argc != 1 && argc != 2)
    errexit (USAGE);
  
  // if specified, store proc number
  if (argc == 2) {
    procn = atoi (argv[1]);
    
    // checking return status of atoi
    if (procn == 0)
      errexit ("Error Parsing PROC_NUMBER for Integer.\n");
    
  }
  
  // print .so objects
  printso (procn);
  
  exit (EXIT_SUCCESS);
}
