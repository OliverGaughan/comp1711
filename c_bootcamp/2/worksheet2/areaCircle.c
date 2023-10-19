#include <stdio.h>

float circleArea (float radius)
{
    float area;
    area = 3.14 * (radius*radius);
    return area;
}

int main () 
{
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    float area = circleArea(radius);

    printf ("The area of a circle with the radius of %f is %f!\n", radius, area);
    return 0;
}