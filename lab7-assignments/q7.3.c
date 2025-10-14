/*
7.3 Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue,
Traverse, IsEmpty, IsFull using array.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((rear + 1) % MAX == front);
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is FULL! Cannot insert %d\n", data);
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = data;
    printf("%d inserted into queue.\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
        return;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("%d removed from queue.\n", data);
}

void traverse() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Check Empty\n");
        printf("5. Check Full\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
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
                if (isEmpty()) printf("Queue is EMPTY.\n");
                else printf("Queue is NOT empty.\n");
                break;
            case 5:
                if (isFull()) printf("Queue is FULL.\n");
                else printf("Queue is NOT full.\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

/*
Output->

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check Empty
5. Check Full
6. Exit
Enter choice: 1
Enter value to enqueue: 10
10 inserted into queue.

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check Empty
5. Check Full
6. Exit
Enter choice: 1
Enter value to enqueue: 20
20 inserted into queue.

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check Empty
5. Check Full
6. Exit
Enter choice: 1
Enter value to enqueue: 30
30 inserted into queue.

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check Empty
5. Check Full
6. Exit
Enter choice: 3
Queue elements: 10 20 30 

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check Empty
5. Check Full
6. Exit
Enter choice: 2
10 removed from queue.

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check Empty
5. Check Full
6. Exit
Enter choice: 3
Queue elements: 20 30 

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check Empty
5. Check Full
6. Exit
Enter choice: 1
Enter value to enqueue: 40
40 inserted into queue.

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check Empty
5. Check Full
6. Exit
Enter choice: 1
Enter value to enqueue: 50
50 inserted into queue.

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check Empty
5. Check Full
6. Exit
Enter choice: 1
Enter value to enqueue: 60
Queue is FULL! Cannot insert 60

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check Empty
5. Check Full
6. Exit
Enter choice: 5
Queue is FULL.

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check Empty
5. Check Full
6. Exit
Enter choice: 3
Queue elements: 20 30 40 50 

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Traverse
4. Check Empty
5. Check Full
6. Exit
Enter choice: 6

*/