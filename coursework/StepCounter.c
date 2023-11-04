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
    // If file is found, return the file
    return file;
}

void optionA() {
    // Declare variable to hold the filename input from user
    char filename[100];
    // Print prompt for user to input
    printf("Input filename:");
    // Store user input in filename variable
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

    }
    // Close the file
    fclose(file);
}

void optionC() {
    // Declare variable to hold the index of the record with the minimum steps
    int minimumRecordIndex;
    // Declare variable to hold the current minimum steps found (starting at the largest possible value)
    int minimumSteps = __INT_MAX__;

    // Loop through all elements (records) in the array...
    for (int i=0; i < recordCount; i++) {
        // Declare variable that stores the current elements step count
        int current = fitnessDataArray[i].steps;
        // If the current records steps is less than the minimum steps variable...
        if (current < minimumSteps) {
            // Change the value of minimum steps variable to the current record's step count
            minimumSteps = current;
            // Store the index of the current element/record in minimum record index variable
            minimumRecordIndex = i;
        }
    }
    // Print the fewest steps record's date and time
    printf("Fewest steps: %s %s\n", fitnessDataArray[minimumRecordIndex].date, fitnessDataArray[minimumRecordIndex].time);
}

void optionD() {
    // Declare variable to hold the index of the record with the maximum steps
    int maxRecordIndex;
    // Declare variable to hold the current maximum steps found (starting at 0)
    int maxSteps = 0;

    // Loop through all elements (records) in the array...
    for (int i=0; i < recordCount; i++) {
        // Declare variable that stores the current elements step count
        int current = fitnessDataArray[i].steps;
        // If the current records steps is more than the maximum steps variable...
        if (current > maxSteps) {
            // Change the value of maximum steps variable to the current record's step count
            maxSteps = current;
            // Store the index of the current element/record in maximum record index variable
            maxRecordIndex = i;
        }
    }
    // Print the largest steps record's date and time
    printf("Largest steps: %s %s\n", fitnessDataArray[maxRecordIndex].date, fitnessDataArray[maxRecordIndex].time);
}

void optionE() {
    // Declare variable to store the total number of steps across all records
    int totalSteps;

    // Loop through all elements (records) in the array...
    for (int i=0; i < recordCount; i++) {
        // Update the total steps counter by the current records step count
        totalSteps += fitnessDataArray[i].steps;
    }

    // Store the mean (total number of steps divided by the total nubmer of records) in a variable
    int meanSteps = totalSteps/recordCount;

    // Print the mean step count
    printf("Mean step count: %d\n", meanSteps);
}

void optionF() {
    // Declare variables to store the index of the starting and ending record in the overall longest continuous period 
    int longestStart = 0;
    int longestEnd = 0;

    // Declare variables to store the index of the starting and ending record in the current continuous period being tracked 
    int currentStart;
    int currentEnd;

    // Loop through all elements (records) in the array...
    for (int i=0; i < recordCount; i++) {
        // If the current record's step count is over 500...
        if (fitnessDataArray[i].steps > 500) {
            // Set the current start variable to the index of the current record
            currentStart = i;
            // Increment the i counter to point to the next index/record
            i += 1;
            // While the step count of the current index/record is greater than 500...
            while (fitnessDataArray[i].steps > 500) {
                // Increment the i counter to point to the next index/record
                i += 1;
            }

            // Set the current end variable to the last index/record that had a step count of over 500 in the continuous period 
            currentEnd = i-1;
            
            // If the current continuous period is greater than the overall continuous period...
            if ((currentEnd-currentStart) > (longestEnd - longestStart)) {
                // Update the indexes/values of the overall longest continuous period variables to the current ones
                longestStart = currentStart;
                longestEnd = currentEnd;
            }
        }
    }

    // Print the longest period start and end dates and times
    printf("Longest period start: %s %s\nLongest period end: %s %s\n", fitnessDataArray[longestStart].date, fitnessDataArray[longestStart].time, fitnessDataArray[longestEnd].date, fitnessDataArray[longestEnd].time);
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
            case 'E':
            case 'e':
                optionE();
                break;
            case 'F':
            case 'f':
                optionF();
                break;
            default:  break;
        }
    } while (option != 'Q' && option != 'q');

    exit(0);
}
