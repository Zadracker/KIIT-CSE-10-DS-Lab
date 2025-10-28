/*
10.4 WAP to create a directed graph using Adjacency Matrix Method and display the degree of each 
vertex.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void printAdjacency(int vertex[MAX][MAX], int num_vertex) {
    printf("\n------Adjacency Matrix------\n\n\t");
    for (int a = 0; a < num_vertex; a++) {
        printf("%d\t", a);
    }
    printf("\n------------------------------------\n");

    for (int k = 0; k < num_vertex; k++) {
        printf("%d|\t", k);
        for (int l = 0; l < num_vertex; l++) {
            printf("%d\t", vertex[k][l]);
        }
        printf("\n");
    }
}

void degree(int vertex[MAX][MAX], int num_vertex) {
    printf("\n------Degree of Each Vertex------\n");
    for (int k = 0; k < num_vertex; k++) {
        int indegree = 0, outdegree = 0;

        for (int l = 0; l < num_vertex; l++) {
            if (vertex[k][l] == 1) {      // outgoing edge from k → l
                outdegree++;
            }
            if (vertex[l][k] == 1) {      // incoming edge to k ← l
                indegree++;
            }
        }

        printf("Vertex %d → In-degree: %d, Out-degree: %d, Total degree: %d\n",
               k, indegree, outdegree, indegree + outdegree);
    }
}

int main() {
    int num_vertex;
    int vertex[MAX][MAX];

    // Initialize adjacency matrix
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            vertex[i][j] = 0;
        }
    }

    printf("Enter the number of vertices you want (max %d): ", MAX);
    scanf("%d", &num_vertex);

    if (num_vertex <= 0 || num_vertex > MAX) {
        printf("Invalid number of vertices.\n");
        return -1;
    }

    printf("\n--Entering Adjacency Information for Directed Graph--\n");
    for (int i = 0; i < num_vertex; i++) {
        for (int j = 0; j < num_vertex; j++) {
            int response;
            printf("edge from %d to %d (1/0)? ", i, j);
            scanf("%d", &response);

            if (response != 0 && response != 1) {
                printf("Invalid input! Must be 0 or 1.\n");
                return -1;
            }
            vertex[i][j] = response;
        }
    }

    printAdjacency(vertex, num_vertex);
    degree(vertex, num_vertex);

    return 0;
}

/*
Output->

Enter the number of vertices you want (max 10): 3

--Entering Adjacency Information for Directed Graph--
edge from 0 to 0 (1/0)? 1
edge from 0 to 1 (1/0)? 0
edge from 0 to 2 (1/0)? 1
edge from 1 to 0 (1/0)? 1
edge from 1 to 1 (1/0)? 1
edge from 1 to 2 (1/0)? 1
edge from 2 to 0 (1/0)? 1
edge from 2 to 1 (1/0)? 0
edge from 2 to 2 (1/0)? 0

------Adjacency Matrix------

        0       1       2
------------------------------------
0|      1       0       1
1|      1       1       1
2|      1       0       0

------Degree of Each Vertex------
Vertex 0 → In-degree: 3, Out-degree: 2, Total degree: 5
Vertex 1 → In-degree: 1, Out-degree: 3, Total degree: 4
Vertex 2 → In-degree: 2, Out-degree: 1, Total degree: 3
*/