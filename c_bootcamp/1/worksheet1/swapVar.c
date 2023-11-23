#include <stdio.h>

int main() {
    int var1;
    int var2;

    printf("Enter the first value: ");
    scanf("%d", &var1);

    printf("Enter the second variable: ");
    scanf("%d", &var2);

    printf("1st variable: %d\n2nd variable: %d\n", var1, var2);

    int temp = var1;
    var1 = var2;
    var2 = temp;

    printf("Variables Swapped!\n1st variable: %d\n2nd variable: %d\n", var1, var2);

    return 0;   
}