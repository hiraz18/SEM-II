#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// =================== Insert into BST (for tree building) ===================
Node* insert(Node* root, int data) {
    if (!root) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

// =================== a) Inorder: Left-Root-Right ===================
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// =================== b) Preorder: Root-Left-Right ===================
void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// =================== c) Postorder: Left-Right-Root ===================
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// =================== Main driver ===================
int main() {
    Node* root = NULL;
    int n, data, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    while (1) {
        printf("\n--- Tree Traversals ---\n");
        printf("1. Inorder\n");
        printf("2. Preorder\n");
        printf("3. Postorder\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        switch (choice) {
            case 1: printf("Inorder:  "); inorder(root); printf("\n"); break;
            case 2: printf("Preorder: "); preorder(root); printf("\n"); break;
            case 3: printf("Postorder:"); postorder(root); printf("\n"); break;
            default: printf("Invalid.\n");
        }
    }
    return 0;
}
