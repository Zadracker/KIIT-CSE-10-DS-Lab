/*
4.2 In addition to 4.1, perform following operations using function on the single linked list:
 i. search an element in the list
ii. sort the list in ascending order
iii. reverse the list
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createList(int n) {
    int data, i;
    struct Node *newNode, *temp;

    head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
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
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
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

void searchElement(int key) {
    int position = 1;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list.\n", key);
}

void sortList() {
    struct Node *current = head, *index = NULL;
    int temp_data;

    if (head == NULL) {
        printf("List is empty. Cannot sort.\n");
        return;
    } else {
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    temp_data = current->data;
                    current->data = index->data;
                    index->data = temp_data;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
    printf("List sorted in ascending order.\n");
}

void reverseList() {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("List reversed.\n");
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
    int n, choice, data, position, key;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    createList(n);

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Count nodes\n");
        printf("4. Traverse the list\n");
        printf("5. Search for an element\n");
        printf("6. Sort the list\n");
        printf("7. Reverse the list\n");
        printf("8. Exit\n");
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
                printf("Enter element to search for: ");
                scanf("%d", &key);
                searchElement(key);
                break;
            case 6:
                sortList();
                break;
            case 7:
                reverseList();
                break;
            case 8:
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

Enter the number of nodes to create: 7
Enter data for node 1: 17
Enter data for node 2: 23
Enter data for node 3: 47
Enter data for node 4: 11
Enter data for node 5: 78
Enter data for node 6: 92
Enter data for node 7: 51

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Search for an element
6. Sort the list
7. Reverse the list
8. Exit
Enter your choice: 1
Enter data to insert: 68
Enter position to insert at: 4
Node inserted at position 4.

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Search for an element
6. Sort the list
7. Reverse the list
8. Exit
Enter your choice: 2
Enter position to delete from: 1
Node deleted from position 1.

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Search for an element
6. Sort the list
7. Reverse the list
8. Exit
Enter your choice: 3
Total number of nodes: 7

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Search for an element
6. Sort the list
7. Reverse the list
8. Exit
Enter your choice: 4
Linked list: 23 -> 47 -> 68 -> 11 -> 78 -> 92 -> 51 -> NULL

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Search for an element
6. Sort the list
7. Reverse the list
8. Exit
Enter your choice: 5
Enter element to search for: 92
Element 92 found at position 6.

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Search for an element
6. Sort the list
7. Reverse the list
8. Exit
Enter your choice: 6
List sorted in ascending order.

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Search for an element
6. Sort the list
7. Reverse the list
8. Exit
Enter your choice: 4
Linked list: 11 -> 23 -> 47 -> 51 -> 68 -> 78 -> 92 -> NULL

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Search for an element
6. Sort the list
7. Reverse the list
8. Exit
Enter your choice: 7
List reversed.

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Search for an element
6. Sort the list
7. Reverse the list
8. Exit
Enter your choice: 4
Linked list: 92 -> 78 -> 68 -> 51 -> 47 -> 23 -> 11 -> NULL

--- Menu ---
1. Insert a node
2. Delete a node
3. Count nodes
4. Traverse the list
5. Search for an element
6. Sort the list
7. Reverse the list
8. Exit
Enter your choice: 8
Exiting program.
*/