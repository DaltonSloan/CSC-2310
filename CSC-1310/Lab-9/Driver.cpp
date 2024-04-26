/*
    Title:    Lab9.cpp
    Author:   Dalton W. Sloan
    Date:     November 14, 2023
    Purpose:  Graph Representation.
*/

#include <iostream>
#include <fstream>
#include "GraphList.h"

using namespace std;

int main() {
    ifstream inputFile("graph.txt");

    if (!inputFile) {
        cerr << "Error: Unable to open 'graph.txt' for reading." << endl;
        return 1;
    }

    int numVertices;
    inputFile >> numVertices;

    // Create an adjacency list object
    graph adjacencyList(numVertices);

    int vertexA, vertexB;

    cout << "There are " << numVertices << " vertices in the graph." << endl << endl;

    while (inputFile >> vertexA >> vertexB) {
        cout << "Adding an edge from " << vertexA << " to " << vertexB << "." << endl;
        adjacencyList.addEdge(vertexA, vertexB);
    }

    inputFile.close();

    cout << "\nAdjacency List..." << endl;
    adjacencyList.printGraph();

    return 0;
}
