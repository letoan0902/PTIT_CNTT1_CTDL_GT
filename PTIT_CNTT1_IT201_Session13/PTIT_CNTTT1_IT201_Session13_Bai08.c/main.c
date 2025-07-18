#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack
{
    int *arr;
    int top;
    int maxSize;
} Stack;

Stack *createStack(int size)
{
    Stack *s = (Stack *)calloc(1, sizeof(Stack));
    s->arr = (int*)calloc(size, sizeof(int));
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

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Ngan xep day");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Ngan xep day");
        return '\0';
    }
    return s->arr[s->top--];
}

int tinhToan(char *input, int len)
{
    Stack *s = createStack(50);
    for (int i = 0; i < len; i++){
        if (isdigit(input[i])){
            push(s, input[i] - '0');
        }else{
            int b = pop(s), a = pop(s);
            if (input[i] == '*'){
                push(s, a * b);
            } else if (input[i] == '/'){
                push(s, a / b);
            }  else if (input[i] == '+'){
                push(s, a + b);
            }  else if (input[i] == '-'){
                push(s, a - b);
            } 
        }
    }
    int result = pop(s);
    free(s->arr);
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
    printf("%d\n", tinhToan(input, len));
    return 0;
}