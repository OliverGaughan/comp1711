#include <stdio.h>

int main() {
    int givenInt;
    int factoral = 1;

    printf("Enter an integer: ");
    scanf("%d", &givenInt);

    for (int i=givenInt;i>0;i--) {
        factoral = factoral*i;
    }

    printf("The factoral of %d is %d!\n", givenInt, factoral);

    return 0;
}