#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Global head pointer
struct Node *head = NULL;

// Create list with n nodes (inserts at end)
void create(int n) {
    int i, value;
    struct Node *newNode, *temp;

    for (i = 0; i < n; i++) {
        printf("Enter data %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

// Insertion at beginning
void insertBeg(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Insertion at end
void insertEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Insertion at middle (position pos, 1-based)
// If pos == 1 it behaves like insertBeg
void insertMid(int value, int pos) {
    int i;
    struct Node *newNode, *temp;

    if (pos <= 1 || head == NULL) {
        insertBeg(value);
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    temp = head;
    for (i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    // Insert after temp
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Deletion at beginning
void deleteBeg() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// Deletion at end
void deleteEnd() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    temp = head;

    // Only one node
    if (temp->next == NULL) {
        printf("Deleted %d from end.\n", temp->data);
        head = NULL;
        free(temp);
        return;
    }

    // Move to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted %d from end.\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

// Deletion at middle (position pos, 1-based)
void deleteMid(int pos) {
    int i;
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (pos <= 1) {
        deleteBeg();
        return;
    }

    temp = head;
    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    // If last node
    if (temp->next == NULL) {
        deleteEnd();
        return;
    }

    // Node in the middle
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
}

// Traversal (forward)
void traversal() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, data, pos;

    printf("How many nodes to create initially? ");
    scanf("%d", &n);
    create(n);
    traversal();

    printf("\nInsert at beginning, enter data: ");
    scanf("%d", &data);
    insertBeg(data);
    traversal();

    printf("\nInsert at end, enter data: ");
    scanf("%d", &data);
    insertEnd(data);
    traversal();

    printf("\nInsert at middle, enter data and position: ");
    scanf("%d %d", &data, &pos);
    insertMid(data, pos);
    traversal();

    printf("\nDelete at beginning:\n");
    deleteBeg();
    traversal();

    printf("\nDelete at end:\n");
    deleteEnd();
    traversal();

    printf("\nDelete at middle, enter position: ");
    scanf("%d", &pos);
    deleteMid(pos);
    traversal();

    return 0;
}
