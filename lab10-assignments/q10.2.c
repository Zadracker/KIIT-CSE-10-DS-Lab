/*
10.2 In addition to 10.1, display DFS traversal sequence of the undirected graph.
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
// ----------------------------------------------------------------------
// NEW IMPLEMENTATION FOR DFS
// ----------------------------------------------------------------------

// Recursive DFS function
void DFS_recursive(int vertex[MAX][MAX], int num_vertex, int start_vertex, int visited[MAX]) {
    // 1. Mark the current vertex as visited
    visited[start_vertex] = 1;
    
    // 2. Print the vertex (traversal sequence)
    printf("%d -> ", start_vertex);

    // 3. Recur for all adjacent vertices
    for (int j = 0; j < num_vertex; j++) {
        // Check if there is an edge (vertex[start_vertex][j] == 1) 
        // AND the adjacent vertex has not been visited (!visited[j])
        if (vertex[start_vertex][j] == 1 && !visited[j]) {
            DFS_recursive(vertex, num_vertex, j, visited);
        }
    }
}

// DFS Traversal Wrapper Function
void DFS_traversal(int vertex[MAX][MAX], int num_vertex) {
    // Array to keep track of visited vertices, initialized to 0 (not visited)
    int visited[MAX] = {0};
    int start_node = 0; // Start traversal from vertex 0

    printf("\n---DFS Traversal Sequence (Starting from 0)---\n");
    
    // In case the graph is disconnected, we loop through all vertices to ensure all components are traversed.
    for (int i = 0; i < num_vertex; i++) {
        if (!visited[i]) {
            DFS_recursive(vertex, num_vertex, i, visited);
        }
    }
    
    // Clean up the output formatting
    printf("END\n");
}

// ----------------------------------------------------------------------

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
            if (scanf("%d",&response) != 1 || (response != 0 && response != 1)) {
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
    
    // Call the new DFS traversal function
    DFS_traversal(vertex, num_vertex); 

    return 0;
}

//Output
/*
Enter the number of vertices you want (max 10): 5

--Entering Adjacency Information--
Is 0 adjacent to 0 (1/0)? 0
Is 0 adjacent to 1 (1/0)? 1
Is 0 adjacent to 2 (1/0)? 1
Is 0 adjacent to 3 (1/0)? 1
Is 0 adjacent to 4 (1/0)? 0
Is 1 adjacent to 1 (1/0)? 0
Is 1 adjacent to 2 (1/0)? 0
Is 1 adjacent to 3 (1/0)? 0
Is 1 adjacent to 4 (1/0)? 1
Is 2 adjacent to 2 (1/0)? 0
Is 2 adjacent to 3 (1/0)? 1
Is 2 adjacent to 4 (1/0)? 0
Is 3 adjacent to 3 (1/0)? 0
Is 3 adjacent to 4 (1/0)? 1
Is 4 adjacent to 4 (1/0)? 0

------Adjacency Matrix------

        0       1       2       3       4
------------------------------------
0|      0       1       1       1       0
1|      1       0       0       0       1
2|      1       0       0       1       0
3|      1       0       1       0       1
4|      0       1       0       1       0

degree of 0 is 3
degree of 1 is 2
degree of 2 is 2
degree of 3 is 3
degree of 4 is 2
---DFS Traversal Sequence (Starting from 0)---
0 -> 1 -> 4 -> 3 -> 2 -> END

*/