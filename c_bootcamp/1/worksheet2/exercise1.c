#include <stdio.h>

int main() {
    int array[5] = {0, 1, 2, 3, 4};
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += i;
    }
    printf("The sum of all elements in the array is %d!\n", sum);
    return 0;
}