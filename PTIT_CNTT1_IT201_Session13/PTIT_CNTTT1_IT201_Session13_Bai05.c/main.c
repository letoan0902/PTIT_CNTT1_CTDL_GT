#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    char *arr;
    int top;
    int maxSize;
}Stack;

Stack* createStack(int size){
    Stack* s = (Stack*)calloc(1,sizeof(Stack));
    s->top=-1;
    s->maxSize=size;
    s->arr=(char*)calloc(size,sizeof(char));
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

void push(Stack* s, char value){
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

int checkDoiXung(char* string, int len){
    Stack* s = createStack(len);
    for (int i = 0; i < len; i++)
    {
        push(s,string[i]);
    }

    for (int i = 0; i < len; i++)
    {
        if(pop(s)!=string[i]){
            return 0;
            free(s->arr);
            free(s);
        }
    }
    
    return 1;
    free(s->arr);
    free(s);
}


int main(){
    char string[50];
    printf("Nhap chuoi: ");
    fgets(string,50,stdin);
    string[strcspn(string,"\n")]='\0';
    int len = strlen(string);
    if(checkDoiXung(string, len)){
        printf("Chuoi doi xung");
    } else {
        printf("Chuoi khong doi xung");
    }
}