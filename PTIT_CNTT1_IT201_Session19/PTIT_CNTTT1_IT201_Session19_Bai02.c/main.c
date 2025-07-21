#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
//B2 xay dung ham khoi tao node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Bai 2: xay dung ham duyet preOrder(Root-left-right)
void preOrderDFS(Node* root) {
    if (root == NULL) return;
    printf("%d ",root->data);
    preOrderDFS(root->left);
    preOrderDFS(root->right);
}
//Bai 3: xay dung ham duyet postorder(left-right-root)
void postorderDFS(Node* root) {
    if (root == NULL) return;
    postorderDFS(root->left);
    postorderDFS(root->right);
    printf("%d ",root->data);
}

//Bai 4: xay dung ham duyet inorder(left-root-right)
void inorderDFS(Node* root) {
    if (root == NULL) return;
    inorderDFS(root->left);
    printf("%d ",root->data);
    inorderDFS(root->right);
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

    printf("preorderDFS: ");
    preOrderDFS(root);
    printf("\n");

    printf("postorderDFS: ");
    postorderDFS(root);
    printf("\n");

    printf("inorderDFS: ");
    inorderDFS(root);


    return 0;
}