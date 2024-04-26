#ifndef ARRAYMINHEAP_H
#define ARRAYMINHEAP_H

#include "Creature.h"

class ArrayMinHeap {
private:
    Creature *heapArray;
    int capacity;
    int heap_size;

    // Private helper functions
    void swap(Creature *a, Creature *b);
    int parent(int i);
    int left(int i);
    int right(int i);
    void minHeapify(int i);

public:
    // Public member functions
    ArrayMinHeap(int capacity);
    ~ArrayMinHeap();

    Creature peek();
    bool remove(Creature &removedCreature);
    void insert(Creature newCreature);
    void resizeArray();
    bool isEmpty();
    int getNumberOfNodes();
    int getHeight();
    void display();
    void saveToFile();
};

#endif // ARRAYMINHEAP_H