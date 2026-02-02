#include <stdio.h>

// Function Prototypes
void display(int arr[], int size);
void insertAt(int arr[], int *size, int pos, int element);
void deleteAt(int arr[], int *size, int pos);

int main() {
    int arr[25]; // Fixed size of 25
    int n = 0;   // Current number of elements
    int choice, element, pos;

    // 1. Initial Creation
    printf("How many elements do you want to enter initially? ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    display(arr, n);

    // 2. Insert at Particular Location
    printf("\n--- Insert Operation ---\n");
    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position (0 to %d): ", n);
    scanf("%d", &pos);
    insertAt(arr, &n, pos, element);
    display(arr, n);

    // 3. Delete from Beginning, Middle, and End
    printf("\n--- Deleting Elements (Beginning, Middle, End) ---\n");
    
    // Delete Beginning (Index 0)
    printf("Deleting from beginning...\n");
    deleteAt(arr, &n, 0);

    // Delete Middle (Index n/2)
    printf("Deleting from middle...\n");
    deleteAt(arr, &n, n / 2);

    // Delete End (Index n-1)
    printf("Deleting from end...\n");
    deleteAt(arr, &n, n - 1);

    // Final Display
    display(arr, n);

    return 0;
}

// Function to display the array
void display(int arr[], int size) {
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSize: %d\n", size);
}

// Function to insert at a specific index
void insertAt(int arr[], int *size, int pos, int element) {
    if (*size >= 25) {
        printf("Error: Array Overflow\n");
        return;
    }
    // Shift elements to the right
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    (*size)++;
}

// Function to delete from a specific index
void deleteAt(int arr[], int *size, int pos) {
    if (*size <= 0) {
        printf("Error: Array Underflow\n");
        return;
    }
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }
    // Shift elements to the left
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
