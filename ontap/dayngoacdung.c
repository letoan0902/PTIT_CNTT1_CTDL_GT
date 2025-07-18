#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack {
    char *str;
    int top;
    int size;
} Stack;

Stack* createStack(int size) {
    Stack* s = (Stack*)calloc(1, sizeof(Stack));
    s->str = (char*)calloc(size, sizeof(char));
    s->top = -1;
    s->size = size;
    return s;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == s->size - 1;
}

void push(Stack* s, char value) {
    if (!isFull(s)) {
        s->str[++s->top] = value;
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->str[s->top--];
    }
    return '\0';
}

void freeStack(Stack* s) {
    free(s->str);
    free(s);
}

int main() {
    char line[100];
    int t;

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &t);

    if (t > 20) {
        return 1;
    }

    while (t--) {
        char input[100005];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        int len = strlen(input);
        Stack* s = createStack(len);
        int flag = 0;
        for (int i = 0; i < len; i++) {
            if (input[i] == '{' || input[i] == '[' || input[i] == '(') {
                push(s, input[i]);
            } else if (input[i] == '}') {
                if (isEmpty(s) || pop(s) != '{') {
                    flag = 1;
                    break;
                }
            } else if (input[i] == ']') {
                if (isEmpty(s) || pop(s) != '[') {
                    flag = 1;
                    break;
                }
            } else if (input[i] == ')') {
                if (isEmpty(s) || pop(s) != '(') {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1 || !isEmpty(s)) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
        freeStack(s);
    }
    return 0;
}
