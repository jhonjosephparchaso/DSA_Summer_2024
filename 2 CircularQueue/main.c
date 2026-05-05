#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "CircularQueue.h"

int main(int argc, char *argv[]) {
	
	CircularQueue QL;
	
	initQueue(&QL);
	
	printf("Is the queue empty? %s", isEmpty(QL) ? "Yes" : "No");
	
	printf("\n=====\n");
	
	Enqueue(&QL, 10);
	Enqueue(&QL, 20);
	Enqueue(&QL, 30);
	
	displayQueue(QL);
	
	printf("\nFront element: %d\n", Front(QL));
    printf("Rear element: %d", Rear(QL));
	
	printf("\n=====\n");
	
	Dequeue(&QL);
	
	displayQueue(QL);
	
	printf("\n=====\n");
	
	Enqueue(&QL, 40);
	
	displayQueue(QL);
	
	printf("\n=====\n");
	
	Dequeue(&QL);
	Enqueue(&QL, 50);
	Enqueue(&QL, 60);
	Dequeue(&QL);
	Enqueue(&QL, 70);
	
	displayQueue(QL);
	
	printf("\nFront element: %d\n", Front(QL));
    printf("Rear element: %d", Rear(QL));
    
    printf("\nIs the queue empty? %s", isEmpty(QL) ? "Yes" : "No");
	
	return 0;
}
