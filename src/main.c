#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

extern const char* getCode(FILE *PyPointer);

int readPy(int argc, char *argv[]); 

int main(int argc, char *argv[]) {
  readPy(argc, argv);
  return 0;
}

int readPy(int argc, char *argv[]) {
  FILE * PyPointer = fopen(argv[1], "r");
  if (PyPointer == NULL) {
    printf("could not read specified file\n");
    return -1;
  }
  getCode(PyPointer);
  fclose(PyPointer);
  return 0;
}
