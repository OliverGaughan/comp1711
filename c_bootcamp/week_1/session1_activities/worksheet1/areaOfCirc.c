#include <stdio.h>

int main() {
    float radius;
    float area;

    printf("Radius of the circle: ");
    scanf("%f", &radius);
    
    area = 3.141592653 * (radius*radius);

    printf("The area of a circle with the radius %f is %f", radius, area);

    return 0;
}