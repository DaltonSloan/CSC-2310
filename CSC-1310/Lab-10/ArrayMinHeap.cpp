#include "ArrayMinHeap.h"
#include <iostream>
#include <cmath>
#include <fstream>

// Constructor
ArrayMinHeap::ArrayMinHeap(int capacity) : capacity(capacity), heap_size(0) {
    heapArray = new Creature[capacity + 1]; // 1-based indexing
}

// Destructor
ArrayMinHeap::~ArrayMinHeap() {
    delete[] heapArray;
}

// Private helper function to swap two elements in the heapArray
void ArrayMinHeap::swap(Creature *a, Creature *b) {
    Creature temp = *a;
    *a = *b;
    *b = temp;
}

// Private helper function to get the index of the parent of a node
int ArrayMinHeap::parent(int i) {
    return (i - 1)/2;
}

// Private helper function to get the index of the left child of a node
int ArrayMinHeap::left(int i) {
    return 2 * i + 1;
}

// Private helper function to get the index of the right child of a node
int ArrayMinHeap::right(int i) {
    return 2 * i + 2;
}

// Private helper function to maintain the min-heap property
void ArrayMinHeap::minHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l <= heap_size && heapArray[l].getName() < heapArray[i].getName())
        smallest = l;

    if (r <= heap_size && heapArray[r].getName() < heapArray[smallest].getName())
        smallest = r;

    if (smallest != i) {
        swap(&heapArray[i], &heapArray[smallest]);
        minHeapify(smallest);
    }
}

// Public function to get the root creature (minimum element)
Creature ArrayMinHeap::peek() {
    if (heap_size > 0)
        return heapArray[1];
    else {
        std::cerr << "Heap is empty. Cannot peek.\n";
        return Creature(); // Assuming Creature() constructs an empty creature
    }
}

// Public function to remove the root creature (minimum element)
bool ArrayMinHeap::remove(Creature &removedCreature) {
    if (heap_size > 0) {
        removedCreature = heapArray[0];
        heapArray[0] = heapArray[--heap_size];
        minHeapify(0);
        return true;
    } else {
        return false;
    }
}

// Public function to insert a new creature into the heap
void ArrayMinHeap::insert(Creature newCreature) {
    if (heap_size == capacity) {
        resizeArray();
    }

    
    int i = heap_size++;
    heapArray[i] = newCreature;
    

    while (i >= 1 && heapArray[i].getName() < heapArray[parent(i)].getName()) {
        swap(&heapArray[i], &heapArray[parent(i)]);
        i = parent(i);
    }
}

// Public function to resize the heapArray to twice its current size
void ArrayMinHeap::resizeArray() {
    capacity *= 2;
    Creature *newArray = new Creature[capacity + 1];

    for (int i = 1; i <= heap_size; i++) {
        newArray[i] = heapArray[i];
    }

    delete[] heapArray;
    heapArray = newArray;
}

// Public function to check if the heap is empty
bool ArrayMinHeap::isEmpty() {
    return (heap_size == 0);
}

// Public function to get the number of nodes in the heap
int ArrayMinHeap::getNumberOfNodes() {
    return heap_size;
}

// Public function to get the height of the heap
int ArrayMinHeap::getHeight() {
    return static_cast<int>(std::ceil(std::log2(heap_size + 1)));
}

// Public function to display the names of creatures in the heap
void ArrayMinHeap::display() {
    for (int i = 0; i < heap_size; i++) {
        std::cout << heapArray[i].getName() << std::endl;
    }
}

// Public function to save the names of creatures in the heap to a file
void ArrayMinHeap::saveToFile() {
    std::ofstream outFile("savedCreatures.txt");

    for (int i = 1; i <= heap_size; i++) {
        outFile << heapArray[i].getName() << std::endl;
    }

    outFile.close();
}

