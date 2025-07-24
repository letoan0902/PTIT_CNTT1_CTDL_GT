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

void DFSUtil(Graph* graph, int src, int* visited) {
    visited[src] = 1;
    printf("%d ", src);
    for (int i = graph->V - 1; i >= 0; i--) {
        if (graph->adjMatrix[src][i] == 1 && visited[i] == 0) {
            DFSUtil(graph, i, visited);
        }
    }
}


void DFS(Graph* graph, int src) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    printf("Cac dinh duoc duyet theo DFS tu %d: ", src);
    DFSUtil(graph, src, visited);
    free(visited);
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
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    DFS(graph, start);

    return 0;
}