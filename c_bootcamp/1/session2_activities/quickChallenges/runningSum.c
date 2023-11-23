#include <stdio.h>

int main() {
    int runningSum = 0;

    for (int i = 1; i < 100; i+=2) {
        runningSum += i;
        printf("Odd Number: %d | Running Sum: %d\n", i, runningSum);
    }
}