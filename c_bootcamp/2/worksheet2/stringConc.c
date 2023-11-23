#include <stdio.h>

int str_len(char strInput[100]);
const char * concatStrings(char string1[100], char string2[100]);

const char * concatStrings(char string1[100], char string2[100]) {
    char concatString[100];
    int i;
    for (i=0; i < str_len(string1); i++) {
        concatString[i] = string1[i];
    }
    int j;
    for (j=0; j < str_len(string2); j++) {
        concatString[i+j] = string2[j];
    }
    concatString[(str_len(string1)+str_len(string2))-1] = "\0";

    return concatString;
}

int str_len(char strInput[100]) {
    int count = 0;
    while (strInput[count] != '\0') {
        count += 1;
    }
    return count;
}

int main() {
    char string1[100];
    char string2[100];
    printf("Enter a string: ");
    scanf("%s", string1);
    printf("Enter another string: ");
    scanf("%s", string2);

    char concatString[200] = concatStrings(string1, string2);
    
    printf("The concatenated string is %s!\n", concatString);
    return 0;
}