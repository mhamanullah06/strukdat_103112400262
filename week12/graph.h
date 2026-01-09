#ifndef GRAPH_H  
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct Elmnode* adrNode;
typedef struct ElmEdge* adrEdge;

struct Node {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode createNode(infoGraph x);
void insertNode(Graph &G, infoGraph X);
void createNode(Graph &G, infoGraph srart, infoGraph end);
void printGraph(Graph G);

#endif