#include <stdio.h>
#include <stdlib.h>

#define SIZE 31  // Prime number for better distribution

// Linked list node
typedef struct ListNode {
    int key;
    struct ListNode* next;
} ListNode;

// Hash table array (array of linked lists)
ListNode* hashTable[SIZE];

// =================== d) Hash Function ===================
int hashFunction(int key) {
    return key % SIZE;  // Simple modulo hash
}

// =================== Helper: create new list node ===================
ListNode* createNode(int key) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// =================== a) Insert ===================
void insert(int key) {
    int index = hashFunction(key);
    
    // Check if key already exists
    ListNode* temp = hashTable[index];
    while (temp) {
        if (temp->key == key) {
            printf("Key %d already exists\n", key);
            return;
        }
        temp = temp->next;
    }
    
    // Insert at head of chain
    ListNode* newNode = createNode(key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    printf("Inserted %d at index %d\n", key, index);
}

// =================== c) Search ===================
int search(int key) {
    int index = hashFunction(key);
    ListNode* temp = hashTable[index];
    
    while (temp) {
        if (temp->key == key) {
            printf("Key %d found at index %d\n", key, index);
            return 1;
        }
        temp = temp->next;
    }
    printf("Key %d not found\n", key);
    return 0;
}

// =================== b) Delete ===================
void delete(int key) {
    int index = hashFunction(key);
    ListNode* temp = hashTable[index];
    ListNode* prev = NULL;
    
    while (temp) {
        if (temp->key == key) {
            if (prev == NULL) {
                hashTable[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Deleted %d from index %d\n", key, index);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d not found for deletion\n", key);
}

// =================== Print hash table ===================
void printTable() {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        ListNode* temp = hashTable[i];
        while (temp) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// =================== Main ===================
int main() {
    int choice, key;

    // Initialize hash table to NULL
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    while (1) {
        printf("\nHash Table Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print Table\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 4:
                printTable();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
