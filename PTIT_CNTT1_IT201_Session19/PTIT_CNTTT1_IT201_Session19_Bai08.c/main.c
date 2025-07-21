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

int getHeight(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
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

    printf("chieu cao cua cay hien tai la %d",getHeight(root));
    return 0;
}