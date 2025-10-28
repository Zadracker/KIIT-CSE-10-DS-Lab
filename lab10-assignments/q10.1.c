/*
10.1 WAP to create an un-directed graph using Adjacency Matrix Method and display the degree of 
each vertex.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void printAdjacency(int vertex[MAX][MAX], int num_vertex){
    printf("\n------Adjacency Matrix------\n");
    printf("\n\t");
    for(int a=0; a<num_vertex; a++){
        printf("%d\t",a);
    }
    printf("\n------------------------------------\n");
    for (int k=0; k<num_vertex; k++){
        printf("%d|\t",k);
        for(int l=0; l<num_vertex; l++){
            printf("%d \t",vertex[k][l]);
        } printf("\n");
    }
}

void degree(int vertex[MAX][MAX], int num_vertex){ 
    for (int k=0; k<num_vertex; k++){
        int degree=0;
        for(int l=0; l<num_vertex; l++){
            if(vertex[k][l]==1){++degree;};
        } printf("\n");
        printf("degree of %d is %d\t",k,degree);
    }
}

int main(){
    int num_vertex;
    int vertex[MAX][MAX];

    for (int i=0; i<MAX; i++) {
        for(int j=0; j<MAX; j++){
            vertex[i][j] = 0;
        }
    }

    printf("Enter the number of vertices you want (max %d): ", MAX);
    scanf("%d",&num_vertex);

    if (num_vertex <= 0 || num_vertex > MAX) {
        printf("Invalid number of vertices.\n");
        return -1;
    }

    printf("\n--Entering Adjacency Information--\n");
    for (int i=0; i<num_vertex; i++){
        for(int j=i; j<num_vertex; j++){
            int response;
            printf("Is %d adjacent to %d (1/0)? ", i, j);
            scanf("%d",&response);
            if (response != 0 && response != 1) {
                printf("Invalid input! Must be 0 or 1.\n");
                return -1;
            }
            if (response == 1){
                vertex[i][j] = 1;
                if (i != j) {
                    vertex[j][i] = 1;
                }
            } 
        }
    }

    printAdjacency(vertex, num_vertex);
    degree(vertex, num_vertex);

    return 0;
}

//Output
/*
Enter the number of vertices you want (max 10): 3

--Entering Adjacency Information--
Is 0 adjacent to 0 (1/0)? 0
Is 0 adjacent to 1 (1/0)? 1
Is 0 adjacent to 2 (1/0)? 1
Is 1 adjacent to 1 (1/0)? 0
Is 1 adjacent to 2 (1/0)? 0
Is 2 adjacent to 2 (1/0)? 0

------Adjacency Matrix------

        0       1       2
------------------------------------
0|      0       1       1
1|      1       0       0
2|      1       0       0

degree of 0 is 2
degree of 1 is 1
degree of 2 is 1

*/