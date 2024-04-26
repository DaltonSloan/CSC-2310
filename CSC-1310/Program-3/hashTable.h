/*
	Title: Program 3
    Class: 1310-001
	Author: Dalton W. Sloan
	Date: 2 November 2023
	Purpose: Hashing passwords.
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "sha256.h"
using namespace std;

class hashTable
{
	private:
		class entry;

		//add the attributes you need for the class---------------------------------------------------------
		int tableSize;    // Size of the hash table
        entry** hashArray; // Array of pointers to store user data

		// Private helper functions
        int hash(string);       // Hashing function to map keys to table slots
        entry* getEntry(string); // Retrieve an entry using a username
	public:
		//add all the functions you need--------------------------------------------------------------------
        hashTable(int);            // Constructor to create a hash table with a specified size
        ~hashTable();              // Destructor to clean up memory
        string generateSalt();     // Generate a random salt for password hashing
        string getSalt(string);    // Get the salt associated with a username
        void addEntry(string, string, string); // Add a new user to the hash table
        bool validateLogin(string, string);    // Validate user login credentials
        bool removeUser(string, string);       // Remove a user from the hash table
};

class hashTable::entry
{
	private:
		string username;    // User's username
        string salt;        // Salt used for password hashing
        string hashedpwd;   // Hashed password

	public:
	
	//add the constructor and getter functions-----------------------------------------------------------
	entry* next;        // Pointer to the next entry in case of collisions

    // Constructor for the entry class
    entry(string u, string s, string h)
    {
		username = u;
		salt = s;
		hashedpwd = h;
		next = nullptr;
    }

    // Getter functions to access private attributes
	string getUsername()
	{
		return username;
	}

	string getSalt()
	{
		return salt;
	}

	string getHashedpwd()
	{
		return hashedpwd;
	}

};

#endif