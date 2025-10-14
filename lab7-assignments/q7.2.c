/*
7.2 Write a menu driven program to implement linear queue operations such as Enqueue, Dequeue,
IsEmpty, Traverse using single linked list.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q) {
    return (q->front == NULL);
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("\nMemory allocation failed! Cannot enqueue %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue Underflow!\n");
        return;
    }

    Node* temp = q->front;
    printf("%d dequeued from queue\n", temp->data);
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void traverse(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue elements: ");
    Node* temp = q->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
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
                enqueue(&q, value);
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

--- Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 4

Queue is Empty

--- Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 1
Enter value to enqueue: 1
1 enqueued to queue

--- Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 1
Enter value to enqueue: 2
2 enqueued to queue

--- Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 3

Queue elements: 1 2

--- Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check if Empty
5. Exit
Enter your choice: 5

Exiting...
*/