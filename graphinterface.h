#ifndef GRAPH_INTERFACE
#define GRAPH_INTERFACE

template <class LabelType>
class GraphInterface {
public:
    virtual int getNumVertices() = 0;
    virtual int getNumEdges() = 0;
    virtual bool add(LabelType start, LabelType end, int edgeWeight) = 0;
    virtual bool remove(LabelType start, LabelType end) = 0;
    virtual int getEdgeWeight(LabelType start, LabelType end) = 0;
    virtual int getLabelIndex(LabelType label) = 0;
    
    void depthFirstTraversal(LabelType start, visit) = 0;
    void breadthFirstTraversal(LabelType start, visit) = 0;
};

#endif