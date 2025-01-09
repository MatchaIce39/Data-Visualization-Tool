#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getDimensions (const char *filename, int *rows) {

    FILE *fileptr = fopen(filename, "r");
    char line[256];
    *rows = 0;

    while (fgets(line, sizeof(line), fileptr)) {

        char *token = strtok(line, " "); //pointer to token
        char *lastToken = NULL;

        while (token != NULL) { //as long as there are more tokens, keep going
            //printf("Token: %s\n", token);
            //This line is just for debugging purposes
            lastToken = token;
            token = strtok(NULL, " "); //move forward
        }

        //printf("rows is: %d\n", *rows);
        (*rows)++;

    }

    return *rows;

}