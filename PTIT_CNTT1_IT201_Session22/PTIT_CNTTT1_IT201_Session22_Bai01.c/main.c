#include <stdio.h>
#include <stdlib.h>

int** createGraph(int n) {
    int** graph = (int**)malloc(sizeof(int*) * n);
    for (int i=0; i<n; i++) {
        graph[i] = (int*)malloc(sizeof(int) * n);
        for (int j=0; j<n; j++) {
            graph[i][j] = 0;
        }
    }
    return graph;
}
void addEdge(int** graph, int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}
void printGraph(int** graph, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("nhap so dinh: ");
    scanf("%d", &n);
    int** graph = createGraph(n);
    int start,end;
    while (scanf("%d %d",&start, &end) == 2) {
        addEdge(graph, start, end);
    }
    printGraph(graph, n);
    return 0;
}