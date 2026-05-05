#ifndef QUEUE_LINKEDLIST
#define QUEUE_LINKEDLIST

typedef struct node {
    int data;
    struct node* next;
}Node, *NodePtr;

typedef struct {
    NodePtr front;
    NodePtr rear;
}Queue;

void initQueue(Queue* q);
void Enqueue(Queue* q, int elem);
void Dequeue(Queue* q);
int Front(Queue q);
int Rear(Queue q);
bool isEmpty(Queue q);
void displayQueue(Queue q);

#endif
