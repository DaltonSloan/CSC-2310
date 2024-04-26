/*
	Title: Lab 5
	Author: Dalton W. Sloan
	Date: 17 October 2023
	Purpose: Adding & Removing items from Stack.
*/
#ifndef DYNSTACK_H
#define DYNSTACK_H

#include <iostream>
using namespace std;

template<typename T>
class DynStack
{
    private:

    struct Node
    {
        T data;
        Node* next;

        // Constructor for the Node struct that initializes data and next pointer.
        Node(T dataVal)
        {
            data = dataVal;
            next = nullptr;
        }
    };

    Node* top;  // Pointer to the top of the stack.

    public:

    // Constructor for the DynStack class.
    DynStack()
    {
        top = nullptr;  // Initialize the top pointer to nullptr, indicating an empty stack.
    }

    // Push a new element onto the stack.
    void push(const T& data) 
    {
        Node* newNode = new Node(data);  // Create a new Node to hold the data.
        newNode->next = top;  // Set the new Node's next pointer to the current top.
        top = newNode;  // Update the top pointer to the new Node.
    }

    // Check if the stack is empty.
    bool isEmpty()
    {
        return top == nullptr;  // The stack is empty if the top pointer is nullptr.
    }

    // Pop the top element from the stack and return its value through the 'data' parameter.
    void pop(T& data)
    {
        if (!isEmpty())  // Check if the stack is not empty.
        {
            Node* temp = top;  // Create a temporary pointer to the top Node.
            data = temp->data;  // Retrieve the data from the top Node.
            top = top->next;  // Update the top pointer to the next Node.
            delete temp;  // Deallocate memory for the old top Node.
        }
        else
        {
            cout << "List is empty" << endl;  // Print a message if the stack is empty.
        }
    }
};

#endif
