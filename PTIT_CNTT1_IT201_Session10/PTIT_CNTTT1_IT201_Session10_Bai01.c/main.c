#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void printList(Node* head){
    while (head!=NULL)
    {
        printf(" %d ->", head->data);
        head=head->next;
    }
    printf(" NULL");
    
}

Node* createNode(int data){
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if(newNode==NULL){
        printf("Khong the cap phat bo nho");
    }
    newNode->data = data;
}


int main() {
    Node* head = createNode(10);
    Node* node1 = createNode(20);
    Node* node2 = createNode(30);
    Node* node3 = createNode(40);
    Node* node4 = createNode(50);

    head->next = node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    printList(head);
    return 0;
}