#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct student s;

    printf("--- Enter Student Information ---\n");

    printf("Enter Full Name: ");
    // fgets is safer: it limits characters and reads spaces
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Removes the trailing newline

    printf("Enter Roll Number: ");
    if (scanf("%d", &s.roll) != 1) {
        printf("Invalid input for roll number.\n");
        return 1;
    }

    printf("Enter Marks: ");
    if (scanf("%f", &s.marks) != 1) {
        printf("Invalid input for marks.\n");
        return 1;
    }

    printf("\n--- Displaying Information ---\n");
    printf("Name:  %s\n", s.name);
    printf("Roll:  %d\n", s.roll);
    printf("Marks: %.2f\n", s.marks);

    return 0;
}
