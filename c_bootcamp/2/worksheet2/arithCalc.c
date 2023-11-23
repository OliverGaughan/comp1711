#include <stdio.h>

float calc(float num1, float num2, char op) {
    float result;
    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        result = num1 / num2;
    }

    return result;
}

int main() {
    float num1;
    float num2;
    printf("Enter a number: ");
    scanf("%f", &num1);
    printf("Enter another number: ");
    scanf("%f", &num2);

    printf("What arithmetic operation would you like you perform on these numbers: ");
    printf ("\n");
    printf ("1) %f + %f\n", num1, num2);
    printf ("2) %f - %f\n", num1, num2);
    printf ("3) %f x %f\n", num1, num2);
    printf ("4) %f / %f\n", num1, num2);
    printf ("5) QUIT\n");

    int option;
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            printf ("%f + %f = %f\n", num1, num2, calc(num1, num2, '+'));
            break;
        case 2:
            printf ("%f - %f = %f\n", num1, num2, calc(num1, num2, '-'));
            break;
        case 3:
            printf ("%f x %f = %f\n", num1, num2, calc(num1, num2, '*'));
            break;
        case 4:
            printf ("%f / %f = %f\n", num1, num2, calc(num1, num2, '/'));
            break;
        case 5:
            printf ("Quitting...\n");
            break;
        default:  break;
    }
    return 0;
}