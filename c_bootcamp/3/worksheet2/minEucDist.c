#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

    double closest = __DBL_MAX__;
    double eucDist;
    int min_indexes[2];


    for (int i=0; i < 10; i++) {
        for (int j=0; j < 10; j++) {
            if (i != j) {
                double xSQRD = (points[i].x - points[j].x) * (points[i].x - points[j].x);
                double ySQRD = (points[i].y - points[j].y) * (points[i].y - points[j].y);
                eucDist = sqrt(xSQRD + ySQRD);
                // printf("%lf", eucDist);
                if (eucDist < closest) {
                    closest = eucDist;
                    min_indexes[0] = i+1;
                    min_indexes[1] = j+1;
                }
            }
        }
    }

    printf("The minimum Euclidean distance is between points %d and %d: %lf\n", min_indexes[0], min_indexes[1], closest);

}