#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

void printValues(Node* n)
{
    while(n!=NULL)
    {
        cout << n->value << endl;
        n = n->next;
    }
}

void insertAtFront(Node** head, int newValue)
{
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int newValue)
{
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node* last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
}

void insertAfter(Node* previous, int newValue)
{
    if (previous == NULL)
    {
        cout << "Previous can't be NULL" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = previous->next;
    previous->next = newNode;

}

int main()
{
    Node* head = new Node();
    Node* nodePtr = new Node();
    Node* tail = new Node();

    head->value = 1;
    head->next = nodePtr;
    nodePtr->value = 2;
    nodePtr->next = tail;
    tail->value = 3;
    tail->next = NULL;

    insertAtFront(&head, -1);

    insertAtEnd(&head, 4);

    insertAfter(head, 0);

    printValues(head);

    delete head;
    delete nodePtr;
    delete tail;

    return 0;
}