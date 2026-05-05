#include <stdio.h>
#include <stdlib.h>
#include "Graphs.h"
#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
    int Graph[N][N] = {0};

    addEdge(Graph, 0, 1);
    addEdge(Graph, 0, 2);
    addEdge(Graph, 0, 3);
    addEdge(Graph, 1, 0);
    addEdge(Graph, 1, 2);
    addEdge(Graph, 1, 3);
    addEdge(Graph, 1, 4);
    addEdge(Graph, 2, 0);
    addEdge(Graph, 2, 1);
    addEdge(Graph, 2, 3);
    addEdge(Graph, 3, 0);
    addEdge(Graph, 3, 1);
    addEdge(Graph, 3, 2);
    addEdge(Graph, 3, 4);
    addEdge(Graph, 4, 1);
    addEdge(Graph, 4, 3);

    printGraph(Graph);

	return 0;
}
