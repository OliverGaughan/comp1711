#include <stdio.h>
#include <string.h>

int main() {
    char strBefore[15];
    printf("Enter a string: ");
    scanf("%s", strBefore);
    
    // printf("%ld", strlen(strBefore));

    int length = strlen(strBefore);
    char strReversed[length];

    int i;
    for (i=length-1;i>=0;i--) {
        printf("%d", i);
        strReversed[i-length+1] = strBefore[i];
    }

    printf("%s\n", strReversed);
    return 0;
}