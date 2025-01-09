#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COLS 50 //this is how much each can hold
#define MAX_ROWS 10 //This is the amount of actual lines in the text file

int getDimensions(const char *filename, int *rows);

void swap(char str1[], char str2[]) {
    char temp[MAX_COLS];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);

}

void bubbleSort(char arr[][MAX_COLS], int length){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - 1; j++){
            if(strcmp(arr[j], arr[j + 1]) > 0) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

}

int main(void) {

    char heights[MAX_ROWS][MAX_COLS];
    int length = sizeof(heights) / sizeof(heights[0]);

    FILE *fileptr;
    char line[256];
    int i = 0;
    //Opening the file with fopen and putting it
    //in read only mode
    fileptr = fopen("data2.txt", "r");

    if (fileptr == NULL) { 
        printf("Error opening file\n"); 
        return 1; 
    } 

    while (fgets(line, sizeof(line), fileptr)) {

        line[strcspn(line, "\n")] = 0; //This will remove the the extra white space when using strtok

        char *token = strtok(line, " "); //pointer to token
        char *lastToken = NULL;

        while (token != NULL) { //as long as there are more tokens, keep going
            //printf("Token: %s\n", token); //this is the token
            lastToken = token;
            token = strtok(NULL, " "); //move forward
        }

        if (lastToken != NULL) {
            //printf("Last Token: %s\n", lastToken);
            strncpy(heights[i], lastToken, sizeof(heights[i]) - 1);
            heights[i][sizeof(heights[i]) - 1] = '\0';
            //printf("i is equal to:  %d\n", i);
        }

        i++;
    }

    fclose(fileptr);
    int n = 10;

    /*
    printf("Before sorting:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("%s\n", heights[i]);
    }
    */

    bubbleSort(heights, n);

    /*
    printf("\n");
    printf("After sorting:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("%s\n", heights[i]);
    }
    */

    FILE *sortedFile = fopen("Sorted_Data.csv", "w");

    if(sortedFile == NULL){
        printf("ERROR\n");
        return 1;
    }

    for (int b = 0; b < length; b++){
        fprintf(sortedFile, "%d, %s\n", b, heights[b]);
    }

    fclose(sortedFile);
    printf("Data was read and written to sorted_data.csv\n");
    return 0;

}