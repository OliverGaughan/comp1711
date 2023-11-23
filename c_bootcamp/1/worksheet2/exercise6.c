#include <stdio.h>

int main() {
    int array1[3] = {0, 1, 2};
    int array2[3] = {3, 4, 5};

    int array1Len = 3;
    int array2Len = 3;    

    int concatenatedArray[array1Len+array2Len];

    for (int i=0; i < array1Len; i++) {
        concatenatedArray[i] = array1[i];
    }

    for (int i=0; i < array2Len; i++) {
        concatenatedArray[i+array1Len] = array2[i];
    }

    for (int i=0; i < sizeof(concatenatedArray); i++) {
        printf("%d\n", concatenatedArray[i]);
    }
}