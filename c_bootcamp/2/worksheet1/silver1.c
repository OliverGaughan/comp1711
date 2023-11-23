#include <stdio.h>

int main() {
    int mark;
    printf("Enter a student's mark/grade: ");
    scanf("%d", &mark);

    if (mark >= 70)  {
        printf("%d is a distinction\n", mark);       
    } else if (mark >= 50) {
        printf("%d is a pass\n", mark);
    } else {
        printf("%d is a fail\n", mark);
    }
    return 0;
}