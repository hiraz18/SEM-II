#include <stdio.h>

// Linear search non-recursive
int linear_iter(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

// Linear search recursive
int linear_rec(int arr[], int n, int key) {
    if (n == 0) return -1;
    if (arr[n - 1] == key) return n - 1;
    int res = linear_rec(arr, n - 1, key);
    return (res == -1) ? -1 : res;
}

// Binary search non-recursive
int binary_iter(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Binary search recursive
int binary_rec(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] < key)
        return binary_rec(arr, mid + 1, high, key);
    return binary_rec(arr, low, mid - 1, key);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  // Unsorted for linear
    int n = sizeof(arr) / sizeof(arr[0]);
    int sorted[] = {11, 12, 22, 25, 34, 64, 90};  // Sorted for binary
    int key, choice, index;

    printf("Enter key to search: ");
    scanf("%d", &key);

    printf("\n--- Linear Search ---\n");
    printf("1. Iterative  2. Recursive\nEnter: ");
    scanf("%d", &choice);
    index = (choice == 1) ? linear_iter(arr, n, key) : linear_rec(arr, n, key);
    if (index != -1) printf("Linear: Found at index %d\n", index);
    else printf("Linear: Not found\n");

    printf("\n--- Binary Search (sorted array) ---\n");
    printf("1. Iterative  2. Recursive\nEnter: ");
    scanf("%d", &choice);
    index = (choice == 1) ? binary_iter(sorted, n, key) : binary_rec(sorted, 0, n - 1, key);
    if (index != -1) printf("Binary: Found at index %d\n", index);
    else printf("Binary: Not found\n");

    return 0;
}
