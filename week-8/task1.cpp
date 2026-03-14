#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Size for array queue

//Queue using Array 
int aqueue[MAX];
int afront = -1, arear = -1;

void aenqueue(int x) {
    if ((arear + 1) % MAX == afront) {
        printf("Array Queue Overflow\n");
        return;
    }
    if (afront == -1) afront = 0;
    arear = (arear + 1) % MAX;
    aqueue[arear] = x;
    printf("Enqueued %d to Array Queue\n", x);
}

int adequeue() {
    int val;
    if (afront == -1) {
        printf("Array Queue Underflow\n");
        return -1;
    }
    val = aqueue[afront];
    if (afront == arear) {
        afront = arear = -1;
    } else {
        afront = (afront + 1) % MAX;
    }
    return val;
}

void adisplay() {
    int i;
    if (afront == -1) {
        printf("Array Queue Empty\n");
        return;
    }
    printf("Array Queue: ");
    for (i = afront; i != arear; i = (i + 1) % MAX)
        printf("%d ", aqueue[i]);
    printf("%d\n", aqueue[arear]);
}

//Queue using Linked List
struct Node {
    int data;
    struct Node *next;
};

struct Node *lfront = NULL, *lrear = NULL;

void lenqueue(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;
    if (lrear == NULL) {
        lfront = lrear = newNode;
    } else {
        lrear->next = newNode;
        lrear = newNode;
    }
    printf("Enqueued %d to Linked List Queue\n", x);
}

int ldequeue() {
    struct Node *temp;
    if (lfront == NULL) {
        printf("Linked List Queue Underflow\n");
        return -1;
    }
    temp = lfront;
    int val = temp->data;
    lfront = lfront->next;
    if (lfront == NULL) lrear = NULL;
    free(temp);
    return val;
}

void ldisplay() {
    struct Node *temp = lfront;
    if (temp == NULL) {
        printf("Linked List Queue Empty\n");
        return;
    }
    printf("Linked List Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main Menu 
int main() {
    int choice, impl, val, res;

    while (1) {
        printf("\nChoose Queue Implementation:\n");
        printf("1. Array Queue\n2. Linked List Queue\n3. Exit\n");
        printf("Enter: ");
        scanf("%d", &impl);

        if (impl == 3) break;

        switch (impl) {
        case 1:  // Array queue menu
            while (1) {
                printf("\n--- Array Queue ---\n");
                printf("1. Enqueue 2. Dequeue 3. Display 4. Back\n");
                scanf("%d", &choice);
                if (choice == 4) break;
                switch (choice) {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", &val);
                    aenqueue(val);
                    break;
                case 2:
                    res = adequeue();
                    if (res != -1) printf("Dequeued %d\n", res);
                    break;
                case 3: adisplay(); break;
                default: printf("Invalid\n");
                }
            }
            break;

        case 2: 
            while (1) {
                printf("\n--- Linked List Queue ---\n");
                printf("1. Enqueue 2. Dequeue 3. Display 4. Back\n");
                scanf("%d", &choice);
                if (choice == 4) break;
                switch (choice) {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", &val);
                    lenqueue(val);
                    break;
                case 2:
                    res = ldequeue();
                    if (res != -1) printf("Dequeued %d\n", res);
                    break;
                case 3: ldisplay(); break;
                default: printf("Invalid\n");
                }
            }
            break;

        default: printf("Invalid choice\n");
        }
    }
    return 0;
}
