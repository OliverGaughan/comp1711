#include <stdio.h>

char concatStrings(char string1[100], char string2[100]) {
    char concatString[200];
    for (int i=0; i < str_len(string1); i++) {
        concatString[i] = string1[i];
    }
    for (int i=strlen(concatString); i < (strlen(string1)+str_len(string2)); i++) {
        concatString[i] = string2[i-strlen(concatString)];
    }
    return concatString;
}

int str_len(char strInput[100]) {
    int count = 0;
    while (strInput[count] != '\0') {
        count += 1;
    }
    return count;
}

int main() {}