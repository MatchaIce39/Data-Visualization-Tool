#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getDimensions (const char *filename, int *rows) {

    FILE *fileptr = fopen(filename, "r");
    char line[256];
    *rows = 0;

    printf("%d/n", *rows);

    while (fgets(line, sizeof(line), fileptr)) {

        char *token = strtok(line, " "); //pointer to token
        char *lastToken = NULL;

        while (token != NULL) { //as long as there are more tokens, keep going
            printf("Token: %s\n", token); //this is the token
            lastToken = token;
            token = strtok(NULL, " "); //move forward
        }

        *rows++;

    }

}

int main() { 
    int rows, cols, maxWordLength; 
    getDimensions("data2.txt", &rows); 

    printf("Max Rows: %d\n", rows); 
    printf("This should be 9 or 10 I think");

    return 0; 
    }