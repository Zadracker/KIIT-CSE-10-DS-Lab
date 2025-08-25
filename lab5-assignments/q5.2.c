/*
5.2 Write a program to create a circular linked list and display the elements of the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createCircularList(int n) {
    if (n <= 0) {
        printf("Number of nodes must be positive.\n");
        return;
    }

    struct Node* newNode;
    struct Node* temp;
    int data;

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    head->data = data;
    head->next = head;
    temp = head;

    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        
        newNode->data = data;
        newNode->next = head;
        temp->next = newNode;
        temp = newNode;       
    }
    printf("Circular linked list with %d nodes created successfully.\n", n);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Elements of the circular linked list: ");
    
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("... (back to start)\n");
}

int main() {
    int n;
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    
    createCircularList(n);
    displayList();
    
    return 0;
}