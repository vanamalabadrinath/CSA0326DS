#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int front, rear;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

void enqueue(Queue* queue, int item) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full.\n");
        return;
    }
    queue->array[++queue->rear] = item;
    if (queue->front == -1) {
        queue->front = 0;
    }
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

void BFS(int** graph, int vertices, int startVertex) {
    int i, currentVertex;
    int* visited = (int*)malloc(vertices * sizeof(int));
    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    Queue* queue = createQueue(vertices);
    visited[startVertex] = 1;
    enqueue(queue, startVertex);
    printf("Breadth First Search (BFS) traversal:\n");
    while (!isEmpty(queue)) {
        currentVertex = dequeue(queue);
        printf("%d ", currentVertex);
        for (i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    printf("\n");
    free(visited);
    free(queue->array);
    free(queue);
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
    BFS(graph, vertices, startVertex);
    for (i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}

