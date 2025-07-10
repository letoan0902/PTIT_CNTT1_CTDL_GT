#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
typedef struct Stack {
    Node* top;
}Stack;

Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

void push(Stack* stack) {
    int n;
    printf("nhap phan tu (n>0):");
    scanf("%d",&n);
    if (n<=0) {
        printf(" ko hop le");
        return;
    }
    Node* newNode = createNode(n);
    newNode->next = stack->top;
    stack->top = newNode;
}
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("ngan xep trong\n");
        return -1;
    }
    Node* temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return value;
}
void print(Stack* stack) {
    Node* current = stack->top;
    if (stack->top == NULL) {
        printf("Ngan xep trong\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    Stack* stack = createStack();

    push(stack);
    push(stack);
    push(stack);
    push(stack);

    int del = pop(stack);
    if (del != -1) printf("da lay phan tu %d\n",del);

    print(stack);
    return 0;
}