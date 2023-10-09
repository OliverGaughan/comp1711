#include <limits.h>
#include <stdio.h>
#include <float.h>

int main() {
    printf("The max size of an int is %f\n", __INT_MAX__);
    printf("The max size of a float is %f\n", __FLT_MAX__);
    printf("The max size of a double is %f\n", __DBL_MAX__);
    printf("The max size of a char is %f\n", __CHAR_MAX__);
    return 0;
}