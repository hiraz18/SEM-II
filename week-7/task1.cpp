#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack[MAX], top = -1;

// --- ARRAY OPERATIONS ---
void push_arr(int val) {
    if (top == MAX - 1) printf("Array Stack Overflow\n");
    else stack[++top] = val;
}

void pop_arr() {
    if (top == -1) printf("Array Stack Underflow\n");
    else printf("Popped from Array: %d\n", stack[top--]);
}

void display_arr() {
    printf("Array Stack: ");
    for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}

// --- LINKED LIST OPERATIONS ---
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* head = NULL;

void push_ll(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void pop_ll() {
    if (head == NULL) printf("LL Stack Underflow\n");
    else {
        Node* temp = head;
        printf("Popped from LL: %d\n", temp->data);
        head = head->next;
        free(temp);
    }
}

void display_ll() {
    printf("LL Stack: ");
    Node* temp = head;
    while (temp) { printf("%d ", temp->data); temp = temp->next; }
    printf("\n");
}

int main() {
    // 1. Testing Array Stack
    printf("--- Array Stack ---\n");
    push_arr(10);
    push_arr(20);
    push_arr(30);
    display_arr(); // Shows: 30 20 10
    pop_arr();     // Removes 30
    display_arr(); // Shows: 20 10

    // 2. Testing Linked List Stack
    printf("\n--- Linked List Stack ---\n");
    push_ll(100);
    push_ll(200);
    display_ll();  // Shows: 200 100
    pop_ll();      // Removes 200
    display_ll();  // Shows: 100

    return 0;
}
