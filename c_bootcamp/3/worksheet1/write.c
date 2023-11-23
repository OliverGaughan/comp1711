#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if  (file == NULL) {
        perror("File Not Found");
        exit(1);
    }
}

int main() {
    FILE *file = open_file("squares.dat", "w");
    
    int n;
    printf("Enter an number: ");
    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++) {
        int square = i*i;
        fprintf(file, "%d\n", square);
        printf("Added square of %d to file\n", i);
    }

    fclose(file);
    exit(0);
}