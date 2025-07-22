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
// xay dung ham duyet preorder(root-left-right)
void preorderDFS(Node* root) {
    if (root == NULL) return;
    printf("%d ",root->data);
    preorderDFS(root->left);
    preorderDFS(root->right);
}
// xay dung ham duyet postorder(left-right-root)
void postorderDFS(Node* root) {
    if (root == NULL) return;
    postorderDFS(root->left);
    postorderDFS(root->right);
    printf("%d ",root->data);
}
// xay dung ham duyet inorder(left-root-right)
void inorderDFS(Node* root) {
    if (root == NULL) return;
    inorderDFS(root->left);
    printf("%d ",root->data);
    inorderDFS(root->right);
}

typedef struct QueueNode {
    Node* tree;
    struct Queue* next;
}QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
}Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* tree) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->tree = tree;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    }else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* result = temp->tree;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return result;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        printf("%d ",current->data);

        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }
    free(q);
}

int main(void) {
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    printf("preorderDFS: ");
    preorderDFS(root);
    printf("\n");

    printf("postorderDFS: ");
    postorderDFS(root);
    printf("\n");

    printf("inorderDFS: ");
    inorderDFS(root);
    printf("\n");

    printf("levelOrder: ");
    levelOrder(root);
    return 0;
}