#include <stdio.h>
#include "Graphs.h"
#define N 5

void addEdge(int Graph[N][N], int col, int row) {
    Graph[col][row] = 1;
}

void printGraph(int Graph[N][N]) {
	int i, j;
    printf("Adjacency Matrix:\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", Graph[i][j]);
        }
        printf("\n");
    }
}

