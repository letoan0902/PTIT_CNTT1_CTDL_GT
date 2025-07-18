#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strdup(const char* s) {
    char* d = malloc(strlen(s) + 1);
    if (d) strcpy(d, s);
    return d;
}

typedef struct Info {
    char* sdt;
    char* time;
} Info;

typedef struct Stack {
    Info* info;
    int top;
    int size;
} Stack;

Stack* createStack(int size) {
    Stack* s = (Stack*)calloc(1, sizeof(Stack));
    s->info = (Info*)calloc(size, sizeof(Info));
    s->top = -1;
    s->size = size;
    return s;
}

int isFullStack(Stack* s) {
    return (s->top == s->size - 1);
}

int isEmptyStack(Stack* s) {
    return (s->top == -1);
}

void pushStack(Stack* s, const char* value, const char* time) {
    if (isFullStack(s)) return;
    s->top++;
    s->info[s->top].sdt = my_strdup(value);
    s->info[s->top].time = my_strdup(time);
}

Info popStack(Stack* s) {
    Info tmp = {NULL, NULL};
    if (isEmptyStack(s)) return tmp;
    tmp = s->info[s->top];
    s->top--;
    return tmp;
}

typedef struct Queue {
    Info* info;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)calloc(1, sizeof(Queue));
    q->info = (Info*)calloc(size, sizeof(Info));
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

int isFullQueue(Queue* q) {
    return ((q->rear + 1) % q->size == q->front);
}

int isEmptyQueue(Queue* q) {
    return (q->front == q->rear);
}

void pushQueue(Queue* q, const char* value, const char* time) {
    if (isFullQueue(q)) return;
    q->info[q->rear].sdt = my_strdup(value);
    q->info[q->rear].time = my_strdup(time);
    q->rear = (q->rear + 1) % q->size;
}

Info popQueue(Queue* q) {
    Info tmp = {NULL, NULL};
    if (isEmptyQueue(q)) return tmp;
    tmp = q->info[q->front];
    q->front = (q->front + 1) % q->size;
    return tmp;
}

void stripNewline(char* s) {
    size_t len = strlen(s);
    if (len && s[len-1] == '\n') s[len-1] = 0;
}

int main() {
    Stack* callBackStack = createStack(100);
    Stack* callForwardStack = createStack(100);
    Queue* callHistoryQueue = createQueue(100);

    char line[100], sdt[20], time[20];
    char choice;

    while (1) {
        printf("-------MANAGER CALL-------\n");
        printf("a. CALL\n");
        printf("b. BACK\n");
        printf("c. REDIAL\n");
        printf("d. HISTORY\n");
        printf("e. EXIT\n");
        printf("Vui long chon: ");
        if (!fgets(line, sizeof(line), stdin)) break;
        choice = line[0];

        if (choice == 'a') {
            printf("Vui long nhap so dien thoai: ");
            fgets(sdt, sizeof(sdt), stdin); stripNewline(sdt);
            printf("Vui long nhap thoi gian: ");
            fgets(time, sizeof(time), stdin); stripNewline(time);
            pushStack(callBackStack, sdt, time);
            pushQueue(callHistoryQueue, sdt, time);
        }
        else if (choice == 'b') {
            Info info = popStack(callBackStack);
            if (info.sdt) {
                printf("BACK: %s - %s\n", info.sdt, info.time);
                pushStack(callForwardStack, info.sdt, info.time);
                pushQueue(callHistoryQueue, info.sdt, info.time);
                free(info.sdt); free(info.time);
            } else {
                printf("Stack rong!\n");
            }
        }
        else if (choice == 'c') {
            Info info = popStack(callForwardStack);
            if (info.sdt) {
                printf("REDIAL: %s - %s\n", info.sdt, info.time);
                pushStack(callBackStack, info.sdt, info.time);
                pushQueue(callHistoryQueue, info.sdt, info.time);
                free(info.sdt); free(info.time);
            } else {
                printf("Khong co cuoc goi nao!\n");
            }
        }
        else if (choice == 'd') {
            printf("LICH SU CUOC GOI:\n");
            int i = callHistoryQueue->front;
            while (i != callHistoryQueue->rear) {
                printf("%s - %s\n", callHistoryQueue->info[i].sdt, callHistoryQueue->info[i].time);
                i = (i + 1) % callHistoryQueue->size;
            }
        }
        else if (choice == 'e') {
            break;
        }
    }

    while (!isEmptyStack(callBackStack)) {
        Info info = popStack(callBackStack);
        if (info.sdt) free(info.sdt);
        if (info.time) free(info.time);
    }
    while (!isEmptyStack(callForwardStack)) {
        Info info = popStack(callForwardStack);
        if (info.sdt) free(info.sdt);
        if (info.time) free(info.time);
    }
    while (!isEmptyQueue(callHistoryQueue)) {
        Info info = popQueue(callHistoryQueue);
        if (info.sdt) free(info.sdt);
        if (info.time) free(info.time);
    }
    free(callBackStack->info); free(callBackStack);
    free(callForwardStack->info); free(callForwardStack);
    free(callHistoryQueue->info); free(callHistoryQueue);

    return 0;
}
