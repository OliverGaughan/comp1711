#include <stdio.h>

int main() {
    float principal;
    float interest;
    int time;

    float simpleInterest;

    printf("Enter the principal (£/$): ");
    scanf("%f", &principal);

    printf("Enter the interest rate per year (%s): ", "%");
    scanf("%f", &interest);

    printf("Enter the time (yrs): ");
    scanf("%d", &time);

    simpleInterest = principal * (interest/100) * time;

    printf("The simple interest is %f", simpleInterest);

    return 0;
}
