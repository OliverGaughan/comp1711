#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
int maxRecords = 1000;


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

// Complete the main function
int main() {
    // Open the file as read
    FILE *file = fopen("FitnessData_2023.csv", "r");
    // If there is an error opening the file, return error message and exit program
    if  (file == NULL) {
        perror("File Not Found");
        exit(1);
    }

    // Declare variables for file reading process
    int buffer_size = 100;
    char line_buffer[buffer_size];

    // Declare array of typedef struct "FITNESS_DATA" with the length of "maxRecords" variable
    FITNESS_DATA fitnessDataArray[maxRecords];
    // Declare count variable for records
    int recordCount = 0;

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

    // Print the number of records in thr CSV file to the screen
    printf("Number of records in file: %d\n", recordCount);

    // Loop through and print the first 3 records in the array
    printf("First 3 records:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s/%s/%d\n", fitnessDataArray[i].date, fitnessDataArray[i].time, fitnessDataArray[i].steps);
    }

    // Close the file and exit the program
    fclose(file);
    exit(0);
}
