/*
2.2 Write a program to perform the following operations on a given square matrix using functions:
i.   Find the no.of nonzero elements
ii.  Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal
*/

#include <stdio.h>
#define MAX_SIZE 100

void count_nonzero(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    printf("Nonzero elements: %d\n", count);
}

void display_upper_triangular(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j > i) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void display_diagonal_elements(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    printf("Elements just above and below the main diagonal:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == i - 1 || j == i + 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE], size;

    printf("Enter size of the square matrix: ");
    scanf("%d", &size);

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    count_nonzero(matrix, size);
    display_upper_triangular(matrix, size);
    display_diagonal_elements(matrix, size);

    return 0;
}

//Output
/*
Enter elements of the matrix:
1 2 3 4 5 6 7 0 0
Nonzero elements: 7
Upper triangular matrix:
  2 3
    6

Elements just above and below the main diagonal:
  2
4   6
  0
  
  */