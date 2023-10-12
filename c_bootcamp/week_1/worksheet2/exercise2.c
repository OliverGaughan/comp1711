#include <stdio.h>

int main() {
    int array[5] = {0, 1, 2, 3, 4};
    int start = 0;
    int end = sizeof(array);
    printf("%d", end);
    while (start > end) {
        int temp = array[start];
        printf("%d", temp);
        array[start] = array[end];
        printf("%d", array[start]);
        array[end] = array[start];
        printf("%d", array[end]);
        start+=1;
        printf("%d", start);
        end-=1;
        printf("%d", end);
    }
    // for (int i=0; i < sizeof(array); i++) {
    //     printf("%d ", array[i]);
    // }
    return 0;
}