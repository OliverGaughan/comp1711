#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "FitnessDataStruct.h"


// Define any additional variables here

// Declare array of typedef struct "FITNESS_DATA" with the length of "maxRecords" variable
FITNESS_DATA fitnessDataArray[1000];
// Declare recordCount variable to store the number of records in the data file in global scope
int recordCount = 0;


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

FILE *open_file(char filename[], char mode[]) {
    // Open the specified file with specified mode
    FILE *file = fopen(filename, mode);
    // If there is an error opening the file, return error message and exit program
    if  (file == NULL) {
        perror("File Not Found");
        exit(1);
    }
    return file;
}

void optionA() {

    char filename[100];

    printf("Input filename:");
    scanf("%s", filename);

    // Open the file as read
    FILE *file = open_file(filename, "r");

    // Declare variables for file reading process
    int buffer_size = 100;
    char line_buffer[buffer_size];

    // Loop until the end of the file is reached...
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        // Declare new variables to retrieve the tokenised date, time and steps from the tokeniseRecord() function
        char Ndate[11];
        char Ntime[6];
        char Nsteps[100];

        // Run the tokeniseRecord() function on the data (record) on the current line
        tokeniseRecord(line_buffer, ",", Ndate, Ntime, Nsteps);

        // Add the date, time and steps to the next index in the array
        strcpy(fitnessDataArray[recordCount].date, Ndate);
        strcpy(fitnessDataArray[recordCount].time, Ntime);
        fitnessDataArray[recordCount].steps = atoi(Nsteps);

        // Increase count of records
        recordCount += 1;

        // Close the file and exit the program
    }
    fclose(file);
}

void optionC() {
    int minimumRecordIndex;
    int minimumSteps = __INT_MAX__;

    for (int i=0; i < recordCount; i++) {
        int current = fitnessDataArray[i].steps;
        if (current < minimumSteps) {
            minimumSteps = current;
            minimumRecordIndex = i;
        }
    }
    printf("Fewest steps: %s %s\n", fitnessDataArray[minimumRecordIndex].date, fitnessDataArray[minimumRecordIndex].time);
}

void optionD() {
    int maxRecordIndex;
    int maxSteps = 0;

    for (int i=0; i < recordCount; i++) {
        int current = fitnessDataArray[i].steps;
        if (current > maxSteps) {
            maxSteps = current;
            maxRecordIndex = i;
        }
    }
    printf("Largest steps: %s %s\n", fitnessDataArray[maxRecordIndex].date, fitnessDataArray[maxRecordIndex].time);
}

// Complete the main function
int main() {
    char option;

    do {
        printf("Select from the following options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit the program\n");

        scanf(" %c", &option);

        switch(option)
        {
            case 'A':
            case 'a':
                // Run the function for option A
                optionA();
                break;
            case 'B':
            case 'b':
                // Print the number of records in thr CSV file to the screen
                printf("Total records: %d\n", recordCount);
                break;
            case 'C':
            case 'c':
                optionC();
                break;
            case 'D':
            case 'd':
                optionD();
                break;
            default:  break;
        }
    } while (option != 'Q' && option != 'q');

    exit(0);
}
