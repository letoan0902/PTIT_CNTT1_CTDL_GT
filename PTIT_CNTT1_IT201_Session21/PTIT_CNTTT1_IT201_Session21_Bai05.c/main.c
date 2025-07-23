#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=  data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* g[], int start, int end) {
    Node* newNode1 = createNode(end);
    newNode1->next = g[start];
    g[start] = newNode1;

    Node* newNode2 = createNode(start);
    newNode2->next = g[end];
    g[end] = newNode2;
}

void print(Node* g[], int n) {
    for (int i=0; i<n;i++) {
        Node* temp = g[i];

        while (temp != NULL) {
            printf("%d",temp->data);
            if (temp->next != NULL) {
                printf("->");
            }
            temp = temp->next;
        }
        printf("->NULL\n");
    }
}

int main() {
    int n = 3;
    Node* graph[n];
    for (int i = 0; i < n; i++)
        graph[i] = NULL;

    addEdge(graph, 1, 2);
    print(graph, n);
    printf("\n");

    addEdge(graph, 0, 1);
    print(graph, n);

    return 0;
}