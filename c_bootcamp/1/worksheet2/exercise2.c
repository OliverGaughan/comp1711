#include <stdio.h>

int main() {
    int array[5] = {0, 1, 2, 3, 4};
    int arrayLen = 5;
    int temp;

    for (int i=0; i < arrayLen/2; i++) {
        temp = array[i];
        array[i] = array[arrayLen-i-1];
        array[arrayLen-i-1] = temp;
    }

    for (int i=0; i < arrayLen; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}