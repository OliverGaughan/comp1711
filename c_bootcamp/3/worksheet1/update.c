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
    FILE *file = open_file("numbers.dat", "r");    
    
    float total = 0;
    int amount = 0;
    float number;
    float average;

    printf("=== File Contents Before ===\n");

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%s", line_buffer);
        number = atof(line_buffer);
        total += number;
        amount += 1;
    }

    average = total/amount;

    fclose(file);


    file = open_file("numbers.dat", "a+");    

    fprintf(file, "%f\n", average);
    printf(":> Added %f to file\n", average);

    fclose(file);
    exit(0);
}