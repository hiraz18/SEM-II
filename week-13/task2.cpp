#include <stdio.h>
#include <stdlib.h>

// AVL Tree node structure
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Create new node
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Height of node
int height(Node *n) {
    return n ? n->height : 0;
}

// Max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Balance factor
int getBalance(Node *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Right rotate
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Left rotate
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// =================== a) Insert in AVL ===================
Node* insert(Node* node, int key) {
    // Standard BST insert
    if (!node) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else return node;  // No duplicates

    // Update height
    node->height = max(height(node->left), height(node->right)) + 1;

    // Balance factor
    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// =================== c) Search in AVL ===================
Node* search(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

// Min value node
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left) current = current->left;
    return current;
}

// =================== b) Delete from AVL ===================
Node* deleteNode(Node* root, int key) {
    // Standard BST delete
    if (!root) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Two children
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    if (!root) return root;

    // Update height
    root->height = max(height(root->left), height(root->right)) + 1;

    // Balance
    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// =================== Main ===================
int main() {
    Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Print inorder\n5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        switch (choice) {
            case 1:
                printf("Key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inserted %d\n", key);
                break;
            case 2:
                printf("Key to delete: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    root = deleteNode(root, key);
                    printf("Deleted %d\n", key);
                } else {
                    printf("%d not found\n", key);
                }
                break;
            case 3:
                printf("Key to search: ");
                scanf("%d", &key);
                if (search(root, key)) printf("%d found\n", key);
                else printf("%d not found\n", key);
                break;
            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            default:
                printf("Invalid\n");
        }
    }
    return 0;
}
