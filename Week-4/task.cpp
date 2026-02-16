#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Global head for simplicity
struct Node* head = NULL;

// I. Creation: Insert at end to build list
void create(int n) {
    struct Node* newNode;
    struct Node* temp = head;
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data %d: ", i+1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

// II. Insertion functions

// At beginning
void insertBeg(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted at beginning: %d
", data);
}

// At end
void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = head;
    if (temp == NULL) {
        head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted at end: %d
", data);
}

// At middle (after a given position, 0-indexed)
void insertMid(int data, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* temp = head;
    if (pos == 0) {
        insertBeg(data);
        return;
    }
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds
");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted at middle (pos %d): %d
", pos, data);
}

// III. Deletion functions

// At beginning
void deleteBeg() {
    if (head == NULL) {
        printf("List empty
");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted from beginning: %d
", temp->data);
    free(temp);
}

// At end
void deleteEnd() {
    if (head == NULL) {
        printf("List empty
");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted from end: %d
", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted from end: %d
", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// At middle (given position, 0-indexed)
void deleteMid(int pos) {
    if (head == NULL) {
        printf("List empty
");
        return;
    }
    struct Node* temp = head;
    if (pos == 0) {
        deleteBeg();
        return;
    }
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds
");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted from middle (pos %d): %d
", pos, toDelete->data);
    free(toDelete);
}

// IV. Traversal
void traversal() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List empty
");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("
");
}

int main() {
    int choice, n, data, pos;
    printf("Singly Linked List Operations
");
    
    // Example usage:
    printf("1. Create list (enter size): ");
    scanf("%d", &n);
    create(n);
    traversal();
    
    // Insert
    printf("Insert beg (data): "); scanf("%d", &data); insertBeg(data); traversal();
    printf("Insert end (data): "); scanf("%d", &data); insertEnd(data); traversal();
    printf("Insert mid (data pos): "); scanf("%d %d", &data, &pos); insertMid(data, pos); traversal();
    
    // Delete
    deleteBeg(); traversal();
    printf("Delete mid (pos): "); scanf("%d", &pos); deleteMid(pos); traversal();
    deleteEnd(); traversal();
    
    return 0;
}
