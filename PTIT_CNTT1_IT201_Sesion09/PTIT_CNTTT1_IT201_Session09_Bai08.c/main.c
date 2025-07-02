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

Node* removeFirst(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* temp = head;
    head=head->next;
    free(temp);
    return head;
}

Node* addAt(Node* head, int index, int value){
    if(index<0||index>=countNode(head)){
        printf("Index khonng hop le");
        return NULL;
    }
    Node* current = head;
    if(index==0){
        return addNode(head, value);
    } else {
        for (int i = 0; i < index-1; i++)
        {  
            current = current->next;
        }
        Node* newNode = createNode(value);

        newNode->next=current->next;
        current->next=newNode;
        return head;
    }
}

Node* removeAt(Node* head, int index){
    if(index<0||index>countNode(head)){
        printf("Index khonng hop le");
        return NULL;
    } else {

        Node* current = head;
        if(index==0){
            return removeFirst(head);
        } else {
            for (int i = 0; i < index-1; i++)
            {
                current=current->next;
            }
            Node* temp = current->next;
            current->next=current->next->next;
            free(temp);
            return head;
            
        }
    }

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
    head = addNode(head, 90);
    printList(head);
    head = removeFirst(head);
    printList(head);
    int a;
    printf("Nhap vi tri index muon xoa: ");
    scanf("%d", &a);
    head = removeAt(head, a);
    printList(head);
    return 0;
}