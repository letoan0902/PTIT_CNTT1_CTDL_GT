#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if(newNode==NULL){
        printf("Khong the cap phat bo nho");
    }
    newNode->data=data;
    return newNode;
}


void printList(Node* head){
    printf("NULL <--");
    while (head!=NULL)
    {
        if(head->next==NULL){
            printf(" %d -->", head->data);
            head=head->next;
        } else {
            printf(" %d <-->", head->data);
            head=head->next;
        }
    }
    printf(" NULL\n");
}

Node* addEnd(Node* head, int data){
    Node* current = head;
    Node* newNode=createNode(data);
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current;
    return head;
}

Node* removeEnd(Node* head){
    Node* current = head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->prev->next=NULL;
    free(current);
    return head;
}
int main() {
    Node* head = createNode(10);
    Node* node1 = createNode(20);
    Node* node2 = createNode(30);
    Node* node3 = createNode(40);
    Node* node4 = createNode(50);

    head->next=node1;
    node1->next=node2;
    node2->next = node3;
    node3->next=node4;
    node4->prev=node3;
    node3->prev=node2;
    node2->prev=node1;
    node1->prev =head;
    printList(head);
    head = removeEnd(head);
    printList(head);
    
    return 0;
}