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

void findNode(Node* head, int find){
    int index=1;
    while(head!=NULL&&head->data!=find){
        head=head->next;
        index++;
    };
    if(head==NULL){
        printf("Khong tim thay node");
        return;
    } else{
        printf("Node %d: %d\n", index, head->data);
    }
}

void checkLength(Node* head){
    int length =0;
    while(head!=NULL){
        head=head->next;
        length++;
    }
    printf("Danh sach co %d phan tu\n",length);
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
    checkLength(head);
    
    return 0;
}