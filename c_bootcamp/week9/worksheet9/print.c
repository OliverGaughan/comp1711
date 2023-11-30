#include <stdio.h>

int main()
{
    char l[100];
    printf("Input a string: ");

    scanf("%c", l);

    char* address = l;

    int counter = 0;
    while (l[counter] != '\0') {
        counter++;
    }

    char arr[counter+1];

    char* address2 = arr;

    for (int i = 0; i < counter+1; i++) {
        arr[i] = *(address+i);
    }

    for (int i = 0; i < counter+1; i++) {
        printf("%c at pointer %p\n", arr[i], address2+i);
    }  
}