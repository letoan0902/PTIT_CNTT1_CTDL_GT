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
    printf(" NULL\n");
    
}

Node* createNode(int data){
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if(newNode==NULL){
        printf("Khong the cap phat bo nho");
    }
    newNode->data = data;
}

Node* addEnd(Node* head, int data){
    Node* current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    Node* newNode=createNode(data);
    current->next=newNode;
    return head;
}

Node* removeEnd(Node* head){
    Node* current=head;
    while(current->next->next!=NULL){
        current=current->next;
    }
    Node* temp = current->next;
    current->next=current->next->next;
    free(temp);
    return head;
}

Node* removeFind(Node* head, int find){
    if (head == NULL) return head;
    if (head->data == find) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* current=head;
    while(current->next != NULL && current->next->data != find){
        current=current->next;
    }
    if(current->next != NULL){
    Node* temp = current->next;
    current->next=current->next->next;
    free(temp);
    }
    return head;
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

void bubbleSort(Node* head){
    if(head==NULL){
        return;
    }
    int swap;
    Node* ptr1;
    Node* lptr=NULL;
    do{
        swap=0;
        ptr1=head;
        while (ptr1->next!=lptr){
            if(ptr1->data > ptr1->next->data){
                int temp = ptr1->data;
                ptr1->data=ptr1->next->data;
                ptr1->next->data=temp;
                swap=1;
            }
            ptr1=ptr1->next;
        }
        lptr = ptr1;
    } while(swap);
}

int main() {
    Node* head = createNode(10);
    Node* node1 = createNode(60);
    Node* node2 = createNode(30);
    Node* node3 = createNode(20);
    Node* node4 = createNode(50);

    head->next = node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    printList(head);
    bubbleSort(head);
    printList(head);
    return 0;
}