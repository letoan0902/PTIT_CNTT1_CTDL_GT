#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* matrixToList(int matrix[100][100], int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->adjLists = (Node**)malloc(n * sizeof(Node*));

    for (int i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                Node* newNode = createNode(j);
                newNode->next = graph->adjLists[i];
                graph->adjLists[i] = newNode;
            }
        }
    }

    return graph;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("%d:", i);
        while (temp) {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    int n;
    printf("nhap so dinh: ");
    scanf("%d", &n);

    int matrix[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    Graph* graph = matrixToList(matrix, n);
    printGraph(graph);

    return 0;
}