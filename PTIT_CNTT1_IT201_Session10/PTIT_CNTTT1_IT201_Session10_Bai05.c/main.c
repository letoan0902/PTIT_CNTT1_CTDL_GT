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
    int a;
    printf("Nhap so nguyen: ");
    scanf("%d",&a);
    if(a<0){
        printf("Nhap sai");
        return 1;
    }
    head = removeFind(head, a);
    printList(head);
    return 0;
}