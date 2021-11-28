#include <iostream>
#include <fstream>
#include <algorithm>
#include "graph.h"

void writeFile(std::string fileName);


int main() {
    Graph<std::string> graph;

    std::ifstream readFile;
    readFile.open("distance.txt");
    std::string tempStart, tempEnd;
    int tempWeight;

    while (readFile >> tempStart >> tempEnd >> tempWeight) {
        graph.add(tempStart, tempEnd, tempWeight);
    }


    graph.displayLabels();
    graph.displayMatrix();
    return 0;
}


// have possible paths output
//      select the best possible [use "min( , )"]