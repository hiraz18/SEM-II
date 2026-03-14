#include <stdio.h>

// =================== a) Insertion sort for integers ===================
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

// =================== b) Bubble sort for characters ====================
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

// =================== c) Selection sort for integers ==================
void selectionSortInt(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// =================== d) Quick sort for characters =====================
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

// =================== Helper print functions ============================
void printIntArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printCharArray(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

// =================== Main driver code ================================
int main() {
    // Example for Insertion sort (integers)
    int intArr1[] = {12, 11, 13, 5, 6};
    int n1 = 5;
    printf("Insertion sort on integers:\n");
    printf("Original: ");
    printIntArray(intArr1, n1);
    insertionSortInt(intArr1, n1);
    printf("Sorted  : ");
    printIntArray(intArr1, n1);
    printf("\n");

    // Example for Bubble sort (characters)
    char charArr1[] = {'d', 'a', 'c', 'b', 'e'};
    int n2 = 5;
    printf("Bubble sort on characters:\n");
    printf("Original: ");
    printCharArray(charArr1, n2);
    bubbleSortChar(charArr1, n2);
    printf("Sorted  : ");
    printCharArray(charArr1, n2);
    printf("\n");

    // Example for Selection sort (integers)
    int intArr2[] = {64, 25, 12, 22, 11};
    int n3 = 5;
    printf("Selection sort on integers:\n");
    printf("Original: ");
    printIntArray(intArr2, n3);
    selectionSortInt(intArr2, n3);
    printf("Sorted  : ");
    printIntArray(intArr2, n3);
    printf("\n");

    // Example for Quick sort (characters)
    char charArr2[] = {'d', 'a', 'c', 'b', 'e'};
    int n4 = 5;
    printf("Quick sort on characters:\n");
    printf("Original: ");
    printCharArray(charArr2, n4);
    quickSortChar(charArr2, 0, n4 - 1);
    printf("Sorted  : ");
    printCharArray(charArr2, n4);

    return 0;
}
