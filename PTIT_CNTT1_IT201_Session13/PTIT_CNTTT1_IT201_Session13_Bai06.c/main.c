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
    } else {
        printf("Ngan xep day, khong the them phan tu.\n");
    }
}

char pop(Stack *stack) {
    if (stack->top == -1) {
        printf("No element in stack\n");
        return '\0';
    } else {
        char value = stack->arr[stack->top];
        stack->top--;
        return value;
    }
}

bool isPalindrome(char *str) {
    int len = strlen(str);
    Stack stack = createStack(len);
    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }
    for (int i = 0; i < len; i++) {
        char c = pop(&stack);
        if (str[i] != c) {
            free(stack.arr);
            return false;
        }
    }
    free(stack.arr);
    return true;
}

int main() {
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
