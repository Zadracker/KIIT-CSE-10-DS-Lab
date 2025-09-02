/*
7.1 Write a menu driven program to create a linear queue using array and perform Enqueue, Dequeue,
Traverse, IsEmpty, IsFull operations.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 || front > rear);
}

int isFull() {
    return (rear == MAX - 1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("\nQueue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = value;
    printf("%d enqueued to queue\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("\nQueue Underflow! Cannot dequeue\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[front++]);
    if (front > rear) {  
        front = rear = -1;
    }
}

void traverse() {
    if (isEmpty()) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                traverse();
                break;

            case 4:
                if (isEmpty())
                    printf("\nQueue is Empty\n");
                else
                    printf("\nQueue is not Empty\n");
                break;

            case 5:
                if (isFull())
                    printf("\nQueue is Full\n");
                else
                    printf("\nQueue is not Full\n");
                break;

            case 6:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
