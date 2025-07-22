#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct Queue {
    Node **arr;
    int front;
    int rear;
    int size;
}Queue;

Queue *createQueue(int size) {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->arr = (Node **)malloc(size * sizeof(Node *));
    newQueue->front = 0;
    newQueue->rear = -1;
    newQueue->size = size;
    return newQueue;
}

void enqueue(Queue *queue, Node *node) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->arr[++queue->rear] = node;
}

int isEmpty(Queue *queue) {
    return queue->front > queue->rear;
}

Node* dequeue(Queue *queue) {
    if (queue->front > queue->rear) return NULL;
    return queue->arr[queue->front++];
}

Node* insert(Node* root, int data) {
    Node *newNode = createNode(data);
    if (root == NULL) return newNode;

    Queue *queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        Node *current = queue->arr[queue->front++];

        if (current->left == NULL) {
            current->left = newNode;
            break;
        } else {
            enqueue(queue, current->left);
        }

        if (current->right == NULL) {
            current->right = newNode;
            break;
        } else {
            enqueue(queue, current->right);
        }
    }
    return root;
}

void levelorderBFS(Node* root) {
    if (root == NULL) return;

    Queue *queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue)) {

        Node *node = queue->arr[queue->front++];
        printf("%d ",node->data);

        if (node->left != NULL) {
            enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
        }
    }
}

int main(void) {
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;

    printf("truoc khi them: ");
    levelorderBFS(root);
    printf("\nSau khi them: ");
    insert(root,6);
    levelorderBFS(root);
    return 0;
}