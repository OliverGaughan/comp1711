#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize an array with random values
void initializeArrayRandom(int a[2][3][4]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int l = 0; l < 4; l++) {
                a[i][j][l] = rand() % (100 + 1 - 70) + 70;
            }
        }
    }
}

int main() {
    int arr[2][3][4];
    initializeArrayRandom(arr);
    for (int i = 0; i < 2; i++) {
        printf("Semester %d:\n", i+1);
        for (int j = 0; j < 3; j++) {
            printf("Student %d:\n", j+1);
            for (int l = 0; l < 4; l++) {
                printf("Module %d mark = %d\n", l+1, arr[i][j][l]);
            }
        }
    }
    
}