#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key  = data;
    temp->left = temp->right = NULL;
    return temp;
}

// =================== a) Insert into BST ===================
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;  // same key: ignore duplicate (or handle as per requirement)
}

// =================== c) Search in BST ===================
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// =================== Delete helper: find min node ===================
Node* findMin(Node* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

// =================== b) Delete from BST ===================
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to delete found
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Two children: replace with inorder successor
        Node* succ = findMin(root->right);
        root->key = succ->key;
        root->right = deleteNode(root->right, succ->key);
    }
    return root;
}

// =================== Inorder traversal (for debugging) ===================
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// =================== Utility: print menu ===================
void printMenu() {
    printf("\nBST Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Print inorder\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

// =================== Main driver ===================
int main() {
    Node* root = NULL;
    int choice, key;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inserted %d.\n", key);
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    root = deleteNode(root, key);
                    printf("Deleted %d.\n", key);
                } else {
                    printf("%d not found in tree.\n", key);
                }
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("Key %d found.\n", key);
                } else {
                    printf("Key %d not found.\n", key);
                }
                break;

            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
