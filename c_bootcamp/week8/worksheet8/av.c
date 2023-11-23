#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize an array with random values
void initializeArrayRandom(int rows, int columns, int a[rows][columns]) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            a[row][col] = rand() % 25; // Generates random values between 0 and 10
        }
    }
}

// Function to print a 2D array
void printArray(int rows, int columns, int a[rows][columns]) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            printf("%d ", a[row][col]);
        }
        printf("\n");
    }
}

void sumMarks(int rows, int columns, int arr[rows][columns]) {
    int sum;
    for (int row = 0; row < rows; row++) {
        printf("Student %d: ", row+1);
        sum = 0;
        for (int col = 0; col < columns; col++) {
            sum += arr[row][col];
        }
        printf("%d\n", sum);
    }
}

void avMarks(int rows, int columns, int arr[rows][columns]) {
    int sum = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            sum += arr[row][col];
        }
    }
    printf("Average of total marks among all students: %d\n", sum/(rows-1));
}

int main() {
    int arr[4][5];

    // Seed the random number generator with the current time
    srand(time(NULL));

    initializeArrayRandom(4, 5, arr);

    printf("=== Student Marks ===\n");
    printArray(4, 5, arr);
    printf("======================\n");

    printf("=== Sum of marks for each student ===\n");
    sumMarks(4, 5, arr);
    printf("======================\n");

    printf("======================\n");
    avMarks(4, 5, arr);
    printf("======================\n");

    return 0;
}