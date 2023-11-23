#include <stdio.h>

void reverseArray(int arr[100], int arrLength) {
    for (int i = 0; i < (arrLength/2); i++) {
        int temp = arr[i];
        arr[i] = arr[i+(arrLength-1)];
        arr[i+(arrLength-1)] = temp;  
    }

    for (int i = 0; i < arrLength; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {1,2,3};
    reverseArray(arr, 3);
}