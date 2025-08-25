/*
5.1 Write a program to create a double linked list and perform the following menu-based operations on it:
i. insert an element at specific position
ii. delete an element from specific position
iii. Traverse the list
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtPosition(int data, int position) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        if (position == 1) {
            head = newNode;
            printf("Inserted %d at position 1\n", data);
        } else {
            printf("Position out of bounds. List is empty.\n");
        }
        return;
    }

    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        printf("Inserted %d at position 1\n", data);
        return;
    }

    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    printf("Inserted %d at position %d\n", data, position);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        printf("Deleted %d from position 1\n", temp->data);
        free(temp);
        return;
    }

    struct Node* current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position!\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    printf("Deleted %d from position %d\n", current->data, position);
    free(current);
}

void traverseList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = head;
    printf("Double Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, position;
    
    while (1) {
        printf("\n*** Double Linked List Operations ***\n");
        printf("1. Insert an element at a specific position\n");
        printf("2. Delete an element from a specific position\n");
        printf("3. Traverse the list\n");
        printf("4. Exit\n");
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
                deleteAtPosition(position);
                break;
            case 3:
                traverseList();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}