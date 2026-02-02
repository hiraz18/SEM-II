#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Define the structure
struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student *ptr;
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' structures
    // (struct Student*) casts the memory to our structure type
    ptr = (struct Student*) malloc(n * sizeof(struct Student));

    // Check if memory allocation was successful
    if (ptr == NULL) {
        printf("Memory not allocated. Exiting...\n");
        return 1; 
    }

    // Storing information
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", (ptr + i)->name); // No '&' needed for strings
        printf("Roll number: ");
        scanf("%d", &(ptr + i)->roll);
        printf("Marks: ");
        scanf("%f", &(ptr + i)->marks);
    }

    // Displaying information
    printf("\n--- Displaying Student Information ---\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: %s, Roll: %d, Marks: %.2f\n", 
                i + 1, (ptr + i)->name, (ptr + i)->roll, (ptr + i)->marks);
    }

    // VERY IMPORTANT: Free the allocated memory
    free(ptr);
    ptr = NULL; 

    return 0;
}
