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

int findMax(Node* root) {
    if (root == NULL) return -999999;
    int max = root->data;
    int left = findMax(root->left);
    int right = findMax(root->right);

    if (left>max) max = left;
    if (right>max) max = right;
    return max;

}
int main(void) {
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    int n = findMax(root);
    printf("gia tri lon nhat cua cay = %d", n);
    return 0;
}