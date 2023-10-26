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
    FILE *file = open_file("input.txt", "r");
    int buffer_size = 100;
    char line_buffer[buffer_size];

    int arr[1000];
    int lineCounter = 0;

    while (fgets(line_buffer, buffer_size, file) != NULL) {
        int num = atoi(line_buffer);
        arr[lineCounter] = num;
        lineCounter += 1;
    }

    arr[lineCounter] = '\0';

    int count = 0;
    int GT1000 = 0;

    while (arr[count] != '\0') {
        printf("%d\n", arr[count]);
        if (arr[count] > 1000) {
            GT1000 += 1;
            // printf("%d is also greater than 1000.\n", arr[count]);
        }
        count += 1;
    }

    printf("Numbers greater than 1000 counter: %d\n", GT1000);

    fclose(file);
    return 0;
}