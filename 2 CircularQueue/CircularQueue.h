#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE
#define MAX 10

typedef struct {
	int data[MAX];
	int front;
	int rear;
}CircularQueue;

void initQueue(CircularQueue* q);
void Enqueue(CircularQueue* q, int elem);
void Dequeue(CircularQueue* q);
int Front(CircularQueue q);
int Rear(CircularQueue q);
bool isEmpty(CircularQueue q);
bool isFull(CircularQueue q);
void displayQueue(CircularQueue q);

#endif
