#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <queue>
#include <stack>
#include "graphinterface.h"

template <class LabelType>
class Graph : public GraphInterface<LabelType> {
private:
    int graphSize;
    static const int MAX_SIZE = 10;
    int adjMatrix[MAX_SIZE][MAX_SIZE];
    LabelType labelArray[MAX_SIZE];

public:
    Graph();
    Graph(int numNodes);
    int getNumVertices();
    int getNumEdges();
    bool add(LabelType start, LabelType end, int edgeWeight);
    bool remove(LabelType start, LabelType end);
    int getEdgeWeight(LabelType start, LabelType end);
    int getLabelIndex(LabelType label);

    void displayLabels();
    void displayMatrix();
    
    void depthFirstTraversal(LabelType start, visit);
    void breadthFirstTraversal(LabelType start, visit);
};

#include "graph.cpp"
#endif