/*
	Title: Lab 4
	Author: Dalton W. Sloan
	Date: 03 October 2023
	Purpose: String Linked List.
*/
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

using namespace std;

class List 
{
    struct ListNode 
    {
        string data;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        ListNode(string data)
        {
            data = data;
            next = nullptr;
            prev = nullptr;
        }
    };

private:
    ListNode* head;
    ListNode* tail;

    void print(ListNode* node) 
    {
        while (node) 
        {
            cout << node->data << endl;
            node = node->next;
        }
        cout << endl;
    }

public:
    List() : head(nullptr), tail(nullptr) {}

    ~List() 
    {
        while (head) 
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void displayList() 
    {
        print(head);
    }

    void appendNode(const string& val) 
    {
        ListNode* newNode = new ListNode(val);
        if (!head) 
        {
            head = tail = newNode;
        }

        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertNode(const string& val) 
    {
        ListNode* newNode = new ListNode(val);
        if (!head || head->data >= val) 
        {
            newNode->next = head;
            if (head)
            { 
                head->prev = newNode;
                head = newNode;
            }

            if (!tail)
            {
                tail = head;
                return;
            }
        }

        ListNode* current = head;
        while (current->next && current->next->data < val) 
        {
            current = current->next;
        }

        newNode->next = current->next;
        if (current->next) 
        {
            current->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;
        }
        if (!newNode->next)
        {
            tail = newNode;
        }
        
    }

    bool deleteNode(const string& val) {
        ListNode* curNode = head;

        while(curNode && curNode->data != val) 
        {
            curNode = curNode->next;
        }

        if(curNode == nullptr)
        {
            return false;
        }

        if(curNode->prev) 
        {
            curNode->prev->next = curNode->next;
        } 
        
        else 
        {
            head = curNode->next;
        }

        if(curNode->next) 
        {
            curNode->next->prev = curNode->prev;
        }

        else 
        {
            tail = curNode->prev;
        }

        delete curNode;
        return true;
    }
};

#endif //LIST_H
