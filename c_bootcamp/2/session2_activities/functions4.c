#include <stdio.h>


// function that takes in fahrenheit temperature and returns the celsius temperature
float fahr_to_celsius (float f_temp)
{
    float c_temp;
    c_temp = (f_temp - 32)/1.8;
    return c_temp;
}

// function that takes in fahrenheit temperature and returns the kelvin temperature
float fahr_to_kelvin (float f_temp)
{
    float k_temp;
    k_temp = fahr_to_celsius(f_temp) + 273.15;
    return k_temp;
}

float fahr_to_newt (float f_temp)
{
    float n_temp;
    n_temp = (f_temp - 32)/5.45454555;
    return n_temp;
}

// function that allows user to input a temperature, then select 2 different options, with whatever option that is chosen calling the corresponding function
int main () 
{
    float fahrenheit;
    char option;

    printf ("Enter a temperature to convert in Fahrenheit:\n");
    scanf ("%f", &fahrenheit);

    printf ("\n");
    printf ("Select A to convert to Celsius\n");
    printf ("Select B to convert to Kelvin\n");
    printf ("Select C to convert to Newton\n");
    printf ("Select Q to quit\n");

    scanf(" %c", &option);

    switch (option)
    {
        case 'A':
        case 'a':
            printf ("Converted to degrees Celsius: %f\n", fahr_to_celsius(fahrenheit));
            break;

        case 'B':
        case 'b':
            printf ("Converted to Kelvin: %f\n", fahr_to_kelvin(fahrenheit));
            break;

        case 'C':
        case 'c':
            printf ("Converted to Newton: %f\n", fahr_to_newt(fahrenheit));
            break;

        case 'Q': break;

        default:  break;
    }

    return 0;
}
