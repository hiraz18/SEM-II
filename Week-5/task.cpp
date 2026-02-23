#include <stdio.h>
#include <stdlib.h>

// Structure for a Doubly Linked List node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a doubly linked list
void createList(int n) {
    struct Node* newNode, *temp;
    int data;

    if (n <= 0) {
        printf("Invalid size!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    printf("List created successfully.\n");
}

// Insert at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    printf("Node inserted at beginning.\n");
}

// Insert at the end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp;

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node inserted at end.\n");
}

// Insert at a given position (middle)
void insertAtMiddle(int data, int pos) {
    if (pos < 0) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;

    if (pos == 0) {
        insertAtBeginning(data);
        free(newNode);
        return;
    }

    struct Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Node inserted at position %d.\n", pos);
}

// Delete from beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted node from beginning with data: %d\n", temp->data);
    free(temp);
}

// Delete from end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    if (head->next == NULL) {
        printf("Deleted node from end with data: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    printf("Deleted node from end with data: %d\n", temp->data);
    free(temp);
}

// Delete from a given position (middle)
void deleteAtMiddle(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 0) {
        deleteAtBeginning();
        return;
    }

    struct Node* temp = head;
    for (int i = 0; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted node from position %d with data: %d\n", pos, temp->data);
    free(temp);
}

// Traverse the doubly linked list
void traversal() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Forward Traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next == NULL) break;
        temp = temp->next;
    }
    printf("\n");

    printf("Backward Traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, n, data, pos;

    while (1) {
        printf("\n\n----- Doubly Linked List Operations -----\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Middle\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from Middle\n");
        printf("7. Delete from End\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtMiddle(data, pos);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtMiddle(pos);
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                traversal();
                break;
            case 9:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
