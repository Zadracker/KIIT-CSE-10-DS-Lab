/*
9.1 Write a program to create a binary search tree of n data elements using linked list and 
perform the following menu driven operations:
i. preorder traversal
ii. postorder traversal
iii. inorder traversal
iv. search an element
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key > root->data) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

int main() {
    Node* root = NULL;
    int choice, key;
    root = insert(root, 50);    root = insert(root, 30);    root = insert(root, 20);
    root = insert(root, 40);    root = insert(root, 70);    root = insert(root, 60);
    root = insert(root, 80);

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Preorder Traversal\n");
        printf("2. Postorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Search an element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 2:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("%d found in the tree\n", key);
                } else {
                    printf("%d not found in the tree\n", key);
                }
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

/*
Output->

--- Binary Search Tree Menu ---
1. Preorder Traversal
2. Postorder Traversal
3. Inorder Traversal
4. Search an element
5. Exit
Enter your choice: 1
Preorder Traversal: 50 30 20 40 70 60 80 

--- Binary Search Tree Menu ---
1. Preorder Traversal
2. Postorder Traversal
3. Inorder Traversal
4. Search an element
5. Exit
Enter your choice: 2
Postorder Traversal: 20 40 30 60 80 70 50 

--- Binary Search Tree Menu ---
1. Preorder Traversal
2. Postorder Traversal
3. Inorder Traversal
4. Search an element
5. Exit
Enter your choice: 3
Inorder Traversal: 20 30 40 50 60 70 80 

--- Binary Search Tree Menu ---
1. Preorder Traversal
2. Postorder Traversal
3. Inorder Traversal
4. Search an element
5. Exit
Enter your choice: 4
Enter value to search: 60
60 found in the tree

--- Binary Search Tree Menu ---
1. Preorder Traversal
2. Postorder Traversal
3. Inorder Traversal
4. Search an element
5. Exit
Enter your choice: 5
Exiting program.

*/