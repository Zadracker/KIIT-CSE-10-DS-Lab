/*
8.1 Write a menu driven program to implement Deques (both Inputrestricted and output-restricted) and
performed operations such as Enqueue, Dequeue, Peek, IsEmpty, IsFull using static array.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int arr[MAX];
    int front, rear;
} Deque;

void init(Deque* dq) { dq->front = dq->rear = -1; }
int isFull(Deque* dq) { return ((dq->rear + 1) % MAX == dq->front); }
int isEmpty(Deque* dq) { return (dq->front == -1); }

void enqRear(Deque* dq, int val) {
    if (isFull(dq)) { printf("Overflow!\n"); return; }
    if (isEmpty(dq)) dq->front = dq->rear = 0;
    else dq->rear = (dq->rear + 1) % MAX;
    dq->arr[dq->rear] = val;
    printf("%d added rear\n", val);
}

void enqFront(Deque* dq, int val) {
    if (isFull(dq)) { printf("Overflow!\n"); return; }
    if (isEmpty(dq)) dq->front = dq->rear = 0;
    else dq->front = (dq->front - 1 + MAX) % MAX;
    dq->arr[dq->front] = val;
    printf("%d added front\n", val);
}

void deqFront(Deque* dq) {
    if (isEmpty(dq)) { printf("Underflow!\n"); return; }
    int v = dq->arr[dq->front];
    if (dq->front == dq->rear) init(dq);
    else dq->front = (dq->front + 1) % MAX;
    printf("%d removed front\n", v);
}

void deqRear(Deque* dq) {
    if (isEmpty(dq)) { printf("Underflow!\n"); return; }
    int v = dq->arr[dq->rear];
    if (dq->front == dq->rear) init(dq);
    else dq->rear = (dq->rear - 1 + MAX) % MAX;
    printf("%d removed rear\n", v);
}

void peek(Deque* dq) {
    if (isEmpty(dq)) { printf("Empty!\n"); return; }
    printf("Front: %d | Rear: %d\n", dq->arr[dq->front], dq->arr[dq->rear]);
}

void display(Deque* dq) {
    if (isEmpty(dq)) { printf("Empty!\n"); return; }
    int i = dq->front;
    printf("Deque: ");
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void inputRestricted() {
    Deque dq; init(&dq);
    int c, v;
    while (1) {
        printf("\n1.EnqRear 2.DeqFront 3.DeqRear 4.Peek 5.Empty? 6.Full? 7.Show 8.Back\n");
        scanf("%d", &c);
        switch (c) {
            case 1: printf("Val: "); scanf("%d", &v); enqRear(&dq,v); break;
            case 2: deqFront(&dq); break;
            case 3: deqRear(&dq); break;
            case 4: peek(&dq); break;
            case 5: printf(isEmpty(&dq)?"Empty\n":"Not Empty\n"); break;
            case 6: printf(isFull(&dq)?"Full\n":"Not Full\n"); break;
            case 7: display(&dq); break;
            case 8: return;
            default: printf("Invalid!\n");
        }
    }
}

void outputRestricted() {
    Deque dq; init(&dq);
    int c, v;
    while (1) {
        printf("\n1.EnqFront 2.EnqRear 3.DeqFront 4.Peek 5.Empty? 6.Full? 7.Show 8.Back\n");
        scanf("%d", &c);
        switch (c) {
            case 1: printf("Val: "); scanf("%d", &v); enqFront(&dq,v); break;
            case 2: printf("Val: "); scanf("%d", &v); enqRear(&dq,v); break;
            case 3: deqFront(&dq); break;
            case 4: peek(&dq); break;
            case 5: printf(isEmpty(&dq)?"Empty\n":"Not Empty\n"); break;
            case 6: printf(isFull(&dq)?"Full\n":"Not Full\n"); break;
            case 7: display(&dq); break;
            case 8: return;
            default: printf("Invalid!\n");
        }
    }
}

int main() {
    int c;
    while (1) {
        printf("\n1.Input-Restricted 2.Output-Restricted 3.Exit\n");
        scanf("%d", &c);
        switch (c) {
            case 1: inputRestricted(); break;
            case 2: outputRestricted(); break;
            case 3: exit(0);
            default: printf("Invalid!\n");
        }
    }
}

/*
Output->

1.Input-Restricted 2.Output-Restricted 3.Exit
1

1.EnqRear 2.DeqFront 3.DeqRear 4.Peek 5.Empty? 6.Full? 7.Show 8.Back
1
Val: 10
10 added rear

1.EnqRear 2.DeqFront 3.DeqRear 4.Peek 5.Empty? 6.Full? 7.Show 8.Back
1
Val: 20
20 added rear

1.EnqRear 2.DeqFront 3.DeqRear 4.Peek 5.Empty? 6.Full? 7.Show 8.Back
7
Deque: 10 20 

1.EnqRear 2.DeqFront 3.DeqRear 4.Peek 5.Empty? 6.Full? 7.Show 8.Back
4
Front: 10 | Rear: 20

1.EnqRear 2.DeqFront 3.DeqRear 4.Peek 5.Empty? 6.Full? 7.Show 8.Back
3
20 removed rear

1.EnqRear 2.DeqFront 3.DeqRear 4.Peek 5.Empty? 6.Full? 7.Show 8.Back
2
10 removed front

1.EnqRear 2.DeqFront 3.DeqRear 4.Peek 5.Empty? 6.Full? 7.Show 8.Back
5
Empty


*/