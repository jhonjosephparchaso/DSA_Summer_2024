#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
    int initialSize = 0;
    int i;
    Graph* graph = createGraph(initialSize);

    for (i = 0; i < 5; i++) {
        addVertex(graph);
    }

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 1);
    addEdge(graph, 4, 3);

    printGraph(graph);

    for (i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
	return 0;
}
