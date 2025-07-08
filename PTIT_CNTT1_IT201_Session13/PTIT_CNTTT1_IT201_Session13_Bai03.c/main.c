#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int maxSize;
} Stack;

Stack createStack(int maxSize) {
    Stack stack;
    stack.arr = (int*) malloc(maxSize * sizeof(int));
    stack.top = -1;
    stack.maxSize = maxSize;
    return stack;
}

void push(Stack *stack, int value) {
    if (stack->top < stack->maxSize - 1) {
        stack->top++;
        stack->arr[stack->top] = value;
    } else {
        printf("Ngan xep day, khong the them phan tu.\n");
    }
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("No element in stack\n");
        return -1;
    } else {
        int value = stack->arr[stack->top];
        stack->top--;
        return value;
    }
}

void printStack(Stack stack) {
    printf("stack={\n");
    printf("elements: [");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d", stack.arr[i]);
        if (i < stack.top) {
            printf(", ");
        }
    }
    printf("],\n");
    printf("top: %d,\n", stack.top);
    printf("cap: %d\n", stack.maxSize);
    printf("}\n");
}

int main() {
    int maxElements = 5;
    Stack myStack = createStack(maxElements);

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < maxElements; i++) {
        int value;
        scanf("%d", &value);
        push(&myStack, value);
    }

    printStack(myStack);

    int poppedValue = pop(&myStack);
    if (poppedValue != -1) {
        printf("%d\n", poppedValue);
    }

    free(myStack.arr);
    return 0;
}
