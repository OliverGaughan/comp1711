#include <stdio.h>

int main()
{
    int vector[5] = {11,13,17, 23 , 31};

    int* address = vector;

    printf ( "\nAddress[0] = %d\n\n", *address);

    printf ( "\nAddress[1] = %d\n\n", *address++); // Passes in the value of address then increments it

    printf ("\n Address[2] = %d\n\n", *++address); // Increments the value of address then prints it

    printf ("\n \n What is happening here?");

}