#include <stdio.h>

int main() {
    int temperature;
    printf("Enter a temperature: ");
    scanf("%d", &temperature);

    if (temperature >= -10 && temperature <= 40)  {
        printf("%d is within the temperature range\n", temperature);       
    } else {
        printf("%d isn't within the temperature range\n", temperature);
    }
    return 0;
}