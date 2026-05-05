#include <stdio.h>
#include <stdbool.h>
#include "UnionIntersection.h"
#define MAX 5

void initSet(SET *S){
	S->count = 0;
}

bool isinSet(SET *S, int elem){
	int i;
	for(i=0; i < S->count && S->data[i] != elem; i++){}
		return(i < S->count)? true : false;
}

void insertinSet(SET *S, int elem){
	if (!isinSet(S, elem) && S->count < MAX) {
        S->data[S->count++] = elem;
    }
}

void deleteinSet(SET *S, int elem) {
    int i, j;

    for (i = 0; i < S->count; i++) {
        if (S->data[i] == elem) {
            for (j = i; j < S->count - 1; j++) {
                S->data[j] = S->data[j + 1];
            }
            S->count--;
        }
    }
}

SET unionSet(SET *S1, SET *S2){
	SET res;
	initSet(&res);
    int i;
	
	for(i=0; i < S1->count; i++) {
        insertinSet(&res, S1->data[i]);
    }
    for(i=0; i < S2->count; i++) {
        insertinSet(&res, S2->data[i]);
    }

    return res;
}

SET intersectSet(SET *S1, SET *S2){
	SET res;
	initSet(&res);
    int i;
	
	for (i=0; i < S1->count; i++) {
        if (isinSet(S2, S1->data[i])) {
            insertinSet(&res, S1->data[i]);
        }
    }

    return res;
}

void printSet(SET S) {
    int i;
    printf("{ ");
    for (i = 0; i < S.count; i++) {
        printf("%d ", S.data[i]);
    }
    printf("}\n");
}

