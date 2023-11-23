#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    double x;
    double y;
} point;


void tokeniseRecord(const char *input, const char *delimiter,
                    char *pos, char *artist, char *title, char *years)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(pos, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(artist, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(title, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(years, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

int main()
{
    point points[10];
    
    for (int i=0; i < 10; i++) {
        points[i].x = rand();
        points[i].y = rand();
    }

    for (int i=0; i < 10; i++) {
        printf("Point %d | x: %lf y: %lf\n", i+1, points[i].x, points[i].y);
    }

    double totalMan = 0;
    
    for (int i=0; i < 9; i++) {
        totalMan += (points[i].x - points[i+1].x) + (points[i].y - points[i+1].y);
    }



    double averageMan = totalMan/10;


    printf("The average Manhattan distance amongst all points: %lf\n", averageMan);

}