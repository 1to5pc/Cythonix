#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int clearFile() {
    FILE *filePointer = fopen("convert.c", "w");
    if (filePointer == NULL) {
        printf("Could not open convert.c to clear.\n");
        return -1; 
    }
    fprintf(filePointer, "\n");
    fclose(filePointer);
    return 0;
}

const char* getCode(FILE *PyPointer) {
    if (PyPointer == NULL) {
        printf("No file found.\n");
        return "\n";
    }

    fseek(PyPointer, 0, SEEK_END);
    long file_size = ftell(PyPointer);
    fseek(PyPointer, 0, SEEK_SET);

    if (file_size == 0) {
        printf("The convert.c is empty.\n");
        return "\n";
    }

    if (clearFile() != 0) {
        return "\n"; 
    }

    char line[255];
    while (fgets(line, sizeof(line), PyPointer)) {
        outPy(line);
    }

    return "\n";
}

int outPy(char line[255]) {
    FILE *PyPointer = fopen("convert.c", "r+");  
    if (PyPointer == NULL) {
        PyPointer = fopen("convert.c", "w+");
        if (PyPointer == NULL) {
            printf("Could not open convert.c\n");
            return -1;
        }
    }

    fseek(PyPointer, 0, SEEK_END);  
    if (ftell(PyPointer) !  ) {    
        fprintf(PyPointer, "#include <stdio.h>\n");
    }

    fseek(PyPointer, 0, SEEK_END);

    if (strncmp(line, "print(", 6) == 0) {
        int i = 6;
        int tmp = 0;
        char argument[200];

        while (line[i] != ')' && line[i] != '\0' && tmp < sizeof(argument) - 1) {
            if (line[i] != '\n') {
                argument[tmp++] = line[i];
            }
            i++;
        }

        argument[tmp] = '\0';

        if (argument[0] == '"' && argument[tmp - 1] == '"') {
            memmove(argument, argument + 1, tmp - 1);
            argument[tmp - 2] = '\0'; 
        }

        for (int j = 0; j < tmp; j++) {
            if (argument[j] == '\'') {
                memmove(argument + j, argument + j + 1, tmp - j); // Shift left
                tmp--; 
                j--; 
            }
        }

        fprintf(PyPointer, "printf(\"%%s\\n\", \"%s\");\n", argument);
        printf("Code generated successfully.\n");
    }

    fclose(PyPointer);
    return 0;
}

int readPy();
