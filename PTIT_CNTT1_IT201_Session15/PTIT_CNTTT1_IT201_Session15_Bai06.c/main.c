#include<stdio.h>

typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int cap;
}Queue;

Queue* createQueue(int cap) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (int*)malloc(sizeof(int) *cap);
    queue->front = 0;
    queue->rear = -1;
    queue->cap = cap;
    return queue;
}
void enQueue(Queue* queue, int val) {
    if (queue->rear == queue->cap -1) {
        printf("hang doi full\n");
        return;
    }
    queue->arr[++queue->rear] = val;
}
int check(Queue* queue) {
    for (int i = queue->front; i < queue->rear;i++) {
        if (queue->arr[i+1] != queue->arr[i] + 1) {
            return 0;
        }
    }
    return 1;
}
int main() {
    Queue* queue = createQueue(5);
    int val;
    for (int i=0;i<5;i++) {
        printf("nhap gia tri them: ");
        scanf("%d",&val);
        enQueue(queue,val);
    }
    if (check(queue)) {
        printf("True");
    }else {
        printf("False");
    }
    return 0;
}