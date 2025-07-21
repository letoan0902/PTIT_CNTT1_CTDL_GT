#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    Node *root = NULL;
    root = createNode(1);
    int n;
    printf("nhap gia tri: ");
    scanf("%d", &n);
    root->left = createNode(n);

    printf("nhap gia tri: ");
    scanf("%d", &n);
    root->right = createNode(n);
    return 0;
}