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
int isEmpty(Queue* queue) {
    if (queue->rear < queue->front) {
        printf("hang doi trong\n");
        return 1;
    }
    return 0;
}
void display(Queue* queue) {
    if (isEmpty(queue)) return;
    printf("thu tu FIFO\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
}
int main() {
    Queue* queue = createQueue(5);
    // cmt phan nhap gia tri lai de check hang doi full
    int val;
    for (int i=0;i<5;i++) {
        printf("nhap gia tri them: ");
        scanf("%d",&val);
        enQueue(queue,val);
    }
    display(queue);
    return 0;
}