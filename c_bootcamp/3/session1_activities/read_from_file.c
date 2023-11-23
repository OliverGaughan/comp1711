#include <stdio.h>
#include <stdlib.h> // Defines exit()

FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if  (file == NULL) {
        perror("File Not Found");
        exit(1);
    }
}

int main() {
    FILE *file = open_file("data.txt", "r");
    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%s", line_buffer);
    }

    fclose(file);
    return 0;
}