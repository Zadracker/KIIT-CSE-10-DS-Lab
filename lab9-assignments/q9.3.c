/*
9.3 In addition to 9.2, perform deletion of an element in the BST using function.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key > root->data)
        return search(root->right, key);
    return search(root->left, key);
}

Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node* findLargest(Node* root) {
    if (root == NULL || root->right == NULL)
        return root;
    return findLargest(root->right);
}

Node* findSmallest(Node* root) {
    if (root == NULL || root->left == NULL)
        return root;
    return findSmallest(root->left);
}

int height(Node* node) {
    if (node == NULL)
        return -1;
    return 1 + max(height(node->left), height(node->right));
}

int countLeaves(Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

void displayInorder(Node* root) {
    if (root != NULL) {
        displayInorder(root->left);
        printf("%d ", root->data);
        displayInorder(root->right);
    }
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        } else {
            Node* successor = findSmallest(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice, data, key;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Initial Binary Search Tree (Inorder Traversal):\n");
    displayInorder(root);
    printf("\n");

    while (1) {
        printf("\n\n--- BST Operations Menu ---\n");
        printf("1. Insert an Element\n");
        printf("2. Display Largest Element\n");
        printf("3. Display Smallest Element\n");
        printf("4. Find Height of a Node\n");
        printf("5. Count Leaf Nodes\n");
        printf("6. Delete an Element\n");
        printf("7. Display Inorder Traversal\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("%d inserted successfully.\n", data);
                break;
            case 2:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    printf("Largest element is: %d\n", findLargest(root)->data);
                break;
            case 3:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    printf("Smallest element is: %d\n", findSmallest(root)->data);
                break;
            case 4:
                printf("Enter the node's data to find its height: ");
                scanf("%d", &key);
                {
                    Node* node = search(root, key);
                    if (node != NULL)
                        printf("Height of node %d is: %d\n", key, height(node));
                    else
                        printf("Node %d not found in the tree.\n", key);
                }
                break;
            case 5:
                printf("Total number of leaf nodes: %d\n", countLeaves(root));
                break;
            case 6:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                if (search(root, key) != NULL) {
                    root = deleteNode(root, key);
                    printf("Node %d deleted successfully.\n", key);
                } else {
                    printf("Node %d not found in the tree.\n", key);
                }
                break;
            case 7:
                printf("Current BST (Inorder): ");
                displayInorder(root);
                printf("\n");
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

/*
Initial Binary Search Tree (Inorder Traversal):
20 30 40 50 60 70 80

--- BST Operations Menu ---
1. Insert an Element
2. Display Largest Element
3. Display Smallest Element
4. Find Height of a Node
5. Count Leaf Nodes
6. Delete an Element
7. Display Inorder Traversal
8. Exit
Enter your choice: 6
Enter element to delete: 30
Node 30 deleted successfully.

--- BST Operations Menu ---
7
Current BST (Inorder): 20 40 50 60 70 80
*/