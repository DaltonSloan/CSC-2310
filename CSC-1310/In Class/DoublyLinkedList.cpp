#include <iostream>

using namespace std;

class List {
public:
    struct Node {
        int value;
        Node* next;
        Node* previous;
    };

private:
    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    // Other member functions to manipulate the list can be added here

    void printForward() {
        Node* traverser = head;
        while (traverser != nullptr) {
            cout << traverser->value << " ";
            traverser = traverser->next;
        }
        cout << endl;
    }

    void printBackward() {
        Node* traverser = tail;
        while (traverser != nullptr) {
            cout << traverser->value << " ";
            traverser = traverser->previous;
        }
        cout << endl;
    }

    void listRemove(Node* curNode) {
        if (curNode == nullptr) return;

        Node* sucNode = curNode->next;
        Node* predNode = curNode->previous;

        if (sucNode != nullptr) {
            sucNode->previous = predNode;
        }

        if (predNode != nullptr) {
            predNode->next = sucNode;
        }

        if (curNode == head) {
            head = sucNode;
        }

        if (curNode == tail) {
            tail = predNode;
        }

        delete curNode;
    }

    void addNode(int value) {
        Node* node = new Node();
        node->value = value;
        node->next = nullptr;
        node->previous = tail;
        
        if (tail != nullptr) {
            tail->next = node;
        } else {
            head = node;
        }

        tail = node;
    }

    // Note: Implement the insertionSort function if needed
};

int main() {
    List myList;

    myList.addNode(1);
    myList.addNode(2);
    myList.addNode(3);
    myList.addNode(4);

    myList.printForward();
    myList.printBackward();

    return 0;
}
