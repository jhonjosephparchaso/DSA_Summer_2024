#ifndef Graphs
#define Graphs

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** adjLists;
    int numVertices;
} Graph;

#endif
