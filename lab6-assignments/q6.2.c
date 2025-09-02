/*
6.2 Write a menu driven program to create a stack using linked list and perform the following operation using function
a. Push
b. Pop
c. IsEmpty
d. display the stack elements
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nStack Overflow! (Memory not available)\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow! Cannot pop\n");
    } else {
        struct Node* temp = top;
        printf("%d popped from stack\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display() {
    if (isEmpty()) {
        printf("\nStack is empty\n");
    } else {
        struct Node* temp = top;
        printf("\nStack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Empty\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                if (isEmpty())
                    printf("\nStack is Empty\n");
                else
                    printf("\nStack is not Empty\n");
                break;

            case 4:
                display();
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
--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Display
5. Exit
Enter your choice: 1
Enter value to push: 10
10 pushed to stack

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Display
5. Exit
Enter your choice: 1
Enter value to push: 20
20 pushed to stack

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Display
5. Exit
Enter your choice: 1
Enter value to push: 30
30 pushed to stack

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Display
5. Exit
Enter your choice: 4

Stack elements: 30 20 10

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Display
5. Exit
Enter your choice: 2
30 popped from stack

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Display
5. Exit
Enter your choice: 4

Stack elements: 20 10

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Display
5. Exit
Enter your choice: 2
20 popped from stack

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Display
5. Exit
Enter your choice: 2
10 popped from stack

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Display
5. Exit
Enter your choice: 3

Stack is Empty

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Display
5. Exit
Enter your choice: 5

Exiting...

*/