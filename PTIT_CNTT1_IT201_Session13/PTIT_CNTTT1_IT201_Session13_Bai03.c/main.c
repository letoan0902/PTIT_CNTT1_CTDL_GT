#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int *arr;
    int top;
    int maxSize;
}Stack;

Stack* createStack(int size){
    Stack* s = (Stack*)calloc(1,sizeof(Stack));
    s->top=-1;
    s->maxSize=size;
    s->arr=(int*)calloc(size,sizeof(int));
    return s;
};

int isEmpty(Stack* s){
    if(s->top==-1){
        return 1;
    } else {
        return 0;
    }
}

int isFull(Stack* s){
    if(s->top==s->maxSize){
        return 1;
    } else {
        return 0;
    }
}

void push(Stack* s, int value){
    if(isFull(s)){
        printf("Ngan xep day");
        return;
    }
    s->top++;
    s->arr[s->top]=value;
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Ngan xep trong");
        return -1;
    }
    return s->arr[s->top--];
}

int main(){
    int a[5]={0};
    printf("Nhap 5 phan tu: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    Stack* s=createStack(5);
    for (int i = 0; i < 5; i++)
    {
        push(s,a[i]);
    }

    while(!isEmpty(s)){
        printf("%d -> ",pop(s));
    }
    printf("NULL\n");
}