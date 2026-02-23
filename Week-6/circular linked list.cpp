#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;  // Points to the last node of the circular linked list

// Function to create a circular linked list with a single node
void create(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;  // Points to itself
    last = newNode;
    printf("Circular Linked List created with data: %d\n", data);
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    if (last == NULL) {
        create(data);
        return;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    printf("Inserted %d at the end.\n", data);
}

// Function to delete a node by value
void deleteNode(int key) {
    if (last == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = last->next, *prev;

    // If the list has only one node
    if (last == last->next && last->data == key) {
        free(last);
        last = NULL;
        printf("Deleted the only node with value %d.\n", key);
        return;
    }

    // If key is in the first node
    if (temp->data == key) {
        last->next = temp->next;
        free(temp);
        printf("Deleted node with value %d.\n", key);
        return;
    }

    // Search for the node to delete
    while (temp->next != last->next && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If node found
    if (temp->data == key) {
        prev->next = temp->next;
        if (temp == last)
            last = prev;
        free(temp);
        printf("Deleted node with value %d.\n", key);
    } else {
        printf("Node with value %d not found.\n", key);
    }
}

// Function to display the circular linked list
void traverse() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

// Main function
int main() {
    int choice, data;

    while (1) {
        printf("\n---- Circular Linked List Menu ----\n");
        printf("1. Create\n2. Insert\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to create list: ");
                scanf("%d", &data);
                create(data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 4:
                traverse();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
