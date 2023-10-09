#include <stdio.h>

int main() {
    int a;
    int b;
    int c;

    printf("First integer: ");
    scanf("%d", &a);
    printf("Second integer: ");
    scanf("%d", &b);

    c = a + b;

    printf("The sum of %d and %d is %d!\n", a, b, c);
    return 0;
}