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
int main() {
    Queue* queue = createQueue(5);
    int val;
    for (int i=0;i<5;i++) {
        printf("nhap gia tri them: ");
        scanf("%d",&val);
        enQueue(queue,val);
    }
    printf("da them xong cac gia tri");
    return 0;
}