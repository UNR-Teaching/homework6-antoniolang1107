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
    readFile.close();


    graph.displayLabels();
    graph.displayMatrix();
    return 0;
}

void writeFile(std::string fileName) {
    std::ofstream writeFile;
    writeFile.open(fileName);
    // while (pathArray) {
    //  writeFile << path << std::endl;
    // }
    // writeFile << "best: " << path << std::endl;
}

// have possible paths output
//      select the best possible [use "min( , )"]