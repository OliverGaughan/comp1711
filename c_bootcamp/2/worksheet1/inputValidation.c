#include <stdio.h>

int main() {
    int num;
    while (num != -1) {
        printf("Enter a number: ");
        scanf ("%d", &num);

        if (num == -1) {
            printf ("Program terminated.\n");           
        } else if (num >= 0 && num <= 100) {
            printf("%d is in the range\n", num);
        } else {
            printf("%d isn't in the range\n", num);            
        }
    }

    return 0;
}