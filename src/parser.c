#include "parser.h"
#include <stdio.h>
#include <string.h>

int clearFile() {
  FILE * filePointer = fopen("convert.c", "w");
  fprintf(filePointer, "\n");
  fclose(filePointer);
  return -1;
}

const char* getCode(FILE *PyPointer) {;
  fseek(PyPointer, 0, SEEK_END);
  long file_size = ftell(PyPointer);
  fseek(PyPointer, 0, SEEK_SET);
  char line[255];
  for (int i = 1; i < 255; i++) {
    if (file_size == 0) {
      printf("The convert.c is empty.\n");
      return "\n";
    } else if (PyPointer == NULL) {
      printf("No file found.\n");
      return "\n";
    } else {
      clearFile();
      while (fgets(line, sizeof(line), PyPointer)) {
        outPy(line);
      }
      break;
    }
  }
  return "\n";
}

int outPy(char line[255]) {
  FILE * PyPointer = fopen("convert.c", "a");
  if (PyPointer == NULL) {
    printf("Could not open convert.c \n");
    return -1;
  }
  char *arguments[200];
  if (strncmp(line, "print(", 6) == 0) {
    int i = 6;
    int tmp = 0;
    char argument[200];

    while (line[i] != ')' && line[i] != '\0') {
            if (line[i] != '\n' && line[i] != ' ') {
                argument[tmp++] = line[i];
           }
           i++;
    }
    arguments[tmp] = '\0';
    fprintf(PyPointer, "printf(\"%%s\", %.*s);\n", tmp, line + 6);
    printf("Code generated successfully. \n");

  }
  fclose(PyPointer);
  return 0;
}

int readPy() {
  FILE * PyPointer = fopen("app.py", "r");
  if (PyPointer == NULL) {
    printf("Could not open app.py for reading.\n");
    return -1;
  }
  getCode(PyPointer);
  fclose(PyPointer);
  return 0;
}
