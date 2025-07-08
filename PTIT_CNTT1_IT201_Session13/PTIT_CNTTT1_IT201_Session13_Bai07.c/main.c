#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *arr;
    int top;
    int maxSize;
} Stack;

Stack createStack(int maxSize) {
    Stack stack;
    stack.arr = (char*) malloc(maxSize * sizeof(char));
    stack.top = -1;
    stack.maxSize = maxSize;
    return stack;
}

void push(Stack *stack, char value) {
    if (stack->top < stack->maxSize - 1) {
        stack->top++;
        stack->arr[stack->top] = value;
    }
}

char pop(Stack *stack) {
    if (stack->top == -1) {
        return '\0';
    } else {
        char value = stack->arr[stack->top];
        stack->top--;
        return value;
    }
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

bool isValidBrackets(char *str) {
    int len = strlen(str);
    Stack stack = createStack(len);
    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(&stack, str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            char open = pop(&stack);
            if (!isMatching(open, str[i])) {
                free(stack.arr);
                return false;
            }
        }
    }
    bool result = (stack.top == -1);
    free(stack.arr);
    return result;
}

int main() {
    char str[200];
    printf("Nhap bieu thuc: ");
    fgets(str, sizeof(str), stdin);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    if (isValidBrackets(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
