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
    FILE *file = open_file("squares.dat", "r");
    
    float total;
    int amount;

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%s", line_buffer);
        float number = atoi(line_buffer);
        total += number;
        amount += 1;
    }

    float average = total/amount;
    printf("The average of all %d numbers is %f\n", amount, average);

    fclose(file);
    return 0;
}