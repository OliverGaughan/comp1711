#include <stdio.h>

int main() {

    float fahrenheit;
    float celsius;

    printf("Enter the Fehrenheit value: ");
    scanf("%f", &fahrenheit);

    celsius = ((fahrenheit-32)*5)/9;

    printf("%f Fahrenheit is %f in celsius!\n", fahrenheit, celsius);
    
    return 0;
}