/*
3.2 WAP to perform addition of two given sparse matrix in 3–tuple format.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Term;

void readSparseMatrix(Term *matrix, int matrixNumber) {
    int rows, cols, numTerms;
    printf("Enter sparse matrix-%d in 3-tuple format\n", matrixNumber);
    scanf("%d %d %d", &rows, &cols, &numTerms);
    matrix[0].row = rows;
    matrix[0].col = cols;
    matrix[0].value = numTerms;

    for (int i = 1; i <= numTerms; i++) {
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }
}

Term* addSparseMatrices(Term *matrix1, Term *matrix2, int *resultSize) {
    if (matrix1[0].row != matrix2[0].row || matrix1[0].col != matrix2[0].col) {
        printf("Error: Matrices must have the same dimensions for addition.\n");
        *resultSize = 0;
        return NULL;
    }

    int numTerms1 = matrix1[0].value;
    int numTerms2 = matrix2[0].value;
    int i = 1, j = 1, k = 1;
    Term *result = (Term *)malloc(sizeof(Term) * (numTerms1 + numTerms2 + 1));
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        *resultSize = 0;
        return NULL;
    }

    result[0].row = matrix1[0].row;
    result[0].col = matrix1[0].col;

    while (i <= numTerms1 && j <= numTerms2) {
        if (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            result[k++] = matrix1[i++];
        } else if (matrix2[j].row < matrix1[i].row || (matrix2[j].row == matrix1[i].row && matrix2[j].col < matrix1[i].col)) {
            result[k++] = matrix2[j++];
        } else {
            int sum = matrix1[i].value + matrix2[j].value;
            if (sum != 0) {
                result[k].row = matrix1[i].row;
                result[k].col = matrix1[i].col;
                result[k++].value = sum;
            }
            i++;
            j++;
        }
    }

    while (i <= numTerms1) {
        result[k++] = matrix1[i++];
    }

    while (j <= numTerms2) {
        result[k++] = matrix2[j++];
    }

    result[0].value = k - 1;
    *resultSize = k;

    return result;
}

void printSparseMatrix(Term *matrix, int size) {
    if (size <= 0) {
        return;
    }
    printf("Resultant Matrix in 3-tuple format\n");
    for (int i = 0; i < size; i++) {
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    Term matrix1[100]; 
    Term matrix2[100];
    
    readSparseMatrix(matrix1, 1);
    readSparseMatrix(matrix2, 2);

    int resultSize;
    Term *resultMatrix = addSparseMatrices(matrix1, matrix2, &resultSize);
    
    if (resultMatrix) {
        printSparseMatrix(resultMatrix, resultSize);
        free(resultMatrix);
    }

    return 0;
}

/*
Output->

Enter sparse matrix-1 in 3-tuple format
4 5 4
0 3 30
1 1 10
2 3 40
3 4 21
Enter sparse matrix-2 in 3-tuple format
4 5 5
0 2 65
1 1 12
2 3 45
3 3 71
3 4 1
Resultant Matrix in 3-tuple format
4 5 6
0 2 65
0 3 30
1 1 22
2 3 85
3 3 71
3 4 22
*/