/*
8.2 Write a menu driven program to implement priority queue operations such as Enqueue, Dequeue, 
Traverse using linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
} PriorityQueue;

void initQueue(PriorityQueue* q) {
    q->front = NULL;
}

int isEmpty(PriorityQueue* q) {
    return (q->front == NULL);
}

void enqueue(PriorityQueue* q, int value, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("\nMemory allocation failed! Cannot enqueue %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;
    if (isEmpty(q) || priority < q->front->priority) {
        newNode->next = q->front;
        q->front = newNode;
    } else {
        Node* temp = q->front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("%d enqueued with priority %d\n", value, priority);
}

void dequeue(PriorityQueue* q) {
    if (isEmpty(q)) {
        printf("\nQueue Underflow! Cannot dequeue\n");
        return;
    }
    Node* temp = q->front;
    printf("%d dequeued (priority %d)\n", temp->data, temp->priority);
    q->front = q->front->next;
    free(temp);
}

void traverse(PriorityQueue* q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nPriority Queue elements:\n");
    Node* temp = q->front;
    while (temp != NULL) {
        printf("Value: %d | Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    PriorityQueue q;
    initQueue(&q);
    int choice, value, priority;
    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Check if Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(&q, value, priority);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                traverse(&q);
                break;
            case 4:
                printf(isEmpty(&q) ? "\nQueue is Empty\n" : "\nQueue is not Empty\n");
                break;

            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

/*
Output->

--- Priority Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 1
Enter value to enqueue: 50
Enter priority: 2
50 enqueued with priority 2

--- Priority Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 1
Enter value to enqueue: 30
Enter priority: 1
30 enqueued with priority 1

--- Priority Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 1
Enter value to enqueue: 70
Enter priority: 3
70 enqueued with priority 3

--- Priority Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 3

Priority Queue elements:
Value: 30 | Priority: 1
Value: 50 | Priority: 2
Value: 70 | Priority: 3

--- Priority Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 2
30 dequeued (priority 1)

--- Priority Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 3

Priority Queue elements:
Value: 50 | Priority: 2
Value: 70 | Priority: 3

--- Priority Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 4
Queue is not Empty

--- Priority Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 5

Exiting...

*/