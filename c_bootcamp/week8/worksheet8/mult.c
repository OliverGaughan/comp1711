#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize an array with random values
void initializeArrayRandom(int rows, int columns, int a[rows][columns]) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            a[row][col] = rand() % 100; // Generates random values between 0 and 10
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

int main() {
    int arr[2][3];
    int transArr[3][2];

    // Seed the random number generator with the current time
    srand(time(NULL));

    initializeArrayRandom(2, 3, arr);

    printArray(2, 3, arr);

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            transArr[col][row] = arr[row][col];
        }
    }

    printArray(3, 2, transArr);

    return 0;
}