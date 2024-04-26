/*
	Title: Lab 4
	Author: Dalton W. Sloan
	Date: 03 October 2023
	Purpose: String Linked List.
*/
#ifndef LIST_H  // Prevents the List class definition from being included more than once
#define LIST_H

#include <iostream>  // Include for std::cout and std::endl
using namespace std;  // Uses the standard namespace

class List  // Class definition for a List
{
    // Definition of a ListNode struct, which will be the elements in the List
    struct ListNode
    {
        string data;  // Holds the data of the node, a string
        ListNode* next;  // Pointer to the next node in the list
    };

    private:
    // Private member variables
    ListNode* head;  // Pointer to the first node in the list
    ListNode* tail;  // Pointer to the last node in the list

    public:
    // Default constructor
    List()
    {
        // Initializes head and tail to nullptr indicating an empty list
        head = nullptr;
        tail = nullptr;
    }

    // Destructor
    ~List()
    {
        // Deletes all nodes in the list
        while (head)
        {
            ListNode* temp = head;  // Temporary pointer to the current node
            head = head->next;  // Move the head pointer to the next node
            delete temp;  // Delete the current node
        }
    }

    // Function to display all nodes in the list
    void displayList() const
    {
        ListNode* temp = head;  // Start at the beginning of the list
        while (temp)  // Iterate through the list
        {
            // Print the data of the current node
            cout << temp->data << endl;
            temp = temp->next;  // Move to the next node
        }
        cout << endl;  // Print a newline at the end for formatting
    }

    // Function to delete a node with a specific word
    void deleteNode(const string& word) 
    {
        if (!head)  // Check if the list is empty
        {
            // If empty, print a message and return
            cout << "No items in list to delete" << endl;
            return;
        }

        ListNode* curNode = head;  // Start at the beginning of the list
        ListNode* prevNode = nullptr;  // Keep track of the previous node

        // If the first node contains the word, delete it
        if (curNode->data == word)
        {
            head = curNode->next;  // Move the head pointer to the next node
            delete curNode;  // Delete the current node
            return;
        }

        // Iterate through the list looking for the word
        while (curNode && curNode->data != word) 
        {
            prevNode = curNode;  // Update the previous node
            curNode = curNode->next;  // Move to the next node
        }

        // If the word was not found in the list, print a message and return
        if (!curNode) 
        {
            cout << "Word not found in the list" << endl;
            return;
        }

        // Unlink the node containing the word
        prevNode->next = curNode->next;

        delete curNode;  // Delete the node
    }

    // Function to append a node with a specific word to the end of the list
    void appendNode(const string& word)
    {
        ListNode* newNode = new ListNode();  // Create a new node
        newNode->data = word;  // Set its data

        if (!head)  // If the list is empty
        {
            // The new node is now both the head and tail of the list
            head = newNode;
            tail = newNode;
        }
        else  // If the list is not empty
        {
            tail->next = newNode;  // Append the new node to the end of the list
            tail = newNode;  // Update the tail pointer
        }
    }

    // Function to insert a node with a specific word in order into the list
    void insertNode(const string& word) 
    {
        ListNode* newNode = new ListNode();  // Create a new node
        newNode->data = word;  // Set its data
        newNode->next = nullptr;  // Its next node is initially nullptr

        if (!head)  // If the list is empty
        {
            // The new node is now both the head and tail of the list
            head = newNode;
            tail = newNode;
            return;
        }

        // If the new node should be inserted at the beginning of the list
        if (head->data >= word) 
        {
            newNode->next = head;  // The new node's next will be the current head
            head = newNode;  // Update the head pointer
            return;
        }

        ListNode* curNode = head;  // Start at the beginning of the list
        // Iterate through the list to find the correct position to insert the new node
        while (curNode->next && curNode->next->data < word) 
        {
            curNode = curNode->next;  // Move to the next node
        }

        // Insert the new node
        newNode->next = curNode->next;
        curNode->next = newNode;

        // If the new node was inserted at the end of the list, update the tail pointer
        if (newNode->next == nullptr) 
        {
            tail = newNode;
        }
    }
};

#endif //LIST_H  // End of the conditional inclusion directive
