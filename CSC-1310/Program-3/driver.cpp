/*
	Title: Program 3
    Class: 1310-001
	Author: Dalton W. Sloan
	Date: 2 November 2023
	Purpose: Hashing passwords.
*/

#include <iostream>
#include <fstream>
#include "sha256.h" // Include the sha256 library for hashing
#include "hashTable.h" // Include the custom hash table implementation

using namespace std;

int main()
{
	ifstream file("testlist.txt");
	int menuChoice;
	int numUsers;
	string user, pwd, salt;
	string username, password;

	if(file.is_open()) {
	file >> numUsers;
	file.ignore(1, '\n');
	// Dynamically allocate a hash table based on the number of users
	hashTable* table = new hashTable(numUsers);

	while(getline(file, user))
	{
		getline(file, pwd);
		// Generate a random salt and add the new user to the hash table
		salt = table->generateSalt();
		table->addEntry(user, salt, sha256(pwd + salt));
	}


	do
	{
		cout << "\nWhat would you like to do?\n";
		cout << "1.  Login.\n";
		cout << "2.  Create account.\n";
		cout << "3.  Delete account.\n";
		cout << "4.  Exit.\n";
		cout << "CHOOSE 1-4:  ";
		cin >> menuChoice;

		while(menuChoice < 1 || menuChoice > 4)
		{
			cout << "That is not a valid choice.\n";
			cout << "CHOOSE 1-4:  ";
			cin >> menuChoice;
		}
		
		switch(menuChoice)
		{
			case 1:	cout << "enter your username:  ";
					cin >> username;
					cout << "enter your password:  ";
					cin >> password;
					
            if(table->validateLogin(username, sha256(password + table->getSalt(username))))// Check if the user's login credentials are correct
						cout << "login successful\n";
					else
						cout << "invalid credentials\n";
					
					break;
					
			case 2: cout << "enter your new username:  ";
					cin >> username;
					cout << "enter your new password:  ";
					cin >> password;
					
					// Generate a random salt and add the new user to the hash table
					salt = table->generateSalt();
					table->addEntry(username, salt, sha256(password + salt));
					
					break;
					
			case 3:	cout << "enter your username:  ";
					cin >> username;
					cout << "enter your password:  ";
					cin >> password;
					
					if(table->removeUser(username, sha256(password + table->getSalt(username))))// Remove the user from the hash table and check if they were removed successfully
						cout << "user removed successfully.\n";
					else
						cout << "invalid credentials, cannot remove user.\n";
					break;
					
			case 4:	cout << "goodbye" << endl;
					// Delete the hash table (memory deallocation)
					delete table;
					break;
					
		}
		
	} while(menuChoice != 4);
}

	return 0;
}