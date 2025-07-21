#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct node *left;
    struct node *right;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* searchBFS(Node* root, int data) {
    if (root == NULL) return NULL;
    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear) {
        Node* current = queue[front++];

        if (current->data == data) return current;

        if (current->left != NULL) queue[rear++] = current->left;

        if (current->right != NULL) queue[rear++] = current->right;
    }
    return NULL;
}
int main() {
    Node *root = NULL;
    root = createNode(2);

    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;

    int n;
    printf("nhap gia tri can tim: ");
    scanf("%d", &n);
    Node* result = searchBFS(root,n);

    if (result != NULL) {
        printf("true");
    }else {
        printf("false");
    }

    return 0;
}