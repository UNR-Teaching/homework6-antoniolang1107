
template <class LabelType>
Graph<LabelType>::Graph() {
    graphSize = 0;
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        for (int j = 0; j < MAX_SIZE - 1; j++) {
            adjMatrix[i][j] = -1;
        }
    }
}

template <class LabelType>
Graph<LabelType>::Graph(int numNodes) {
    graphSize = numNodes - 1;
    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            adjMatrix[i][j] = -1;
        }
    }
}

template <class LabelType>
int Graph<LabelType>::getNumVertices() {
    return graphSize;
}

template <class LabelType>
int Graph<LabelType>::getNumEdges() {
    int numEdges = 0;

    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            if (adjMatrix[i][j] != 0)
                numEdges++;
        }
    }
    return numEdges / 2;
}

template <class LabelType>
bool Graph<LabelType>::add(LabelType start, LabelType end, int edgeWeight) {
    int labelIndex1 = getLabelIndex(start), labelIndex2 = getLabelIndex(end);
    
    if (labelIndex1 == -1) {
        labelIndex1 = graphSize;
        graphSize++;
        labelArray[labelIndex1] = start;
    }
    if (labelIndex2 == -1) {
        labelIndex2 = graphSize;
        graphSize++;
        labelArray[labelIndex2] = end;
    }
    if (labelIndex1 == labelIndex2) {
        std::cout << "Cannot create edge between the same node" << std::endl;
        return false;
    }
    if (labelIndex1 > graphSize || labelIndex2 > graphSize) {
        std::cout << "Vertex is not in the bounds of the graph" << std::endl;
        return false;
    }
    else {
        adjMatrix[labelIndex1][labelIndex2] = edgeWeight;
        adjMatrix[labelIndex2][labelIndex1] = edgeWeight;
        return true;
    }
    return false;
}

template <class LabelType>
bool Graph<LabelType>::remove(LabelType start, LabelType end) {
    int startIndex = getLabelIndex(start), endIndex = getLabelIndex(end);
    adjMatrix[startIndex][endIndex] = -1;
    adjMatrix[endIndex][startIndex] = -1;
    // remove edge from graph
    // if vertex has no edges, remove from graph
}

template <class LabelType>
int Graph<LabelType>::getEdgeWeight(LabelType start, LabelType end) {
    return adjMatrix[getLabelIndex(start)][getLabelIndex(end)];
}

template<class LabelType>
int Graph<LabelType>::getLabelIndex(LabelType label) {
    for (int i = 0; i < graphSize; i++) {
        if (label == labelArray[i])
            return i;
    }
    return -1;
}

template <class LabelType>
void Graph<LabelType>::displayLabels() {
    for (int i = 0; i < graphSize; i++) {
        std::cout << i+1 << ". " << labelArray[i] <<std::endl;
    }
}

template <class LabelType>
void Graph<LabelType>::displayMatrix() {
    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            std::cout << adjMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

template <class LabelType>
void Graph<LabelType>::DepthFirstTraversal(LabelType start, visit) {
    std::stack<int> DFTstack;
    bool visited[graphSize];
}



template <class LabelType>
void Graph<LabelType>::BreadthFirstTraversal(LabelType start, visit) {
    std::queue<int> BFTqueue;
    bool visited[graphSize] = false;

    BFTqueue.enqueue(getLabelIndex(start));
    visited[getLabelIndex(start)] = true;

    LabelType current;
    while (!BFTqueue.empty()) {
        current = BFTqueue.peek();
        BFTqueue.dequeue();

        for (int i = 0; i < adjMatrix[getLabelIndex(current)].size() == 1; i++) {
            if (adjMatrix[getLabelIndex(current)][i] < 0 && (!visited[i])) {
                BFTqueue.enqueue(i);
                visited[i] = true;
            }
        }
    }

}