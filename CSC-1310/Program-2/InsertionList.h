/*
	Title: Program 2
    Class: 1310-001
	Author: Dalton W. Sloan
	Date: 12 October 2023
	Purpose: Doubly-linked List.
*/
#ifndef INSERTIONLIST_H
#define INSERTIONLIST_H

#include <iostream>
using namespace std;

// Template class representing a doubly-linked list.
template<typename T>
class List 
{
    // Inner structure defining a node in the doubly-linked list.
    struct listNode 
    {
        T value;                      // Data stored in the node.
        listNode* next = nullptr;     // Pointer to the next node in the list.
        listNode* prev = nullptr;     // Pointer to the previous node in the list.
    };

private:
    listNode* head;  // Pointer to the start (head) of the list.
    listNode* tail;  // Pointer to the end (tail) of the list.

    // Function to swap the positions of two nodes in the list.
    // Assumes the first node comes before the second in the list.
    void swap(listNode* first, listNode* second)
    {
        if (!first || !second) return;

        listNode* firstPrev = first->prev;
        listNode* firstNext = first->next;
        listNode* secondPrev = second->prev;
        listNode* secondNext = second->next;

        // Case: nodes are adjacent.
        if (firstNext == second) 
        {
            // Rearrange pointers to swap positions.
            if (firstPrev) firstPrev->next = second;
            second->prev = firstPrev;
            first->next = secondNext;
            if (secondNext) secondNext->prev = first;
            second->next = first;
            first->prev = second;
        }
        // Case: nodes have at least one node between them.
        else 
        {
            // Rearrange pointers to swap positions.
            if (firstPrev) firstPrev->next = second;
            second->prev = firstPrev;
            first->next = secondNext;
            if (secondNext) secondNext->prev = first;
            second->next = firstNext;
            first->prev = secondPrev;
        }

        // Update head or tail if they were swapped.
        if (head == first) head = second;
        else if (head == second) head = first;
        if (tail == first) tail = second;
        else if (tail == second) tail = first;
    }

    // Function to sort the list using the selection sort.
    void selectionSort()
    {
        listNode* current = head;
        while (current)
        {
            listNode* min = current;
            listNode* itr = current->next;

            // Traverse the unsorted part of the list to find the minimum node.
            while (itr)
            {
                if (itr->value < min->value) min = itr;
                itr = itr->next;
            }

            // Swap the minimum node with the current node, if they're different.
            if (min != current) swap(current, min);
            current = current->next;
        }
    }

public:
    // Default constructor initializing an empty list.
    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor to free memory by deleting all nodes.
    ~List() 
    {
        while (head) 
        {
            listNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to print the entire list.
    void print() 
    {
        listNode* node = head;
        while (node) 
        {
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

    // Function to add an element to the end of the list.
    void append(const T& val) 
    {
        listNode* newNode = new listNode(val);
        if (!head) 
        {
            // If the list is empty, new node becomes both head and tail.
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            // Add the new node to the end and update tail.
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Public interface to sort the list.
    void sort() 
    {
        selectionSort();
    }
};

#endif
