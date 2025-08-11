/*
3.1 WAP to perform transpose of a given sparse matrix in 3-tuple format.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Tuple;

void transposeSparseMatrix(Tuple* original, Tuple* transposed) {
    int num_elements = original[0].value;
    int original_rows = original[0].row;
    int original_cols = original[0].col;

    transposed[0].row = original_cols;
    transposed[0].col = original_rows;
    transposed[0].value = num_elements;

    if (num_elements > 0) {
        int q = 1; 
        for (int i = 0; i < original_cols; i++) { 
            for (int j = 1; j <= num_elements; j++) {
                if (original[j].col == i) {
                    transposed[q].row = original[j].col;
                    transposed[q].col = original[j].row;
                    transposed[q].value = original[j].value;
                    q++;
                }
            }
        }
    }
}

void printSparseMatrix(Tuple* matrix, int size) {
    if (size <= 0) {
        printf("Empty matrix.\n");
        return;
    }
    printf("R C Element\n");
    for (int i = 0; i < size; i++) {
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    int original_size = 5;
    Tuple original_matrix[5] = {
        {4, 5, 4},
        {0, 2, 33},
        {1, 1, 17},
        {2, 3, 46},
        {3, 4, 51}
    };

    printf("Sparse matrix in 3-tuple format:\n");
    printSparseMatrix(original_matrix, original_size);

    Tuple transposed_matrix[original_size];

    transposeSparseMatrix(original_matrix, transposed_matrix);

    printf("\nTranspose of sparse matrix:\n");
    printSparseMatrix(transposed_matrix, original_size);

    return 0;
}

/*
Output->

Sparse matrix in 3-tuple format:
R C Element
4 5 4
0 2 33
1 1 17
2 3 46
3 4 51

Transpose of sparse matrix:
R C Element
5 4 4
1 1 17
2 0 33
3 2 46
4 3 51

*/