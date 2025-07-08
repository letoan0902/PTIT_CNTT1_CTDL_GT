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

int main() {
    int maxElements = 5;
    Stack myStack = createStack(maxElements);

    printf("Ngan xep da duoc tao voi toi da %d phan tu.\n", myStack.maxSize);
    printf("Chi so top hien tai: %d\n", myStack.top);

    free(myStack.arr);
    return 0;
}
