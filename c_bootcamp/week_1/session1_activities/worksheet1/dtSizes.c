#include <limits.h>
#include <stdio.h>
#include <float.h>

int main() {
    printf("The max size of an int is %d\n", __INT_MAX__);
    printf("The max size of a float is %f\n", __FLT_MAX__);
    printf("The max size of a double is %lf\n", __DBL_MAX__);
    printf("The max size of a char is %d\n", __SCHAR_MAX__);
    return 0;
}