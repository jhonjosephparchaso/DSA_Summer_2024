#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, char process, int burstTime, int arrivalTime) {
	fcfsPtr current;
    fcfsPtr newNode = (fcfsPtr)malloc(sizeof(fcfsNode));
    if(newNode != NULL) {
        newNode->process = process;
        newNode->burstTime = burstTime;
        newNode->arrivalTime = arrivalTime;
        newNode->waitingTime = 0;  
        newNode->turnAroundTime = 0;  
        newNode->avgWaitTime = 0.0;  
        newNode->avgTurnAroundTime = 0.0;
        newNode->executionTime = 0;
        newNode->next = NULL;

        if(q->front == NULL || q->front->arrivalTime > newNode->arrivalTime) {
            newNode->next = q->front;
            q->front = newNode;
            if(q->rear == NULL) {
                q->rear = newNode;
            }
        }else{
        	for(current=q->front; current->next != NULL && current->next->arrivalTime <= newNode->arrivalTime; current = current->next){}
            newNode->next = current->next;
            current->next = newNode;
            if(newNode->next == NULL) {
                q->rear = newNode;
            }
        }
    }
}

void dequeue(Queue* q) {
    if(q->front != NULL) {
        fcfsPtr temp = q->front;
        q->front = q->front->next;
        if(q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
    }
}

fcfsPtr front(Queue q) {
    return q.front;
}

fcfsPtr rear(Queue q) {
    return q.rear;
}

int isEmpty(Queue q) {
    return (q.front == NULL);
}

void calculateMetrics(Queue* q) {
	fcfsPtr current = q->front;
	int currentTime = 0;
	int totalWaitingTime = 0;
	int totalTurnAroundTime = 0;
	int numProcesses = 0;
	
    if(!isEmpty(*q)) {
	    for (current=q->front; current != NULL; current = current->next) {
	        if (currentTime < current->arrivalTime) {
	            currentTime = current->arrivalTime;
	        }
	
	        current->executionTime = currentTime;
	        current->waitingTime = current->executionTime - current->arrivalTime;
	        current->turnAroundTime = current->burstTime + current->executionTime;
	        
	        currentTime += current->burstTime;
	    }
	
	    for (current=q->front; current != NULL; current = current->next) {
	        totalWaitingTime += current->waitingTime;
	        totalTurnAroundTime += current->turnAroundTime;
	        numProcesses++;
	    }
	
	    float avgWaitTime = (float)totalWaitingTime / numProcesses;
	    float avgTurnAroundTime = (float)totalTurnAroundTime / numProcesses;
	
	    for (current=q->front; current != NULL; current = current->next) {
	        current->avgWaitTime = avgWaitTime;
	        current->avgTurnAroundTime = avgTurnAroundTime;
	    }
    }
}

void displayFCFS(Queue q) {
    fcfsPtr current;
    if (q.front != NULL) {
        printf("Process\tBurst Time\tArrival Time\tExecution Time\tWaiting Time\tTurnaround Time\n");
        printf("--------------------------------------------------------------------------\n");

        for (current = q.front; current != NULL; current = current->next) {
            printf("%c\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", current->process, current->burstTime, current->arrivalTime, current->executionTime, current->waitingTime, current->turnAroundTime);
        }

        printf("Average Waiting Time: %.2f\n", q.front->avgWaitTime);
        printf("Average Turnaround Time: %.2f\n", q.front->avgTurnAroundTime);
    }
}

