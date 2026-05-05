#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

int main(int argc, char *argv[]) {
    Queue q;
    initQueue(&q);
    
    enqueue(&q, 'A', 2, 1);
    enqueue(&q, 'B', 3, 0);
    enqueue(&q, 'C', 4, 2);
    enqueue(&q, 'D', 1, 5);
    enqueue(&q, 'E', 2, 0);
    enqueue(&q, 'F', 3, 3);
    
//    displayFCFS(q);
//    
//    dequeue(&q);
    
    calculateMetrics(&q);
    
    displayFCFS(q);
    
    return 0;
}

