#include <stdio.h>

int main() {

    int meal;

    printf ("=== MENU ===\nWhich meal would you want?:\n[1] Fish and Chips\n[2] Pizza\n[3] Burger and chips\n[4] Curry\n[5] Pasta\n============\n:> ");
    scanf ("%d", &meal);
    
    switch (meal) {
        case 1:
        printf("Fish and chips has been ordered.\n");
        break;

        case 2:
        printf("Pizza has been ordered.\n");
        break;

        case 3:
        printf("Burger and chips has been ordered.\n");
        break;

        case 4:
        printf("Curry has been ordered.\n");
        break;

        case 5:
        printf("Pasta has been ordered.\n");
        break;
    }
    
    return 0;
}