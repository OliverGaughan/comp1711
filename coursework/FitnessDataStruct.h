#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H
#include <stdio.h>
#include <stdlib.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps);


FILE *open_file(char filename[], char mode[]);

#endif