#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 4 == 0 && num % 5 == 0)  {
        printf("%d is divisible by both 4 and 5\n", num);       
    } else if (num % 4 == 0) {
        printf("%d is only divisible by 4\n", num);
    } else if (num % 5 == 0) {
        printf("%d is only divisible by 5\n", num);
    } else {
        printf("%d is divisile by neither 4 nor 5\n", num);
    }
    return 0;
}