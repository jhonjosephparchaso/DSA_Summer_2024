#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int initialSize) {
	int i;
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = initialSize;
    graph->adjLists = malloc(initialSize * sizeof(Node*));
    for (i = 0; i < initialSize; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addVertex(Graph* graph) {
    graph->numVertices++;
    graph->adjLists = realloc(graph->adjLists, graph->numVertices * sizeof(Node*));
    graph->adjLists[graph->numVertices - 1] = NULL;
}

void addEdge(Graph* graph, int from, int to) {
    Node* newNode = createNode(to);
    newNode->next = graph->adjLists[from];
    graph->adjLists[from] = newNode;
}

void printGraph(Graph* graph) {
	int i;
    for (i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Vertex %c:", 'A' + i);
        while (temp) {
            printf(" -> %c", 'A' + temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

