/*
3.3 WAP to represent the polynomial of single variable using 1-D array and perform the addition of two polynomial 
equations.
*/

#include <stdio.h>
#include <stdlib.h>

void add_polynomials(int poly1[], int poly2[], int result[], int degree) {
    for (int i = 0; i <= degree; i++) {
        result[i] = poly1[i] + poly2[i];
    }
}

void print_polynomial(int poly[], int degree) {
    int first_term_printed = 0;
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (first_term_printed) {
                printf("+");
            }

            if (i == 0) {
                printf("%d", poly[i]);
            } else if (poly[i] == 1) {
                printf("x^%d", i);
            } else {
                printf("%dx^%d", poly[i], i);
            }
            first_term_printed = 1;
        }
    }
    if (!first_term_printed) {
        printf("0");
    }
    printf("\n");
}

int main() {
    int max_degree;

    printf("Enter maximum degree of x: ");
    scanf("%d", &max_degree);

    int *poly1 = (int *)malloc((max_degree + 1) * sizeof(int));
    int *poly2 = (int *)malloc((max_degree + 1) * sizeof(int));
    int *result = (int *)malloc((max_degree + 1) * sizeof(int));

    if (poly1 == NULL || poly2 == NULL || result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter Polynomial-1 from lowest degree to highest degree: ");
    for (int i = 0; i <= max_degree; i++) {
        scanf("%d", &poly1[i]);
    }

    printf("Enter Polynomial-2 from lowest degree to highest degree: ");
    for (int i = 0; i <= max_degree; i++) {
        scanf("%d", &poly2[i]);
    }

    add_polynomials(poly1, poly2, result, max_degree);

    printf("\nResultant Polynomial: ");
    print_polynomial(result, max_degree);

    free(poly1);
    free(poly2);
    free(result);

    return 0;
}

/*
Output ->

Enter maximum degree of x: 2
Enter Polynomial-1 from lowest degree to highest degree: 4 2 3
Enter Polynomial-2 from lowest degree to highest degree: 6 5 2

Resultant Polynomial: 5x^2+7x^1+10
*/