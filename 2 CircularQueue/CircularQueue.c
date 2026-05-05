#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CircularQueue.h"
#define MAX 10

void initQueue(CircularQueue* q) {
    q->front = 0;
    q->rear = MAX - 1;
}

bool isEmpty(CircularQueue q) {
    return (q.front == q.rear + 1 || (q.front == 0 && q.rear == MAX - 1));
}

bool isFull(CircularQueue q) {
    return ((q.rear + 2) % MAX == q.front);
}

void Enqueue(CircularQueue *q, int elem){
    if (isEmpty(*q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = elem;
}

void Dequeue(CircularQueue *q){
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

int Front(CircularQueue q){
	return (!isEmpty(q)) ? q.data[q.front] : -1;
}

int Rear(CircularQueue q){
	return (!isEmpty(q)) ? q.data[q.rear] : -1;
}

void displayQueue(CircularQueue q){
	int i;
	for (i=q.front; i != q.rear; i = (i + 1) % MAX){
		printf("%d ", q.data[i]);
	}
    printf("%d", q.data[i]);
}
