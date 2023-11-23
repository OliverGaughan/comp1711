#include <stdio.h>

int main() {
    int givenInt;

    printf("Enter an integer: ");
    scanf("%d", &givenInt);

    if (givenInt % 2 == 0) {
        printf("%d is even!\n", givenInt);
    } else {
        printf("%d is odd!\n", givenInt);
    }
    
    return 0;
}