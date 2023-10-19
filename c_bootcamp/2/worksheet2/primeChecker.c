#include <stdio.h>

int isPrime(int num) {
    int counter = 0; 
    for (int i = num; i>0; i--) {
        if (num%i == 0) {
            counter += 1;
        }
    }
    if (counter > 2) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    int result = isPrime(num);

    if (result == 1) {
        printf("%d is a prime number!\n", num);
    } else {
        printf("%d isn't a prime number!\n", num);
    }
    return 0;
}