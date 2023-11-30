#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Declare array of typedef struct "FITNESS_DATA" with the length of "maxRecords" variable
FitnessData fitnessDataArray[1000];
// Declare recordCount variable to store the number of records in the data file in global scope
int recordCount = 0;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL && ptr[4] == '-' && ptr[7] == '-' && ptr[10] == '\0') {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
    } else {
        printf("Error: invalid file\n");
        exit(1);
    }
    if (ptr != NULL && ptr[2] == ':' && ptr[5] == '\0') {
        strcpy(time, ptr);
        ptr = strtok(NULL, &delimiter);
    } else {
        printf("Error: invalid file\n");
        exit(1);
    }
    if (ptr != NULL && ptr[1] != '\0') {
        *steps = atoi(ptr);
    } else {
        printf("Error: invalid file\n");
        exit(1);
    }
}

FILE *open_file(char filename[], char mode[]) {
    // Open the specified file with specified mode
    FILE *file = fopen(filename, mode);
    // If there is an error opening the file, return error message and exit program
    if  (file == NULL) {
        printf("Error: invalid file\n");
        exit(1);
    }
    // If file is found, return the file
    return file;
}

int read_data(char filename[]) {
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
        int Nsteps;

        // Run the tokeniseRecord() function on the data (record) on the current line
        tokeniseRecord(line_buffer, ',', Ndate, Ntime, &Nsteps);

        // Add the date, time and steps to the next index in the array
        strcpy(fitnessDataArray[recordCount].date, Ndate);
        strcpy(fitnessDataArray[recordCount].time, Ntime);
        fitnessDataArray[recordCount].steps = Nsteps;

        // Increase count of records
        recordCount += 1;

    }
    // Close the file
    fclose(file);
    return 0;
}

int main() {

    // Declare variable to hold the filename input from user
    char filename[100];
    // Print prompt for user to input
    printf("Enter Filename: ");
    // Store user input in filename variable
    scanf("%s", filename);

    read_data(filename);

    FitnessData temp;
    for (int i=0; i < recordCount; i++) {
        for (int j=0; j < recordCount; j++) {
            if (fitnessDataArray[i].steps > fitnessDataArray[j].steps) { 
                temp = fitnessDataArray[i]; 
                fitnessDataArray[i] = fitnessDataArray[j]; 
                fitnessDataArray[j] = temp; 
            } 
        }
    }

    strcat(filename, ".tsv");

    FILE *file = open_file(filename, "w+");

    for (int i=0; i < recordCount; i++) {
        fprintf(file, "%s\t%s\t%d\n", fitnessDataArray[i].date, fitnessDataArray[i].time, fitnessDataArray[i].steps);
    }

    fclose(file);

    printf("Data sorted and written to %s\n", filename);

    exit(0);
}