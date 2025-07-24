#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **adjMatrix;
} Graph;

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

typedef struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (int*)malloc(capacity * sizeof(int));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

void enQueue(Queue* queue, int value) {
    if (queue->rear == queue->capacity - 1) {
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = value;
}

int isQueueEmpty(Queue* queue) {
    if (queue->front > queue->rear) {
        return 1;
    }
    return 0;
}

int deQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }
    return queue->arr[queue->front++];
}

void BFS(Graph* graph, int src) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    visited[src] = 1;
    Queue* queue = createQueue(graph->V);
    enQueue(queue, src);

    printf("Cac dinh duoc duyet theo BFS tu %d: ", src);

    while (!isQueueEmpty(queue)) {
        int currentNode = deQueue(queue);
        printf("%d ", currentNode);
        for (int i = 0; i < graph->V; i++) {
            if (graph->adjMatrix[currentNode][i] == 1 && visited[i] == 0) {
                enQueue(queue, i);
                visited[i] = 1;
            }
        }
    }

    free(visited);
    free(queue->arr);
    free(queue);
}

int main() {
    int v, e;
    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);

    Graph* graph = createGraph(v);

    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(graph, u, w);
    }

    int start;
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    BFS(graph, start);

    return 0;
}