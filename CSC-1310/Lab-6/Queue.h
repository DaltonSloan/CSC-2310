/*
	Title: Lab 6
	Author: Dalton W. Sloan
	Date: 24 October 2023
	Purpose: Queue.
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue
{
    private:

    struct QueueNode
    {
        string riderName;
        QueueNode* next;

        // Constructor for QueueNode, initializes riderName and next pointer
        QueueNode(string name)
        {
            riderName = name;
            next = nullptr;
        }
    };

    int numNodes;       // Counter to keep track of the number of nodes in the queue
    QueueNode* head;    // Pointer to the first node in the queue
    QueueNode* tail;    // Pointer to the last node in the queue

    public:

    Queue()
    {
        head = nullptr;  // Initialize the head pointer to nullptr (empty queue)
        tail = nullptr;  // Initialize the tail pointer to nullptr (empty queue)
    }

    ~Queue()
    {
        while (head)
        {
            // Print a message for each rider being removed during destruction
            cout << "Oh shoot, I am sorry, our park is closed so " << head->riderName << " will not get to ride today." << endl;
            
            QueueNode* temp = head;  // Create a temporary pointer to the current head node
            head = head->next;      // Move head to the next node
            delete temp;            // Delete the current node
        }
    }

    void enQueue(string name)
    {
        QueueNode* temp = new QueueNode(name);  // Create a new node with the given rider's name

        if (!tail)  // If the queue is empty (tail is nullptr)
        {
            head = temp;  // Set both head and tail to the new node
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;  // Link the current tail to the new node
            tail = temp;        // Update the tail pointer to the new node
        }
    }

    string deQueue()
    {
        QueueNode* temp = head;  // Create a temporary pointer to the current head node

        head = head->next;  // Move the head to the next node

        if (!head)  // If the queue is now empty
        {
            tail = nullptr;  // Update the tail pointer to nullptr
        }

        string riderName = temp->riderName;  // Store the rider's name before removing the node
        delete temp;  // Delete the removed node

        return riderName;  // Return the rider's name
    }

    bool isEmpty()
    {
        if (!head)  // If head is nullptr, the queue is empty
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif
