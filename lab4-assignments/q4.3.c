/*
4.3 Write a program to represent the polynomial equation of single variable using single linked list and perform 
the addition of two polynomial equations.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int power;
    struct Node* next;
} Node;

Node* createNode(int coeff, int power) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(Node** head_ref, int coeff, int power) {
    if (coeff == 0) {
        return;
    }

    Node* newNode = createNode(coeff, power);
    Node* current = *head_ref;
    Node* prev = NULL;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (current != NULL && current->power > power) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newNode->next = *head_ref;
        *head_ref = newNode;
    }
    else {
        newNode->next = current;
        prev->next = newNode;
    }
}

void displayPolynomial(Node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        if (current->coeff != 0) {
            printf("%dx^%d", current->coeff, current->power);
        }

        if (current->next != NULL && current->next->coeff != 0) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp_poly1 = poly1;
    Node* temp_poly2 = poly2;

    while (temp_poly1 != NULL && temp_poly2 != NULL) {
        if (temp_poly1->power > temp_poly2->power) {
            insertTerm(&result, temp_poly1->coeff, temp_poly1->power);
            temp_poly1 = temp_poly1->next;
        }
        else if (temp_poly2->power > temp_poly1->power) {
            insertTerm(&result, temp_poly2->coeff, temp_poly2->power);
            temp_poly2 = temp_poly2->next;
        }
        else {
            int sum_coeff = temp_poly1->coeff + temp_poly2->coeff;
            insertTerm(&result, sum_coeff, temp_poly1->power);
            temp_poly1 = temp_poly1->next;
            temp_poly2 = temp_poly2->next;
        }
    }

    while (temp_poly1 != NULL) {
        insertTerm(&result, temp_poly1->coeff, temp_poly1->power);
        temp_poly1 = temp_poly1->next;
    }

    while (temp_poly2 != NULL) {
        insertTerm(&result, temp_poly2->coeff, temp_poly2->power);
        temp_poly2 = temp_poly2->next;
    }
    
    return result;
}

void freePolynomial(Node* head) {
    Node* current = head;
    Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    int maxPower1, maxPower2;
    int coeff, i;

    printf("Polynomial-1:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &maxPower1);

    for (i = maxPower1; i >= 0; i--) {
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0) {
            insertTerm(&poly1, coeff, i);
        }
    }

    printf("\nPolynomial-2:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &maxPower2);

    for (i = maxPower2; i >= 0; i--) {
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0) {
            insertTerm(&poly2, coeff, i);
        }
    }
    
    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    Node* sum = addPolynomials(poly1, poly2);
    printf("\nSum: ");
    displayPolynomial(sum);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);

    return 0;
}


/*
Output->

Polynomial-1:
Enter the Maximum power of x: 2
Enter the coefficient of degree 2: 4
Enter the coefficient of degree 1: 3
Enter the coefficient of degree 0: 0

Polynomial-2:
Enter the Maximum power of x: 3 
Enter the coefficient of degree 3: 5
Enter the coefficient of degree 2: 4
Enter the coefficient of degree 1: 6
Enter the coefficient of degree 0: 10

Polynomial 1: 4x^2 + 3x^1
Polynomial 2: 5x^3 + 4x^2 + 6x^1 + 10x^0

Sum: 5x^3 + 8x^2 + 9x^1 + 10x^0
*/