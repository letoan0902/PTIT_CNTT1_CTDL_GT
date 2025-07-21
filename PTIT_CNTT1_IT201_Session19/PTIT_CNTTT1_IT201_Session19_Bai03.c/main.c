#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* searchDFS(Node* root, int data) {
    if (root == NULL) return NULL;
    if (root->data == data) return root;

    Node* find = searchDFS(root->left,data);
    if (find != NULL) return find;

    return searchDFS(root->right,data);
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
    Node* result = searchDFS(root,n);

    if (result != NULL) {
        printf("true");
    }else {
        printf("false");
    }

    return 0;
}