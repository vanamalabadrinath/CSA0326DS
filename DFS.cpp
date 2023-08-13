#include <stdio.h>
#include <stdlib.h>
void DFS(int** graph, int* visited, int vertices, int currentVertex) {
    int i;
    printf("%d ", currentVertex);
    visited[currentVertex] = 1;
    for (i = 0; i < vertices; i++) {
        if (graph[currentVertex][i] && !visited[i]) {
            DFS(graph, visited, vertices, i);
        }
    }
}
int main() {
    int i, j, vertices, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (i = 0; i < vertices; i++) {
        graph[i] = (int*)malloc(vertices * sizeof(int));
    }
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);
    int* visited = (int*)malloc(vertices * sizeof(int));
    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    printf("Depth First Search (DFS) traversal:\n");
    DFS(graph, visited, vertices, startVertex);
    printf("\n");
    for (i = 0; i < vertices; i++){
        free(graph[i]);
    }
    free(graph);
    free(visited);
    return 0;
}

