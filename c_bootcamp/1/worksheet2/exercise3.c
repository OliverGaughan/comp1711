#include <stdio.h>

int main() {
    int array[5] = {0, 1, 2, 3, 4};
    int arrayLen = 5;
    int largest = 0;

    for (int i=0; i < arrayLen; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }

    printf("%d\n", largest);
    
    return 0;
}