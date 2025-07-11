#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue {
    Node* front;
    Node* rear;
}Queue;

Queue* createQueue(){
    Queue* q = (Queue*)calloc(1,sizeof(Queue));
    if(q==NULL){
        printf("Khong the cap phat bo nho");
        exit(1);
    }
    return q;
}

Node* createNode(int value){
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if(newNode==NULL){
        printf("Khong the cap phat bo nho");
        exit(1);
    }
    newNode->data=value;
    return newNode;
}

void enQueue(Queue* q, int value){
    Node* newNode = createNode(value);
    if(q->rear==NULL){
        q->front=q->rear=newNode;
    } else {
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

void printQueue(Queue* q){
    Node* current=q->front;
    while (current!=NULL)
    {
        printf(" %d --> ", current->data);
        current=current->next;
    }
    printf(" NULL\n");
    
}

void printProntRear(Queue* q){
    printf("Rear: %d -> %d", q->rear->data, q->rear->next);
    printf("\nFront: %d\n",q->front->data);
}

int main() {
    Queue* q = createQueue();
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,5);
    enQueue(q,3);
    int value;
    printf("Nhap vao gia tri: ");
    scanf("%d",&value);
    enQueue(q,value);
    printQueue(q);
    printProntRear(q);
    return 0;
}