/*
6.1 Write a menu driven program to create a stack using array and perform the following operation using
function
a. Push
b. Pop
c. check stack is empty or not
d. check stack is full or not
e. display stack elements
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("\nStack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow! Cannot pop\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}

void display() {
    if (isEmpty()) {
        printf("\nStack is empty\n");
    } else {
        printf("\nStack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
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
        printf("4. Check if Full\n");
        printf("5. Display\n");
        printf("6. Exit\n");
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
                if (isFull())
                    printf("\nStack is Full\n");
                else
                    printf("\nStack is not Full\n");
                break;

            case 5:
                display();
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

/*
Output

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Check if Full
5. Display
6. Exit
Enter your choice: 1
Enter value to push: 10
10 pushed to stack

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Check if Full
5. Display
6. Exit
Enter your choice: 1
Enter value to push: 20
20 pushed to stack

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Check if Full
5. Display
6. Exit
Enter your choice: 5

Stack elements: 20 10

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Check if Full
5. Display
6. Exit
Enter your choice: 2
20 popped from stack

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Check if Full
5. Display
6. Exit
Enter your choice: 3

Stack is not Empty

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Check if Full
5. Display
6. Exit
Enter your choice: 2
10 popped from stack

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Check if Full
5. Display
6. Exit
Enter your choice: 3

Stack is Empty

--- Stack Menu ---
1. Push
2. Pop
3. Check if Empty
4. Check if Full
5. Display
6. Exit
Enter your choice: 6

Exiting...

*/