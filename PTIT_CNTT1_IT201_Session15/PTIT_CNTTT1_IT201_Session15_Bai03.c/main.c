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
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
int main() {
    int size,val;
    printf("nhap so luong phan tu: ");
    scanf("%d",&size);
    Queue* queue = createQueue(size);
    // hang doi trong khi moi tao
    isEmpty(queue);
    for (int i=0;i<size;i++) {
        printf("nhap gia tri them: ");
        scanf("%d",&val);
        enQueue(queue,val);
    }
    // hang doi full khi da them het gia tri
    isEmpty(queue);
    return 0;
}