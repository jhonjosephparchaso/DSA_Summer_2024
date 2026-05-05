#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "QueueLL.h"

void initQueue(Queue* q){
    q->front=NULL;
    q->rear=NULL;
}

void Enqueue(Queue* q, int elem){
    NodePtr temp;
    
    temp = (NodePtr)malloc(sizeof(Node));
    if(temp != NULL){
        temp->data = elem;
        temp->next = NULL;
		if(q->rear == NULL){
			q->front = temp;
			q->rear = temp;
		}else {
			q->rear->next = temp;
			q->rear = temp;
		}
	}
}

void Dequeue(Queue* q){
	NodePtr temp;
	
	if(q->front != NULL){
		temp = q->front;
		q->front = q->front->next;
		if(q->front == NULL){
			q->rear = NULL;
		}
		free(temp);
	}
}

int Front(Queue q){
	return (q.front != NULL)? q.front->data : -1;
}

int Rear(Queue q){
	return (q.rear != NULL)? q.rear->data : -1;
}

bool isEmpty(Queue q){
	return (q.front == NULL);
}

void displayQueue(Queue q){
	NodePtr trav;
	
	for(trav=q.front; trav != NULL; trav = trav->next){
		printf("%d ", trav->data);
	}
}


