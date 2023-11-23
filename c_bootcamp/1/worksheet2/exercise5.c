#include <stdio.h>

int main() {
    int array[6] = {0, 2, 2, 3, 2, 3};
    int duplicates[6];
    int arrayLen = 6;
    int overallCounter = 0;

    for (int i=0; i < arrayLen; i++) {
        int counter = 0;
        int current = array[i];

        for (int j=0; j < arrayLen; j++) {
            if (current == duplicates[j]) {
                i += 1;
                j = arrayLen;
            }
        }

        for (int j=1; j < arrayLen; j++) {
            if (current == array[j]) {
                counter += 1;
            }
        }

        if (counter > 1) {
            printf("%d is duplicated %d times!\n", current, counter);
            duplicates[overallCounter] = current;
            overallCounter += 1;
        }
    }

    if (overallCounter < 1) {
        printf("No Duplicates Found!\n");
    }

    return 0;
}