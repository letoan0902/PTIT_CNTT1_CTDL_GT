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

int checkLength(Node* head){
    int length =0;
    while(head!=NULL){
        length++;
        head=head->next;
    }
    return length;
}

Node* addAt(Node* head, int data, int position){
    Node* current = head;
    Node* newNode = createNode(data);
    int index=1;
    if(position==1){
        current->prev=newNode;
        newNode->next=current;
        head=newNode;
    } else if(position==checkLength(head)+1){
        while(current->next!=NULL){
            current=current->next;
        }
        newNode->prev=current;
        current->next=newNode;
    } else {
        while(index!=position){
            current=current->next;
            index++;
        }
        current->prev->next=newNode;
        newNode->next=current;
        newNode->prev=current->prev;
        current->prev=newNode;
    }
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
    int a, b;
    printf("Nhap data: ");
    scanf("%d", &a);
    printf("Nhap position: ");
    scanf("%d",&b);
    if(b<1||b>checkLength(head)+2){
        printf("Khong hop le");
        return 1;
    }
    head = addAt(head, a, b);
    printList(head);
    return 0;
}