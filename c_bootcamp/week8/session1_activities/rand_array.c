#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a[3][4];
    int b[3][4];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }

    int c[3][4];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            c[i][j] = a[i][j] * b[i][j];
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

}