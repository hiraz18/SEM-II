#include <stdio.h>
#include <stdlib.h>

#define MAX 5   

//Stack using Array
int astack[MAX];
int atop = -1;

void apush(int x) {
    if (atop == MAX - 1) {
        printf("Array Stack Overflow\n");
        return;
    }
    astack[++atop] = x;
    printf("Pushed %d to Array Stack\n", x);
}

int apop() {
    if (atop == -1) {
        printf("Array Stack Underflow\n");
        return -1;
    }
    return astack[atop--];
}

void adisplay() {
    int i;
    if (atop == -1) {
        printf("Array Stack is Empty\n");
        return;
    }
    printf("Array Stack elements: ");
    for (i = atop; i >= 0; i--)
        printf("%d ", astack[i]);
    printf("\n");
}

//Stack using Linked List
struct Node {
    int data;
    struct Node *next;
};

struct Node *ltop = NULL;

void lpush(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = ltop;
    ltop = newNode;
    printf("Pushed %d to Linked List Stack\n", x);
}

int lpop() {
    struct Node *temp;
    int val;
    if (ltop == NULL) {
        printf("Linked List Stack Underflow\n");
        return -1;
    }
    temp = ltop;
    val = temp->data;
    ltop = ltop->next;
    free(temp);
    return val;
}

void ldisplay() {
    struct Node *temp = ltop;
    if (temp == NULL) {
        printf("Linked List Stack is Empty\n");
        return;
    }
    printf("Linked List Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Main: choose implementation
int main() {
    int implChoice, choice, val, res;

    while (1) {
        printf("\nChoose Stack Implementation:\n");
        printf("1. Array Stack\n");
        printf("2. Linked List Stack\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &implChoice);

        if (implChoice == 3)
            break;

        switch (implChoice) {
        case 1:
            while (1) {
                printf("\n--- Array Stack Menu ---\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Display\n");
                printf("4. Back to Main Menu\n");
                printf("Enter choice: ");
                scanf("%d", &choice);

                if (choice == 4) break;

                switch (choice) {
                case 1:
                    printf("Enter value to push: ");
                    scanf("%d", &val);
                    apush(val);
                    break;
                case 2:
                    res = apop();
                    if (res != -1)
                        printf("Popped %d from Array Stack\n", res);
                    break;
                case 3:
                    adisplay();
                    break;
                default:
                    printf("Invalid choice\n");
                }
            }
            break;

        case 2:
            while (1) {
                printf("\n--- Linked List Stack Menu ---\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Display\n");
                printf("4. Back to Main Menu\n");
                printf("Enter choice: ");
                scanf("%d", &choice);

                if (choice == 4) break;

                switch (choice) {
                case 1:
                    printf("Enter value to push: ");
                    scanf("%d", &val);
                    lpush(val);
                    break;
                case 2:
                    res = lpop();
                    if (res != -1)
                        printf("Popped %d from Linked List Stack\n", res);
                    break;
                case 3:
                    ldisplay();
                    break;
                default:
                    printf("Invalid choice\n");
                }
            }
            break;

        default:
            printf("Invalid implementation choice\n");
        }
    }

    return 0;
}
