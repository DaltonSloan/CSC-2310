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

    printValues(head);

    delete head;
    delete nodePtr;
    delete tail;

    return 0;
}
