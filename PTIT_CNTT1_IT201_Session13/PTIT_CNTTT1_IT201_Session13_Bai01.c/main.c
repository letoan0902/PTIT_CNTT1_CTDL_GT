#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int *arr;
    int top;
    int maxZSize;
}Stack;

Stack* createStack(int size){
    Stack* s = (Stack*)calloc(1,sizeof(Stack));
    s->top=-1;
    s->maxZSize=size;
    s->arr = (int*)calloc(size,sizeof(int));
    return s;
}

int isEmpty(Stack* s){
    if(s->top==-1){
        return 1;
    } else {
        return 0;
    }
}

int isFull(Stack* s){
    if(s->top==s->maxZSize-1){
        return 1;
    } else {
        return 0;
    }
}

void push(Stack* s, int value){
    if(isFull(s)){
        printf("Ngan xep day");
        return;
    } else {
        s->top++;
        s->arr[s->top]=value;
    }
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Ngan xep rong");
        return -1;
    }else {
        int a=s->arr[s->top];
        s->top--;
        return a;
    }
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Ngan xep rong");
        return 1;
    }else {
        return s->arr[s->top];
    }
}

void freeStack(Stack* s){
    free(s->arr);
    free(s);
}

void printStack(Stack* s){
    int temp=s->top;
    while(temp!=-1){
        printf("%d -> ",s->arr[temp]);
        temp--;
    }
}

int main(){

    Stack* s = createStack(5);
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    // push(s,60);

    while(!isEmpty(s)){
        printf("%d -> ",pop(s));
    }
    pop(s);
    freeStack(s);
    return 0;
}
