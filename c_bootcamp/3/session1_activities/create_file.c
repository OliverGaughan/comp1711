#include <stdio.h>

// r = read file
// w = write to file (create file if necessary)
// a = append to file (create file if necessary)
// r+ = read and write, from beginning
// w+ read and write, overwriting
// a+ = read and write, appending

int main() {
    char filename[] = "data.txt";
    FILE *file = fopen(filename, "w");
    if  (file == NULL) {
        perror("File Not Found");
        return 1;
    }

    fclose(file);
    return 0;
}