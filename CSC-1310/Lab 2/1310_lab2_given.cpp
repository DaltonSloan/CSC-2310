/*
	Title: Lab 2
	Author: Dalton W. Sloan
	Date: 19 September 2023
	Purpose: Recursion.
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				
				cout << "\nTotal: " << sumOfNumbers(num) << "\n";
				
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				if (isMember(myArray, num, ARRAY_SIZE) == false)
				{
					cout << "\nNo! " << num << " is NOT in the array." << endl;
				}

				else if (isMember(myArray, num, ARRAY_SIZE) == true)
				{
				cout << "\nYes! " << num << " is in the array." << endl;
				}

				else
				cout << "\nSomething went wrong..." << endl;
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here
				cout << "\nReversed: ";
				stringReverser(userString, userString.length());

				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				if (isPalindrome(userStrModified)) 
				{
					cout << "\nThe string is a palindrome.\n";
				} 
				
				else 
				{
					cout << "\nThe string is not a palindrome.\n";
				}
				
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << "\nTotal: " << multiply(num1, num2) << "\n";
				
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!
#include <iostream>
#include <string>
using namespace std;

// Function to calculate the sum of all integers from 1 to num
int sumOfNumbers(int num)
{
    // Base case: if num is greater than 1, continue the recursion
    if (num > 1)
    {
        // Add num to the sum of the numbers less than num
        return num + sumOfNumbers(num - 1);
    }
    // Base case: if num is 1 or less, return 1
    else
    {
        return 1;
    }
}

// Function to check if a number is a member of an array
bool isMember(int* myArray, int num, int size)
{
    // Base case: if size is less than 0, return false (search completed)
    if (size < 0)
    {
        return false;
    }
    
    // Check if the current element at index 'size' is equal to num
    if (myArray[size] == num)
    {
        return true;
    }
    
    // Recursive call: Continue searching in the remaining array
    return isMember(myArray, num, size - 1);
}

// Function to reverse a string and print it
void stringReverser(string str, int i)
{
    // Base case: if i is greater than 0, continue the recursion
    if (i > 0)
    {
        // Print the current character at index i-1
        cout << str[i - 1];
        
        // Recursive call: Continue with the next character
        stringReverser(str, i - 1);
    }
}

// Function to check if a string is a palindrome
bool isPalindrome(string str)
{
    // Base case: If the string has length 1 or 0, it's a palindrome
    if (str.length() <= 1)
    {
        return true;
    }
    
    // Check if the first and last characters are the same
    if (str.front() != str.back())
    {
        return false;
    }
    
    // Create a substring without the first and last characters
    string sub = str.substr(1, str.length() - 2);
    
    // Recursive call: Check if the substring is a palindrome
    return isPalindrome(sub);
}

// Function to multiply two integers using addition/subtraction
int multiply(int x, int y)
{
    // Base case: if x is positive, continue the recursion
    if (x > 0)
    {
        return y + multiply(x - 1, y);
    }
    // Base case: if x is negative, continue the recursion using negative y
    else if (x < 0)
    {
        return -y + multiply(x + 1, y);
    }
    // Base case: if x is 0, the product is 0
    else
    {
        return 0;
    }
}
