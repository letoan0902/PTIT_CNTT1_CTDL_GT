#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int *arr;
    int front;
    int rear;
    int cap;
}Queue;
Queue *createQueue(int cap){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (int*)malloc( cap*sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->cap = cap;
    return queue;
}
int main(void) {

    return 0;
}