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

Node* removeData(Node* head, int a){
    Node* current = head;

    while(current!=NULL){
        if(current->data==a){
            Node* temp = current;
            if(current->prev==NULL){
                head=current->next;
                if(head!=NULL){
                    head->prev=NULL;
                }
            } else {
                current->prev->next=current->next;
                if(current->next!=NULL){
                    current->next->prev=current->prev;
                }
            }
            
            current=current->next;
            free(temp);
        } else {
            current=current->next;
        }
    }
    return head;
}

int checkLength(Node* head){
    int length =0;
    while(head!=NULL){
        head=head->next;
        length++;
    }
    return length;
}

void findMid(Node* head){
    int flag = checkLength(head)/2+1;
    int index=1;
    if(checkLength(head)==1){
        printf("Node 1: %d", head->data);
        return;
    }
    while (index!=flag)
    {
        head=head->next;
        index++;
    }

    printf("Node %d: %d", index, head->data);
    
}

int main() {
    Node* head = createNode(5);
    Node* node1 = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);

    head->next=node1;
    node1->next=node2;
    node2->next = node3;
    node3->next=node4;
    node4->prev=node3;
    node3->prev=node2;
    node2->prev=node1;
    node1->prev =head;
    printList(head);
    head=addEnd(head, 60);
    printList(head);
    findMid(head);
    
    return 0;
}