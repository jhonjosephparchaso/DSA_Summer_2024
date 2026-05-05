#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OpenHash.h"
#define MAX 10

void initHashTable(openHash* OH) {
	int i;
    for (i = 0; i < MAX; i++) {
        OH->arr[i] = NULL;
    }
}

int hash(int key) {
    return key % MAX;
}

void insert(openHash* OH, studentInfo student, int key) {
	NodePtr* trav, temp;
    int index = hash(key);
    temp = (NodePtr)malloc(sizeof(Node));
    if(temp != NULL){
	    for(trav = &(OH->arr[index]); *trav != NULL && (*trav)->data.idNum < student.idNum; trav = &((*trav)->next)){}
	    temp->data = student;
	    temp->next = *trav;
	    *trav = temp;
	}
}

void delete(openHash* OH, int idNum, int key) {
    int index = hash(key);
    NodePtr trav;
    NodePtr prev = NULL;
    for(trav = OH->arr[index]; trav != NULL && trav->data.idNum != idNum; prev = trav, trav = trav->next){}
    if (trav != NULL) {
        if (prev == NULL) {
            OH->arr[index] = trav->next;
        } else {
            prev->next = trav->next;
        }
        free(trav);
    }
}

void display(openHash OH) {
	int i;
	NodePtr trav;
    for (i = 0; i < MAX; i++) {
        printf("%d: ", i);
        for (trav = OH.arr[i]; trav != NULL ; trav = trav->next){
			printf("(%s %s, %d, %02d/%04d, %d) -> ", 
            trav->data.name.fName, trav->data.name.lName, 
			trav->data.idNum,
			trav->data.birthdate.month, trav->data.birthdate.year,
			trav->data.age);
        }
        printf("NULL\n");
    }
}
