/*
	Title:    Lab7.cpp
	Author:   Dalton w. Sloan
	Date:     October 25, 2023
	Purpose:  Costume Inventory Data stored in Hash Table
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "Costume.h"
#include "HashEntry.h" 
using namespace std;

class HashTable
{
private:
    int tableSize;
    HashEntry** table; 

    int getHash(int key)
    {
        return key % tableSize;
    }

public:
    HashTable(int size)
    {
        tableSize = size;
        table = new HashEntry*[tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = nullptr;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < tableSize; i++)
        {
            delete table[i];
        }
        delete[] table;
    }

    void putValue(int key, Costume* value)
    {
        int index = getHash(key);
        int indexProbed = 0;

        
        while (indexProbed < tableSize)
        {
            
            if (table[index] == nullptr)
            {
                table[index] = new HashEntry(key, value);
                cout << "BUCKET: " << indexProbed << endl;
                return;
            }

            cout << "Collision at bucket: " << indexProbed << endl;
            index = (index + 1) % tableSize;
            ++indexProbed;
        }
        return;
    }

    void printHashTable()
    {
        cout << "----------" << endl;
        for (int i = 0; i < tableSize; i++)
    {
        if (table[i] != nullptr && table[i]->getKey() != -1)
        {
            cout << i << ": " << table[i]->getKey() << ", " << table[i]->getValue()->getCostumeName() << endl;
        }
    }
    cout << "----------" << endl;
    }
};

#endif
