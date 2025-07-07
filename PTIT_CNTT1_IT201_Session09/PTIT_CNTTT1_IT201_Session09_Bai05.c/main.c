#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;


Node* createNode(int data){
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if(newNode==NULL){
        printf("Khong the cap phat bo nho");
    }
    newNode->data=data;
    return newNode;
}

void printList(Node *head){
    while (head!=NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int searchNode(Node* head, int input){
    while (head!=NULL)
    {
        if(head->data==input){
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int countNode(Node* head){
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}

Node* addNode(Node* head, int data){
    Node* newNode=createNode(data);
    newNode->next=head;
    return newNode;
}
int main() {
    Node* head = createNode(10);
    Node* node1 = createNode(20);
    Node* node2 = createNode(30);
    Node* node3 = createNode(40);
    Node* node4 = createNode(50);


    head->next=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;

    printList(head);
    printf("Danh sach lien ket co %d phan tu\n", countNode(head));
    int a;
    printf("Nhap so muon them: ");
    scanf("%d", &a);
    head = addNode(head, a);
    printList(head);
    return 0;
}