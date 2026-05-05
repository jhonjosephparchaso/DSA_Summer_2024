#ifndef FCFS
#define FCFS

typedef struct node {
    char process;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnAroundTime;
    float avgWaitTime;
    float avgTurnAroundTime;
    int executionTime;
    struct node* next;
} fcfsNode, *fcfsPtr;

typedef struct {
    fcfsPtr front;
    fcfsPtr rear;
} Queue;

void initQueue(Queue* q);
void enqueue(Queue* q, char process, int burstTime, int arrivalTime);
void dequeue(Queue* q);
int isEmpty(Queue q);
fcfsPtr front(Queue q);
fcfsPtr rear(Queue q);
void calculateMetrics(Queue* q);
void displayFCFS(Queue q);

#endif

