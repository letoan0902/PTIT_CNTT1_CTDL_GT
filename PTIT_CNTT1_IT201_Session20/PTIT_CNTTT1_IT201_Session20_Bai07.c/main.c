#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

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
} Queue;

Queue* createQueue(int size) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (Node**)malloc(size * sizeof(Node*));
    queue->front = 0;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

void enqueue(Queue *queue, Node *node) {
    if (queue->rear == queue->size - 1) return;
    queue->arr[++queue->rear] = node;
}

int isEmpty(Queue *queue) {
    return queue->front > queue->rear;
}

Node* dequeue(Queue *queue) {
    if (isEmpty(queue)) return NULL;
    return queue->arr[queue->front++];
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) return NULL;

    Queue* queue = createQueue(100);
    enqueue(queue, root);

    Node* target = NULL;
    Node* lastNode = NULL;
    Node* lastParent = NULL;

    while (!isEmpty(queue)) {
        Node* current = dequeue(queue);
        if (current->data == data) {
            target = current;
        }

        if (current->left != NULL) {
            enqueue(queue, current->left);
            lastParent = current;
            lastNode = current->left;
        }

        if (current->right != NULL) {
            enqueue(queue, current->right);
            lastParent = current;
            lastNode = current->right;
        }
    }

    if (target == NULL) return root;

    target->data = lastNode->data;

    if (lastParent->left == lastNode) {
        lastParent->left = NULL;
    } else {
        lastParent->right = NULL;
    }

    free(lastNode);
    free(queue->arr);
    free(queue);
    return root;
}

void levelorderBFS(Node* root) {
    if (root == NULL) return;

    Queue* queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        Node* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left) enqueue(queue, current->left);
        if (current->right) enqueue(queue, current->right);
    }

    free(queue->arr);
    free(queue);
}

int main(void) {
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;

    printf("truoc khi xoa: ");
    levelorderBFS(root);
    printf("\n");

    root = deleteNode(root, 3);

    printf("sau khi xoa: ");
    levelorderBFS(root);
    printf("\n");

    return 0;
}