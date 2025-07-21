#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int insert(Node* root, int value) {
    if (root == NULL) return 0;

    if (root->left == NULL) {
        root->left = createNode(value);
        return 1;
    }

    if (root->right == NULL) {
        root->right = createNode(value);
        return 1;
    }

    if (insert(root->left, value)) return 1;
    return insert(root->right, value);
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

    int value;
    printf("nhap gia tri them vao: ");
    scanf("%d", &value);
    insert(root, value);

    return 0;
}