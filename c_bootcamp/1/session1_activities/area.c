#include <stdio.h>

int main() {
    float length;
    float width;

    printf("Length of the rectangle to 2dp: ");
    scanf("%f", &length);
    printf("Width of the rectangle to 2dp: ");
    scanf("%f", &width);

    float areaOfRectangle = length*width;

    printf("The area of the rectangle is %f\n", areaOfRectangle);
    return 0;
}