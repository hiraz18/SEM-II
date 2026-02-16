#include <stdio.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *ptr = arr;  // ptr points to first element of arr

    printf("Array elements using pointer: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));  // access using pointer arithmetic
    }

    return 0;
}
