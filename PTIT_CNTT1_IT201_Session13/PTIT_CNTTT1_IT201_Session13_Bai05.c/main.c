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

void reverseArray(int *arr, int n) {
    Stack stack = createStack(n);
    for (int i = 0; i < n; i++) {
        push(&stack, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&stack);
    }
    free(stack.arr);
}

void printArray(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Mang sau khi dao nguoc: ");
    printArray(arr, n);

    free(arr);
    return 0;
}
