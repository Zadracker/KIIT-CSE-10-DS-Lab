/*
2.3 WAP to represent a given sparse matrix in 3-tuple format using 2-D array. 
*/

#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int sparse_matrix[MAX_SIZE][MAX_SIZE], rows, cols;
    int tuple[MAX_SIZE][3];
    int nonzero_count = 0;

    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &sparse_matrix[i][j]);
            if (sparse_matrix[i][j] != 0) {
                tuple[nonzero_count][0] = i;
                tuple[nonzero_count][1] = j;
                tuple[nonzero_count][2] = sparse_matrix[i][j];
                nonzero_count++;
            }
        }
    }

    printf("Sparse matrix in 3-tuple format:\n");
    printf("%d   %d   %d\n", rows, cols, nonzero_count);
    for (int i = 0; i < nonzero_count; i++) {
        printf("%d   %d   %d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
    return 0;
}

//Output
/*

Enter size of the sparse matrix: 4 5                                          
Enter elements of sparse matrix:
0 0 33 0 0 0 17 0 0 0 0 0 0 46 0 0 0 0 0 51
Sparse matrix in 3-tuple format:
4   5   4
0   2   33
1   1   17
2   3   46
3   4   51


*/