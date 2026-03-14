#include <stdio.h>

//a) Insertion sort for integers
void insertionSortInt(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//b) Bubble sort for characters 
void bubbleSortChar(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// c) Selection sort for integers
void selectionSortInt(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

//d) Quick sort for characters 
int partitionChar(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    char temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSortChar(char arr[], int low, int high) {
    if (low < high) {
        int pi = partitionChar(arr, low, high);
        quickSortChar(arr, low, pi - 1);
        quickSortChar(arr, pi + 1, high);
    }
}

//Print functions
void printInt(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void printChar(char arr[], int n) {
    for (int i = 0; i < n; i++) printf("'%c' ", arr[i]);
    printf("\n");
}

//Get user input 
void getIntInput(int arr[], int n) {
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
}

void getCharInput(char arr[], int n) {
    printf("Enter %d characters: ", n);
    for (int i = 0; i < n; i++) scanf(" %c", &arr[i]);  // space before %c skips whitespace
}

//Main menu
int main() {
    int choice, n;
    int intArr[100];
    char charArr[100];

    while (1) {
        printf("\n=== Sorting Algorithms ===\n");
        printf("1. Insertion Sort (Integers)\n");
        printf("2. Bubble Sort (Characters)\n");
        printf("3. Selection Sort (Integers)\n");
        printf("4. Quick Sort (Characters)\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        printf("Enter array size: ");
        scanf("%d", &n);

        switch (choice) {
            case 1:  // Insertion integers
                getIntInput(intArr, n);
                printf("Original: "); printInt(intArr, n);
                insertionSortInt(intArr, n);
                printf("Sorted:   "); printInt(intArr, n);
                break;

            case 2:  // Bubble characters
                getCharInput(charArr, n);
                printf("Original: "); printChar(charArr, n);
                bubbleSortChar(charArr, n);
                printf("Sorted:   "); printChar(charArr, n);
                break;

            case 3:  // Selection integers
                getIntInput(intArr, n);
                printf("Original: "); printInt(intArr, n);
                selectionSortInt(intArr, n);
                printf("Sorted:   "); printInt(intArr, n);
                break;

            case 4:  // Quick characters
                getCharInput(charArr, n);
                printf("Original: "); printChar(charArr, n);
                quickSortChar(charArr, 0, n - 1);
                printf("Sorted:   "); printChar(charArr, n);
                break;

            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }
    return 0;
}
