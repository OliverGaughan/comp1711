#include <stdio.h>

int main() {
    int array[5] = {0, 1, 2, 3, 4};
    int arrayLen = 5;
    int last = array[arrayLen-1];

    for (int i=arrayLen-1; i > 0;i--) {
        array[i] = array[i-1];
    }

    array[0] = last;

    for (int i=0; i < arrayLen; i++) {
        printf("%d\n", array[i]);
    }
}