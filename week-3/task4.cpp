#include <stdio.h>

int main() {
    int n, index;
    
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter index to access (0 to %d): ", n-1);
    scanf("%d", &index);
    
    int *ptr = arr;
    printf("Element at index %d: %d\n", index, *(ptr + index));
    
    return 0;
}
