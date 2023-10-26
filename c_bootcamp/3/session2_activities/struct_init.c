#include <stdio.h>
#include <string.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

int main () {
    char name[200];
    char student_id[11];
    unsigned mark;

    struct student new_student;

    printf("=== Creating new profile ===\n");
    printf("What is your name?\n");
    scanf("%s", new_student.name); // scanf() becomes inefficient when dealing with spaces in strings - runs until it sees a space then stops scanning
    printf("What is you student ID, %s?\n", new_student.name);
    scanf("%s", new_student.student_id);
    printf("What is your final mark, %s?\n", new_student.name);
    scanf("%u", &new_student.mark);

    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}