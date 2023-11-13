#include <stdio.h>

typedef struct {
    char date[20];
    float bloodIron;
} reading;

int main() {
    char dateN[20];
    float bloodIronN;
    printf("Create an new reading: ");
    printf("-> Date: ");
    scanf("%s", dateN);
    printf("-> Blood iron: ");
    scanf("%f", &bloodIronN);

    reading num1;
    num1.date = dateN;
    num1.bloodIron = bloodIronN;

}