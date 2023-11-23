#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    double x;
    double y;
} point;

int main()
{
    point points[10];
    
    for (int i=0; i < 10; i++) {
        points[i].x = rand();
        points[i].y = rand();
    }

    for (int i=0; i < 10; i++) {
        printf("Point %d | x: %lf y: %lf\n", i+1, points[i].x, points[i].y);
    }

}