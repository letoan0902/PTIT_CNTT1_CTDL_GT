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

int checkLength(Node* head){
    int length =0;
    while(head!=NULL){
        head=head->next;
        length++;
    }
    return length;
}

Node* addNode(Node* head, int data){
    Node* newNode=createNode(data);
    newNode->next=head;
    newNode->prev=NULL;
    head->prev=newNode;
    return newNode;
}

Node* removeFirst(Node* head){
    Node* temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
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



Node* addAt(Node* head, int data, int position){
    Node* newNode=createNode(data);
    if(position==1){
        return addNode(head,data);
    }
    if(position==checkLength(head)){
        return addEnd(head, data);
    }
    int index=1;
    Node* current = head;
    while (index!=position&&current!=NULL)
    {
        current=current->next;
        index++;
    }

    if(current==NULL){
        printf("Index khong hop le");
        return head;
    } else {
        current->prev->next=newNode;
        newNode->prev=current->prev;
        newNode->next=current;
        current->prev=newNode;
        return head;
    }
}

Node* removeAt(Node* head, int position){
    Node* current = head;
    if(position==1){
        return removeFirst(head);
    } else if(position==checkLength(head)){
        while (current->next!=NULL)
        {
            current=current->next;
        }
        current->prev->next=NULL;
        free(current);
    } else {
        int index=1;
        while (index!=position)
        {
           index++;
           current=current->next; 
        }
        current->prev->next=current->next;
        current->next->prev=current->prev;
        free(current);
    }
    return head;
}

Node * reverseList(Node* head){
    Node* current=head;
    Node* temp = NULL;
    while (current!=NULL)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }

    if(temp!=NULL){
        head=temp->prev;
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
    head = reverseList(head);
    printList(head);
    return 0;
}