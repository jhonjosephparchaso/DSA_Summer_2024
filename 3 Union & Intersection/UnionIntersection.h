#ifndef UNION_INTERSECTION
#define UNION_INTERSECTION

#include <stdbool.h>
#define MAX 5

typedef struct {
	int data[MAX];
	int count;
}SET;

void initSet(SET *S);
bool isinSet(SET *S, int elem);
void insertinSet(SET *S, int elem);
void deleteinSet(SET *S, int elem);
SET unionSet(SET *S1, SET *S2);
SET intersectSet(SET *S1, SET *S2);
void printSet(SET S);

#endif
