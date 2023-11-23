#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = rand();
    int lives = 3;
    int guess;

    while (lives > 0) {
        printf("Guess a number: ");
        scanf("%d", &guess);
        if (guess == number) {
            printf("Well done, you correctly guessed the number!\n");
            return 0;
        } else {
            lives -= 1;
            if (guess >= number) {
                printf("Incorrect, you were too high. You have %d live(s) remaining!\n", lives);
            } else {
                printf("Incorrect, you were too low. You have %d live(s) remaining!\n", lives);
            }

        }
    }
    printf("Out of lives! The number was %d!\n", number);
    return 0;
}