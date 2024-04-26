/*
	Title: Program 3
    Class: 1310-001
	Author: Dalton W. Sloan
	Date: 2 November 2023
	Purpose: Hashing passwords.
*/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashTable.h"
#include "sha256.h"
using namespace std;

// Define the getEntry function to retrieve a user entry by username
hashTable::entry* hashTable::getEntry(string username) 
{
    int index = hash(username); // Calculate the bucket index for the given username
    entry* current = hashArray[index];

    while (current != nullptr) 
    {
        if (current->getUsername() == username)
        {
            return current; // Return the entry when the username matches
        }
        current = current->next;
    }

    return nullptr; // Return nullptr if the username is not found in the bucket
}

// Define the hashTable constructor
hashTable::hashTable(int size) 
{
    tableSize = size;
    hashArray = new entry*[tableSize];
    for (int i = 0; i < tableSize; i++) 
    {
        hashArray[i] = nullptr;
    }
    srand(time(0)); // Seed the random number generator for salt generation
}

// Define the hashTable destructor
hashTable::~hashTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        entry* current = hashArray[i];
        while (current != nullptr)
        {
            entry* head = current->next;
            delete current;
            current = head;
        }
    }
    delete[] hashArray; // Free the memory used by the hash table
}

// Hash function (do not modify)
int hashTable::hash(string key)
{
    int sum = 0;
    for(int i = 0; i < key.size(); i++)
        sum += key[i];
    
    return sum % tableSize;
}

// Generate a random salt for password hashing (do not modify)
string hashTable::generateSalt()
{
    string s = "";
    
    for(int i = 0; i < tableSize; i++)
        s = s + char('!' + (rand() % 93));
    return s;
}

// Retrieve the salt associated with a username
string hashTable::getSalt(string key) 
{
    entry* user = getEntry(key);
    if (user) {
        return user->getSalt();
    }
    return "";  
}

// Add a new user entry to the hash table
void hashTable::addEntry(string username, string salt, string hashedpwd) 
{
    int index = hash(username);
    entry* current = hashArray[index];
    entry* prev = nullptr;

    while (current) 
    {
        if (current->getUsername() == username) 
        {
            cout << "Username already exists: " << username << endl;
            return;
        }

        prev = current;
        current = current->next;
    }

    // Create a new user entry
    entry* newUser = new entry(username, salt, hashedpwd);

    if (prev == nullptr) 
    {
        // The bucket is empty, so add the new user as the first element
        hashArray[index] = newUser;
    }

    else 
    {
        // Add the new user to the end of the linked list
        prev->next = newUser;
    }

    cout << "Account created. Added user: " << username << " to server: " << index << endl;
}

// Validate user login credentials
bool hashTable::validateLogin(string username, string hashedpwd) 
{
    entry* user = getEntry(username);

    if (user && user->getHashedpwd() == hashedpwd) 
    {
        return user->getHashedpwd() == hashedpwd;
    }
    else 
    {
        return false;
    }
}

// Remove a user from the hash table
bool hashTable::removeUser(string username, string hashedpwd) 
{
    int index = hash(username);
    entry* current = hashArray[index];
    entry* prev = nullptr;

    while (current) 
    {
        if (current->getUsername() == username) 
        {
            // Check if the provided hashed password matches.
            if (current->getHashedpwd() == hashedpwd) 
            {
                // Remove the user.
                if (prev) 
                {
                    prev->next = current->next;
                }
                else 
                {
                    hashArray[index] = current->next;
                }

                delete current; // Free the memory of the removed user
                return true;  // User removed successfully.
            } 
            else 
            {
                return false;  // Password incorrect.
            }
        }

        prev = current;
        current = current->next;
    }
    
    // User not found in the table.
    return false;
}


