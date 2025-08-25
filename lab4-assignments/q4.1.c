/*
4.1 Write a program to create a single linked list of n nodes and perform the following menu-based operations on 
it using function:
i. Insert a node at specific position
ii. Deletion of an element from specific position
iii. Count nodes
iv. Traverse the linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct  Node {
    int data;
    Node* next;
}Node;

Node* head = NULL;

void createList(int n) {
    int data, i;
    Node *newNode, *temp;

    head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

void insertAtPosition(int data, int position) {
    int i;
    Node *newNode, *temp;

    newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at position 1.\n");
        return;
    }

    temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", position);
}

void deleteFromPosition(int position) {
    int i;
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    temp = head;
    if (position == 1) {
        head = head->next;
        free(temp);
        printf("Node deleted from position 1.\n");
        return;
    }

    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", position);
}

int countNodes() {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes: %d\n", count);
    return count;
}

void traverseList() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, choice, data, position;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    createList(n);

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Count nodes\n");
        printf("4. Traverse the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 2:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 3:
                countNodes();
                break;
            case 4:
                traverseList();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

/*
Output->

Enter the number of nodes to create: 3
Enter data for node 1: 12
Enter data for node 2: 55
Enter data for node 3: 22

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Exit
Enter your choice: 1
Enter data to insert: 32
Enter position to insert at: 2
Node inserted at position 2.

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Exit
Enter your choice: 2
Enter position to delete from: 1
Node deleted from position 1.

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Exit
Enter your choice: 3
Total number of nodes: 3

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Exit
Enter your choice: 4
Linked list: 32 -> 55 -> 22 -> NULL

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Exit
Enter your choice: 5
Exiting program.
*/