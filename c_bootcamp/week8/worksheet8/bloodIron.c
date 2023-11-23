#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    float value;
} BloodIron;

// Declare recordCount variable to store the number of records in the data file in global scope
int recordCount = 0;

BloodIron bloodIronArr[1000];

// Function to print a 2D array
void printArray(int rows, int columns, float a[rows][columns]) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            printf("%f\t", a[row][col]);
        }
        printf("\n");
    }
}

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, float *value) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
    } else {
        printf("Error: invalid file\n");
        exit(1);
    }
    ptr = strtok(NULL, &delimiter);
    if (ptr != NULL) {
        *value = atof(ptr);
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

int read_data() {
    // Declare variable to hold the filename input from user
    char filename[100];
    // Print prompt for user to input
    printf("Enter Filename: ");
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
        float Nvalue;

        // Run the tokeniseRecord() function on the data (record) on the current line
        tokeniseRecord(line_buffer, ',', Ndate, &Nvalue);

        // Add the date, time and steps to the next index in the array
        strcpy(bloodIronArr[recordCount].date, Ndate);
        bloodIronArr[recordCount].value = Nvalue;

        // Increase count of records
        recordCount += 1;

    }
    // Display that the file has been loaded
    // printf("File successfully loaded.\n");
    // Close the file
    fclose(file);
    return 0;
}

int main() {
    read_data();

    for (int i = 0; i < recordCount; i++) {
        printf("%s %f\n", bloodIronArr[i].date, bloodIronArr[i].value);
    }

    float arr[5][recordCount];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < recordCount; j++) {
            arr[i][j] = 0.0;
        }
    }

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;

    for (int i = 0; i < recordCount; i++) {
        if (bloodIronArr[i].value > 10.9 && bloodIronArr[i].value < 12) {
            arr[0][count1] = bloodIronArr[i].value;
            count1++;
        } else if (bloodIronArr[i].value > 11.9 && bloodIronArr[i].value < 13) {
            arr[1][count2] = bloodIronArr[i].value;
            count2++; 
        } else if (bloodIronArr[i].value > 12.9 && bloodIronArr[i].value < 14) {
            arr[2][count3] = bloodIronArr[i].value;
            count3++;
        } else if (bloodIronArr[i].value > 13.9 && bloodIronArr[i].value < 15) {
            arr[3][count4] = bloodIronArr[i].value;
            count4++;
        } else if (bloodIronArr[i].value > 14.9 && bloodIronArr[i].value < 16) {
            arr[4][count5] = bloodIronArr[i].value;
            count5++;
        }
    }

    printArray(5, recordCount, arr);

    return 0;
}