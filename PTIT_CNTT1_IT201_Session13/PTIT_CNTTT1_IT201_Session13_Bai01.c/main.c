#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int cap;
}Stack;

Stack* createStack(int cap) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(cap * sizeof(int));
    stack->top = -1;
    stack->cap = cap;
    return stack;
}
int isFull(Stack* stack) {
    if (stack->top == stack->cap -1) return 1;
    return 0;
}
Stack* push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("stack is full\n");
        return;
    }

    stack->top++;
    stack->arr[stack->top] = value;
    return stack;
}
void printStack(Stack* stack) {
    printf("stack={\n");
    printf("\telements: [");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d, ",stack->arr[i]);
    }
    printf("],\n");
    printf("\ttop: %d,\n",stack->top);
    printf("\tcap: %d\n}",stack->cap);
}
int main() {
    Stack* stack = createStack(5);
    int value;
    printf("Nhap phan tu:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d",&value);
        push(stack,value);
    }
    printStack(stack);
    return 0;
}