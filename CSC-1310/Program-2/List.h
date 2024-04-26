/*
	Title: Program 2
    Class: 1310-001
	Author: Dalton W. Sloan
	Date: 12 October 2023
	Purpose: Doubly-linked List.
*/

// Header guard to prevent duplicate inclusion.
#ifndef LIST_H
#define LIST_H

// Including the necessary library for I/O operations.
#include <iostream>
using namespace std;

// A template class that represents a doubly linked list of any type.
template<typename T>
class List 
{
    private:
    // An inner struct representing a node in the doubly linked list.
    struct listNode 
    {
        T value;                   // Holds the data for this node.
        listNode* next = nullptr;  // Points to the next node in the list.
        listNode* prev = nullptr;  // Points to the previous node in the list.
    };

    listNode* head; // Pointer to the beginning of the list.
    listNode* tail; // Pointer to the end of the list.

    // Prints the values starting from a given node until the end of the list.
    void print(listNode* node) 
    {
        // Loop until the end of the list is reached.
        while (node) 
        {
            cout << *(node->value) << " "; // Print the value at the current node.
            node = node->next;              // Move to the next node.
        }
        cout << endl; // Finish with a newline.
    }

    // Implements mergesort algorithm for the linked list, recursively.
    listNode* mergesort(listNode* start, listNode* end) 
    {
        // Base condition: if list is empty or only has one node, return.
        if (!start || start == end) 
        {
            return start;
        }

        listNode* mid = split(start, end);    // Split the list into two halves.
        start = mergesort(start, mid->prev);  // Sort the left half.
        mid = mergesort(mid, end);            // Sort the right half.

        return merge(start, mid);             // Merge and return the sorted halves.
    }

    // Merges two sorted linked lists together.
    listNode* merge(listNode* left, listNode* right) 
    {
        if (!left) return right;
        if (!right) return left;

        // Determine which node to keep at the front and merge accordingly.
        if (*(left->value) > *(right->value)) 
        {
            left->next = merge(left->next, right);
            left->next->prev = left;
            left->prev = nullptr;
            return left;
        } 
        else 
        {
            right->next = merge(left, right->next);
            right->next->prev = right;
            right->prev = nullptr;
            return right;
        }
    }

    // Splits the linked list into two halves.
    listNode* split(listNode* start, listNode* end) 
    {
        listNode* fast = start->next;
        listNode* slow = start;

        // Use two pointers to find the middle of the list.
        while (fast != end) 
        {
            fast = fast->next;
            if (fast != end) 
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        listNode* mid = slow->next; // Get the starting node of the second half.
        slow->next = nullptr;       // Break the list into two.
        return mid;                 // Return starting node of the second half.
    }

public:
    // Constructor initializes an empty list.
    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor deletes all nodes to free memory.
    ~List() 
    {
        while (head) 
        {
            listNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Prints the entire list.
    void print() 
    {
        print(head);
    }

    // Adds a new value to the end of the list.
    void append(const T& val) 
    {
        listNode* newNode = new listNode();
        newNode->value = val;

        if (!head) 
        {
            // If list is empty, new node is both head and tail.
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            // Otherwise, attach new node at the end.
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Sorts the list using the mergesort algorithm.
    void mergesort() 
    {
        head = mergesort(head, tail);
        tail = head;
        // Re-adjust the tail pointer after sorting.
        while (tail && tail->next)
        {
            tail = tail->next;
        }
    }
};

// End of header guard.
#endif
