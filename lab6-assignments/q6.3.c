/*
6.3 Write a program to convert infix expression to postfix expression using stack.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isDigit(ch)) {
            postfix[k++] = ch;
            if (!isDigit(infix[i])) {
                postfix[k++] = ' ';
            }
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != -1 && peek() != '(') {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            pop();
        }
        else {
            while (peek() != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            push(ch);
        }
    }

    while (peek() != -1) {
        postfix[k++] = pop();
        postfix[k++] = ' ';
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}



/*
Enter infix expression: 3+5*2
Postfix expression: 3 5 2 * +

Enter infix expression: (3+12)*4
Postfix expression: 3 12 + 4 *
*/