/*
    Title:    Lab9.cpp
    Author:   Dalton W. Sloan
    Date:     November 14, 2023
    Purpose:  Graph Representation.
*/

#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include <iostream>
using namespace std;

class graph
{
    private:
    struct listNode
    {
        int value;
        listNode* next;
    };

    listNode** headArray;
    int numVertices;
    int numEdges;

    public:
    graph(int primeVert)
    {
        numVertices = primeVert;
        headArray = new listNode*[numVertices];

        for (int i = 0; i < numVertices; i++)
        {
            headArray[i] = nullptr;
        }
    }

    ~graph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            listNode* current = headArray[i];

            while (current != nullptr)
            {
                listNode* head = current->next;
                delete current;
                current = head;
            }
        }

        delete [] headArray;
    }

    void addEdge(int a, int b)
    {
        // Create a new listNode for vertex b
        listNode* newNode = new listNode;
        newNode->value = b;
        newNode->next = nullptr;

        listNode* current = headArray[a];
        listNode* prev = nullptr;

        // Find the correct position to insert the new edge while keeping the list sorted
        while (current != nullptr && current->value < b) {
            prev = current;
            current = current->next;
        }

        // If the new edge is the first in the list
        if (prev == nullptr) {
            newNode->next = headArray[a];
            headArray[a] = newNode;
        }
        else {
            newNode->next = current;
            prev->next = newNode;
        }
    }

    void printGraph() 
    {
        for (int i = 0; i < numVertices; i++) 
        {
            listNode* current = headArray[i];

            // Print the vertex
            cout << i << "--->";

            while (current != nullptr) 
            {
                cout << current->value;
                if (current->next != nullptr) 
                {
                    cout << "--->";
                }
                current = current->next;
            }

            cout << "--->NULL" << endl;
        }
    }
};



#endif