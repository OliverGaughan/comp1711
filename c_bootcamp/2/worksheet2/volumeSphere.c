#include <stdio.h>
#include <math.h>

float volumeSphere (double radius)
{
    float volume;
    volume = (4/3) * 3.14 * pow(radius, 3);
    return volume;
}

int main () 
{
    double radius;
    printf("Enter the radius of the sphere: ");
    scanf("%lf", &radius);
    float volume = volumeSphere(radius);

    printf ("The volume of a sphere with the radius of %lf is %f!\n", radius, volume);
    return 0;
}