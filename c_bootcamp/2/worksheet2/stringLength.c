#include <stdio.h>


int str_len(char strInput[100]) {
    int count = 0;
    while (strInput[count] != '\0') {
        count += 1;
    }
    return count;
}

int main() {
    char strInput[100];
    printf("Enter a string: ");
    scanf("%s", strInput);
    int length = str_len(strInput);
    printf("The length of %s is %d!\n", strInput, length);
    return 0;
}