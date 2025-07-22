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

int findLevel(Node* root, int value, int level) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == value) return level;

    int left = findLevel(root->left, value, level + 1);
    if (left != -1) return left;

    return findLevel(root->right, value, level + 1);
}
int main(void) {
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;

    int value;
    printf("nhap gia tri can tim: ");
    scanf("%d", &value);
    int level = findLevel(root, value, 0);
    if (level != -1) {
        printf("level %d",level);
    }else {
        printf("ko co trong cay");
    }
    return 0;
}