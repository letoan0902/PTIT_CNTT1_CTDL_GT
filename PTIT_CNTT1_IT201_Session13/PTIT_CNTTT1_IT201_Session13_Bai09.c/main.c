#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack
{
    char *str;
    int top;
    int maxSize;
} Stack;

Stack *createStack(int size)
{
    Stack *s = (Stack *)calloc(1, sizeof(Stack));
    s->str = (char*)calloc(size, sizeof(char));
    s->top = -1;
    s->maxSize = size;
    return s;
}

int isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(Stack *s)
{
    if (s->top == s->maxSize - 1)
    {
        return 1;
    }
    return 0;
}

void push(Stack *s, char value)
{
    if (isFull(s))
    {
        printf("Ngan xep day");
        return;
    }
    s->str[++s->top] = value;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Ngan xep day");
        return '\0';
    }
    return s->str[s->top--];
}

char* tinhToan(char *input, int len)
{
    Stack *s = createStack(50);
    for (int i = 0; i < len; i++){
        if (isdigit(input[i])){
            push(s, input[i]);
        }else{
            char b = pop(s), a = pop(s);
            if (input[i] == '*'){
                char* c = strcat(b,"*");
                char* d = strcat(c,a);
                push(s, d);
            } else if (input[i] == '/'){
                char* c = strcat(b,"/");
                char* d = strcat(c,a);
                push(s, d);
            }  else if (input[i] == '+'){
                char* c = strcat(b,"+");
                char* d = strcat(c,a);
                push(s, d);
            }  else if (input[i] == '-'){
                char* c = strcat(b,"-");
                char* d = strcat(c,a);
                push(s, d);
            } 
        }
    }
    char result = pop(s);
    free(s->str);
    free(s);
    return result;
}

int main()
{
    char input[50];
    printf("Nhap bieu thuc: ");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';
    int len = strlen(input);
    printf("%s\n", tinhToan(input, len));
    return 0;
}