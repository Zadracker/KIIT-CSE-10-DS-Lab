/*
5.3 Write a program to represent the given sparse matrix using header single linked list and display it.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row, col, val;
    struct Node *next;
} Node;

Node* createNode(int row, int col, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int row, int col, int val) {
    Node *newNode = createNode(row, col, val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displaySparse(Node *head, int rows, int cols, int nonZero) {
    printf("\nsparse matrix in 3-tuple format\n");
    printf("%d   %d   %d\n", rows, cols, nonZero);

    Node *temp = head;
    while (temp != NULL) {
        printf("%d   %d   %d\n", temp->row, temp->col, temp->val);
        temp = temp->next;
    }
}

int main() {
    int rows, cols;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter elements of sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    Node *head = NULL;
    int nonZero = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                insertNode(&head, i, j, matrix[i][j]);
                nonZero++;
            }
        }
    }

    displaySparse(head, rows, cols, nonZero);

    return 0;
}
