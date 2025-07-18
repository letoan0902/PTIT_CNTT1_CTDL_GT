#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack {
    char* arr;
    int top;
    int maxSize;
}Stack;

Stack* createStack(int size){
    Stack* s = (Stack*)calloc(1,sizeof(Stack));
    s->arr=(char*)calloc(size,sizeof(char));
    s->top=-1;
    s->maxSize=size;
    return s;
}

int isEmpty(Stack* s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

int isFull(Stack* s){
    if(s->maxSize-1==s->top){
        return 1;
    }
    return 0;
}

void push(Stack* s, char value){
    if(isFull(s)){
        printf("Ngan xep day");
        return;
    }
    s->arr[++s->top]=value;
}

char pop(Stack* s){
    if(isEmpty(s)){
        printf("Ngan xep trong");
        return '\0';
    }
    return s->arr[s->top--];
}

void checkBieuThuc(char* str, int len){
    Stack* s=createStack(len);
    for (int i = 0; i < len; i++){
        if(str[i]=='{'||str[i]=='['||str[i]=='('){
            push(s,str[i]);
        }else if(str[i]=='}'){
            if(!isEmpty(s) &&s->arr[s->top]=='{'){
                pop(s);
            }
        }else if(str[i]==']'){
            if(!isEmpty(s) &&s->arr[s->top]=='['){
                pop(s);
            }
        }else if(str[i]==')'){
            if(!isEmpty(s) &&s->arr[s->top]=='('){
                pop(s);
            }
        }
    }
    if(isEmpty(s)){
        printf("True");
    }else {
        printf("False");
    }
    free(s->arr);
    free(s);
}


int main(){
    char str[50];
    printf("Nhap bieu thuc: ");
    fgets(str,50,stdin);
    str[strcspn(str,"\n")]='\0';
    int len = strlen(str);
    checkBieuThuc(str,len);
    return 0;
}